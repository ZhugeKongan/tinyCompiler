//
// Created by ZhugeKongan on 2022/7/25.
//

#ifndef TINYCOMPILER_TRANSFORMER_H
#define TINYCOMPILER_TRANSFORMER_H

#include "Parser.h"
#include "AST.h"


class Transformer{
public:
    static Transformer& OnGetTransformer();
private:
    Transformer(){};
public:
    TASTobj* run(ASTobj *astobjs);
    TASTobj* tranverseNode(ASTobj* astobj);


};

#endif //TINYCOMPILER_TRANSFORMER_H
