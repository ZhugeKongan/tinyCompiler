//
// Created by ZhugeKongan on 2022/7/22.
//

#ifndef TINYCOMPILER_ENUM_H
#define TINYCOMPILER_ENUM_H


#include<iostream>

enum Tokentype {
    PAREN,
    NAME,
    NUMBER,
    STRING,
};

enum ASTtype {
    PROGRAM,
    CALLEXPRESSION,
    NUMBERLITERAL,
    STRINGLITERAL,

};

enum TASTtype {
    Program,
    ExpressionStatement,
    CallExpression,
    Identifier,
    NumberLiteral,

};


#endif //TINYCOMPILER_ENUM_H