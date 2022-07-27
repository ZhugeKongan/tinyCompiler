//
// Created by ZhugeKongan on 2022/7/24.
//

#include "Parser.h"

Parser& Parser::OnGetParser() {
    static Parser mParser;
    return mParser;

}
ASTobj* Parser::parseTokens(const std::vector<Token> &tokens){

    if(tokens.size()==0)return nullptr;
    try {
        int t=0;
        return Parser::OnGetParser().parseExpr(tokens,t);
    }
    catch(char const* strs){
        std::cout<<"parser error:"<<strs<<std::endl;
    }

    return nullptr;

}

ASTobj* Parser::parseExpr(const std::vector<Token> &tokens,int &t){

    if(t>=tokens.size())return nullptr;

    auto astnode=new ASTobj();
    switch (tokens[t]._type) {
        case Tokentype::PAREN:
            if(tokens[t]._value[0]=='('){
                ++t;
                return Parser::OnGetParser().parseExpr(tokens,t);

            }
            else if(tokens[t]._value[0]==')'){
                return nullptr;
            }
            break;
        case Tokentype::NAME:
            astnode->_type=ASTtype::CALLEXPRESSION;
            astnode->_name=tokens[t]._value;
            ++t;
            astnode->_param.first=Parser::OnGetParser().parseExpr(tokens,t);
            astnode->_param.second=Parser::OnGetParser().parseExpr(tokens,t);
            ++t;
            break;
        case Tokentype::NUMBER:
            astnode->_type=ASTtype::NUMBERLITERAL;
            astnode->_value=tokens[t]._value;
            ++t;
            break;
        case Tokentype::STRING:
            astnode->_type=ASTtype::STRINGLITERAL;
            astnode->_value=tokens[t]._value;
            ++t;
            break;
        default:
            throw "PARSER ERROR: not support the Tokentype";
            break;

    }



    return astnode;

}