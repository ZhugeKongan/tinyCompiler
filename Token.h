//
// Created by ZhugeKongan on 2022/7/22.
//

#ifndef TINYCOMPILER_TOKEN_H
#define TINYCOMPILER_TOKEN_H



#include<iostream>
#include <vector>
#include <string>
#include "Enum.h"

class Token{
public:
    Tokentype _type;
    std::string _value;

public:
    Token (){

    }
    Token(const Tokentype &type,const std::string &value){
        _type=type;
        _value=value;
    }

};

#endif //TINYCOMPILER_TOKEN_H