//
// Created by eric on 16/04/2021.
//

#ifndef MTPARSER_PARSER_H
#define MTPARSER_PARSER_H
#include "Tokenizer.h"
#include <map>
#include <tuple>

namespace MTparser {
    using namespace std;
    typedef vector<string> Data_set;
    typedef map<string ,string > Option_list;
    typedef map<string,tuple<Option_list , Data_set>> Data_block;

    vector<double> dataset2double(Data_set const& , string const skip = "");

    class Parser {
    public:
        void parse(string const&);
        Option_list get_option_list_for(string const& key) const;
        Data_set get_data_set_for(string const& key) const;
        Data_block get() const;
    private:
        void parse(vector<Token> &);
        Tokenizer tokenizer;
        void data_block(vector<Token>::iterator &it);
        Option_list option_list(vector<Token>::iterator &it);
        Data_set data_set(vector<Token>::iterator &it);
        string spare_free_text; // to not waste info section
        Data_block fileContents;
    };
}

#endif //MTPARSER_PARSER_H
