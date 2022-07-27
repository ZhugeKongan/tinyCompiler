//
// Created by ZhugeKongan on 2022/7/24.
//

#ifndef TINYCOMPILER_PARSER_H
#define TINYCOMPILER_PARSER_H

#include "Tokenizer.h"
#include "AST.h"

class Parser{
public:
    static Parser& OnGetParser();
private:
    Parser(){};
public:
    ASTobj* parseTokens(const std::vector<Token> &tokens);
    ASTobj* parseExpr(const std::vector<Token> &tokens,int &t);


};














#endif //TINYCOMPILER_PARSER_H
