#include <iostream>
#include <fstream>
#include <strstream>
#include "Parser.h"

std::string getFileContents(std::ifstream&);
int main() {
    try{
        std::cout << "MTParser 1.0\n";
        std::string fileName{"/Users/eric79/Downloads/cop2_orig_edi/84_013.edi"};
        std::ifstream file;
        file.open(fileName);
        if(!file.is_open())throw std::runtime_error("Cannot open file "+ fileName+"\n");
        std::string fileContents = getFileContents(file);
        file.close();

        MTparser::Parser p;
        p.parse(fileContents);
        MTparser::Data_set ds;
        MTparser::Option_list ol;
        MTparser::Data_block edi_contents = p.get();
        for (auto it=edi_contents.begin();it!=edi_contents.end();it++){
            std::cout << it->first << ":\n\toption list:\n";
            ol = p.get_option_list_for(it->first);
            for (auto oit=ol.begin();oit!=ol.end();oit++){
                std::cout << "\t\t" << oit->first << "==" << oit->second << std::endl;
            }
            std::cout << "\tdataset:\n";

            ds = p.get_data_set_for(it->first);
            for (auto d : MTparser::dataset2double(ds, p.get_option_list_for(">HEAD")["EMPTY"])){
                std::cout << "\t\t" << d << std::endl;
            }
        }
        return 0;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << "\n";
        return -1;
    }
    catch (...){
        std::cerr << "unhandled error.\n";
        return 1;
    }
}

std::string getFileContents(std::ifstream& input){
    std::ostrstream sstr;
    sstr << input.rdbuf();
    return sstr.str();
}
