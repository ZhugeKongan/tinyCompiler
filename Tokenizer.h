//
// Created by ZhugeKongan on 2022/7/22.
//

#ifndef TINYCOMPILER_TOKENIZER_H
#define TINYCOMPILER_TOKENIZER_H


#include "Token.h"


std::vector<Token> tokenizer(const std::string &strs);//将每行语句进行词法分析

#endif //TINYCOMPILER_TOKENIZER_H