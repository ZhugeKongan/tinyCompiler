//
// Created by ZhugeKongan on 2022/7/25.
//


#ifndef TINYCOMPILER_AST_H
#define TINYCOMPILER_AST_H

#include "Token.h"


class ASTNode{
public:
    ASTtype _type;
    std::string _value;

};


class ASTobj{
public:
    ASTtype _type;
    std::string _name;
    std::string _value;
    std::pair<ASTobj*,ASTobj*> _param;
    std::vector<ASTobj*> _body;
//    std::vector<ASTNode*> _body;

//public:
//    ASTobj(){
////        _param= nullptr;
//        _type=ASTtype::STRINGLITERAL;
//        std::pair<ASTobj*,ASTobj*> _param;
//        _param.first=nullptr;
//        _param.second=nullptr;
//        _body=nullptr;
//    }
};

class TASTobj{
public:
    TASTtype _type;
    std::string _name;
    std::string _value;
    TASTobj* _expression;
    TASTobj* _callee;
    std::pair<TASTobj*,TASTobj*> _arguments;
    std::vector<TASTobj*> _body;

};
#endif //TINYCOMPILER_AST_H
