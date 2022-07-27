//
// Created by ZhugeKongan on 2022/7/22.
//

#include "Tokenizer.h"

std::vector<Token> tokenizer(const std::string &strs){
    int strlen=strs.size();
    std::vector<Token> tokens;
    int t=0;
    while(t<strlen&&strs[t]==' ')++t;

    if(t<strlen&&strs[t]==';')return tokens;

    while(t<strlen){

        while(t<strlen&&strs[t]==' ')++t;

        if(t>=strlen)break;
        char c=strs[t];

        if(c=='('){
            tokens.push_back(Token(PAREN,"("));
            ++t;
            continue;
        }

        if(c==')'){
            tokens.push_back(Token(PAREN,")"));
            ++t;
            continue;
        }

        if(c>='0'&&c<='9'){
            std::string value="";
            while(t<strlen&&strs[t]>='0'&&strs[t]<='9'){
                value+=strs[t];
                ++t;
            }
            tokens.push_back(Token(NUMBER,value));
            continue;

        }

        if(c>='a'&&c<='z'){
            std::string value="";
            while(t<strlen&&strs[t]!=' '){
                value+=strs[t];
                ++t;

            }
            tokens.push_back(Token(NAME,value));
            continue;
        }

        if(c=='"'){
            std::string value="";
            ++t;
            while(t<strlen&&strs[t]!='"'){
                value+=strs[t];
                ++t;

            }
            ++t;
            tokens.push_back(Token(STRING,value));
            continue;
        }

        throw "tokenizer error: dont match the token !";



    }
    return tokens;


}