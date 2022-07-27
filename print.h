//
// Created by ZhugeKongan on 2022/7/24.
//

#ifndef TINYCOMPILER_PRINT_H
#define TINYCOMPILER_PRINT_H



#include "Token.h"
#include "AST.h"
#include "Tools.h"

void print_token(Token token);
void print_tokens(std::vector<Token> tokens);

void print_astobj(ASTobj* astobj,int t);

void print_astobj(ASTobj *astobjs);

void print_astobj(TASTobj *tastobjs);

void print_astobj(TASTobj* astobj,int t);



#endif //TINYCOMPILER_PRINT_H