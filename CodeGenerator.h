
//
// Created by ZhugeKongan on 2022/7/25.
//

#ifndef TINYCOMPILER_CODEGENERATOR_H
#define TINYCOMPILER_CODEGENERATOR_H

#include <fstream>
#include <string>
#include "AST.h"
#include <unordered_map>

class Generator{
public:
    std::unordered_map<std::string,std::string> string2ops;
    static Generator& OnGetGenerator();
private:
    Generator();
public:

    bool run(TASTobj *tastobjs,std::string opath);
    bool gHeader(std::ofstream &file);
    bool gEnder(std::ofstream &file);
    std::string gExpression(TASTobj *tastobj);


};


#endif //TINYCOMPILER_CODEGENERATOR_H
