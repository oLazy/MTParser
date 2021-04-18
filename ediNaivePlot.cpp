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
        std::ifstream is;
        is.open(fileName);
        if(!is.is_open())throw std::runtime_error("Cannot open file " + fileName+ "\n");
        std::string fileContents = getFileContents(is);
        is.close();
        MTparser::Parser p;
        p.parse(fileContents);
        auto skip_string = p.get_option_list_for(">HEAD")["EMPTY"];

        Gnuplot gp;
        auto freq = MTparser::dataset2double(p.get_data_set_for(">FREQ"), skip_string);
        auto zxyr = MTparser::dataset2double(p.get_data_set_for(">ZXYR"), skip_string);
        auto zyxr = MTparser::dataset2double(p.get_data_set_for(">ZYXR"), skip_string);
        auto zyxs = MTparser::dataset2double(p.get_data_set_for(">ZYXR"), skip_string);

        gp << "plot '-' with errorbars pt 6 rgb '#F0BC42' title 're(z_{xy})'\n";
        gp.send1d(std::make_tuple(freq,zxyr,std::sqrt()));
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
