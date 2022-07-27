//
// Created by ZhugeKongan on 2022/7/25.
//
#include "Transformer.h"


Transformer& Transformer::OnGetTransformer() {
    static Transformer m_transfor;
    return m_transfor;
}

TASTobj* Transformer::run(ASTobj *astobjs){
    if(astobjs->_type!=ASTtype::PROGRAM)return nullptr;

    TASTobj* tastobjs=new TASTobj();
    tastobjs->_type=TASTtype::Program;
    try {
        for(auto astobj:astobjs->_body){
            TASTobj* tastobj=new TASTobj();
            tastobj->_type=TASTtype::ExpressionStatement;
            tastobj->_expression=Transformer::tranverseNode(astobj);
            tastobjs->_body.emplace_back(tastobj);

        }
    }
    catch(char const* strs){
        std::cout<<"Transformer Error:"<<strs<<std::endl;
    }

    return tastobjs;
}

TASTobj* Transformer::tranverseNode(ASTobj* astobj){
    if(astobj==nullptr) return nullptr;
    TASTobj* tastobj=new TASTobj();
    if(astobj->_type==ASTtype::STRINGLITERAL||astobj->_type==ASTtype::NUMBERLITERAL){
        tastobj->_type=TASTtype::NumberLiteral;
        tastobj->_value=astobj->_value;
    }
    else if(astobj->_type==ASTtype::CALLEXPRESSION){
        tastobj->_type=::TASTtype::CallExpression;
        tastobj->_callee=new TASTobj();
        tastobj->_callee->_type=TASTtype::Identifier;
        tastobj->_callee->_name=astobj->_name;
        tastobj->_arguments.first=Transformer::tranverseNode(astobj->_param.first);
        tastobj->_arguments.second=Transformer::tranverseNode(astobj->_param.second);
    }
    else{
        throw "tranverseNode didn't support the ASTtype ！";
    }
    return tastobj;
}