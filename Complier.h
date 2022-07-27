//
// Created by ZhugeKongan on 2022/7/27.
//

#ifndef TINYCOMPILER_COMPLIER_H
#define TINYCOMPILER_COMPLIER_H
#include <iostream>
#include <fstream>
#include<string>

#include "print.h"
#include "Tokenizer.h"
#include "Parser.h"
#include "Transformer.h"
#include "CodeGenerator.h"



class Complier{
public:
    DECLARE(s,std::string,InFiles);
    DECLARE(s,std::string,OutFiles);
public:
    static Complier& OnGetComplier();
private:
    Complier(){};
public:
    bool Init();
    bool run();


};











#endif //TINYCOMPILER_COMPLIER_H
