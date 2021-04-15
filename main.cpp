#include <iostream>
#include <fstream>
#include <strstream>
#include "Tokenizer.h"

std::string getFileContents(std::ifstream&);
int main() {
   try{
       std::cout << "MTParser 1.0\n";
       std::string fileName{"/home/eric/Projects/MTParser/pc5009c.edi"};
       std::ifstream file;
       file.open(fileName);
       if(!file.is_open())throw std::runtime_error("Cannot open file "+ fileName+"\n");
       std::string fileContents = getFileContents(file);
       file.close();
//       std::cout << fileContents << "\n\n";
        MTparser::Tokenizer tokenizer;

        MTparser::vector<MTparser::Token> tokens = tokenizer.parse(fileContents);
        for (auto t : tokens){
            std::cout << t.text << "\t" << MTparser::sTokenTypeStrings[t.type] << "\t" << t.lineNumber << std::endl;
        }
   }
   catch (...)
   {
       std::cerr << "unhandled error.\n";
       return 1;
   }
}

std::string getFileContents(std::ifstream& input){
    std::ostrstream sstr;
    sstr << input.rdbuf();
    return sstr.str();
}