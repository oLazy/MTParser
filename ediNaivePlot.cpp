//
// Created by Standard on 17/04/2021.
//
#include "MTTensor.h"
#include "gnuplot-iostream.h"
#include <iostream>
#include <boost/tuple/tuple.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/program_options.hpp>
#include "Parser.h"
#include <fstream>
#include <strstream>
#include <algorithm>
#include <cmath>
#include <boost/filesystem.hpp>


boost::program_options::options_description parse_cmdline(int argc, char *argv[], boost::program_options::variables_map& p_vm);
std::string getFileContents(std::ifstream&);

int main(int argc, char* argv[]){
    try {
        // program configuration
        boost::program_options::variables_map vm;
        auto desc = parse_cmdline(argc, argv, vm);
        if (vm.count("help")) {
            std::cout << desc << std::endl;
            return 0;
        }
        auto fileName = vm["in-path"].as<std::string>();
        auto pathObject = boost::filesystem::path(fileName);
        std::cout << "handling file: " << pathObject.filename().string() << "\n";
        std::ifstream is;
        is.open(fileName);
        if(!is.is_open())throw std::runtime_error("Cannot open file " + fileName+ "\n");
        std::string fileContents = getFileContents(is);
        is.close();
        MTparser::Parser p;
        p.parse(fileContents);
        auto skip_string = p.get_option_list_for(">HEAD")["EMPTY"];
        std::cout << "skip_string: " << skip_string << "\n";
        auto edi_contents = p.get();
        MTparser::Option_list ol;
        MTparser::Data_set ds;
//        for (auto it=edi_contents.begin();it!=edi_contents.end();it++) {
//            std::cout << it->first << ":\n\toption list:\n";
//            ol = p.get_option_list_for(it->first);
//            for (auto oit = ol.begin(); oit != ol.end(); oit++) {
//                std::cout << "\t\t" << oit->first << "==" << oit->second << std::endl;
//            }
//        }

        Gnuplot gp;
        auto freq = MTparser::dataset2double(p.get_data_set_for(">FREQ"), skip_string);
        // OFF-DIAG
        auto zxyr = MTparser::dataset2double(p.get_data_set_for(">ZXYR"), skip_string);
        auto zyxr = MTparser::dataset2double(p.get_data_set_for(">ZYXR"), skip_string);
        auto zxyi = MTparser::dataset2double(p.get_data_set_for(">ZXYI"), skip_string);
        auto zyxi = MTparser::dataset2double(p.get_data_set_for(">ZYXI"), skip_string);
        // MAIN-DIAG
        auto zxxr = MTparser::dataset2double(p.get_data_set_for(">ZXXR"), skip_string);
        auto zyyr = MTparser::dataset2double(p.get_data_set_for(">ZYYR"), skip_string);
        auto zxxi = MTparser::dataset2double(p.get_data_set_for(">ZXXI"), skip_string);
        auto zyyi = MTparser::dataset2double(p.get_data_set_for(">ZYYI"), skip_string);

        auto zxyv = MTparser::dataset2double(p.get_data_set_for(">ZXY.VAR"), skip_string);
        auto zyxv = MTparser::dataset2double(p.get_data_set_for(">ZYX.VAR"), skip_string);
        auto zxxv = MTparser::dataset2double(p.get_data_set_for(">ZXX.VAR"), skip_string);
        auto zyyv = MTparser::dataset2double(p.get_data_set_for(">ZYY.VAR"), skip_string);

        std::vector<double> zxys,zyxs,zxxs,zyys;
        for (auto v : zxyv) zxys.push_back(std::sqrt(v));
        for (auto v : zyxv) zyxs.push_back(std::sqrt(v));
        for (auto v : zxxv) zxxs.push_back(std::sqrt(v));
        for (auto v : zyyv) zyys.push_back(std::sqrt(v));


        auto title = pathObject.filename().string();
        auto pos = title.find('_');
        title.insert(pos,"\\");
        gp << "set title '" + title +"'\n";
        gp << "set multiplot layout 2,2\n";
        gp << "set logscale x\n";
//        gp << "set logscale y\n";
        gp << "set xlabel 'Frequency (Hz)'\n";
        gp << "set ylabel 'Impedance (Ohm)'\n";

        // XX
        gp << "set title '" + title +"-XX'\n";
        gp << "plot "
              << "'-' with errorbars pt 3 lc rgb '#F0BC42' title 're(z_{xx})', "
              << "'-' with errorbars pt 4 lc rgb '#8E1F2F' title 'im(z_{xx})'"
              << "\n";
        gp.send1d(std::make_tuple( freq, zxxr, zxxs));
        gp.send1d(std::make_tuple( freq, zxxi, zxxs));
        // XY
        gp << "set title '" + title +"-XY'\n";
        gp << "plot "
           << "'-' with errorbars pt 3 lc rgb '#F0BC42' title 're(z_{xy})', "
           << "'-' with errorbars pt 4 lc rgb '#8E1F2F' title 'im(z_{xy})'"
           << "\n";
        gp.send1d(std::make_tuple( freq, zxyr, zxys));
        gp.send1d(std::make_tuple( freq, zxyi, zxys));
        // YX
        gp << "set title '" + title +"-YX'\n";
        gp << "plot "
           << "'-' with errorbars pt 3 lc rgb '#F0BC42' title 're(z_{yx})', "
           << "'-' with errorbars pt 4 lc rgb '#8E1F2F' title 'im(z_{yx})'"
           << "\n";
        gp.send1d(std::make_tuple( freq, zyxr, zyxs));
        gp.send1d(std::make_tuple( freq, zyxi, zyxs));
        // YY
        gp << "set title '" + title +"-YY'\n";
        gp << "plot "
           << "'-' with errorbars pt 3 lc rgb '#F0BC42' title 're(z_{yy})', "
           << "'-' with errorbars pt 4 lc rgb '#8E1F2F' title 'im(z_{yy})'"
           << "\n";
        gp.send1d(std::make_tuple( freq, zyyr, zyys));
        gp.send1d(std::make_tuple( freq, zyyi, zyys));

        return 0;
    }
    catch (std::exception &e){
        std::cout << "Error: " << e.what() <<"\n";
        return 1;
    }
    catch(...){
        std::cerr << "Unhandled exception. Quit.\n";
        return 2;
    }
    return 0;
}






boost::program_options::options_description parse_cmdline(int argc, char *argv[], boost::program_options::variables_map& p_vm){
    namespace po = boost::program_options;
    po::options_description generic("Generic options");
    generic.add_options()
            ("help,h", "display this message and exit.")
            ("in-path,i", po::value<std::string>(), "PATH to the input .edi file.")
            ("out-path, o", po::value<std::string>()->default_value("./"), "Where I save plots.");
    po::store(po::parse_command_line(argc, argv, generic), p_vm);
    po::notify(p_vm);
    return generic;
}

std::string getFileContents(std::ifstream& input){
    std::ostrstream sstr;
    sstr << input.rdbuf();
    return sstr.str();
}
