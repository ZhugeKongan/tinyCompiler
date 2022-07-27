//
// Created by ZhugeKongan on 2022/7/27.
//


#include "print.h"

void print_token(Token token){
    std::cout<<"type:"<<OnGetTokentypeName(token._type)<<std::endl;
    std::cout<< "value:"<< token._value<<std::endl;

}

void print_tokens(std::vector<Token> tokens){
    for(auto token:tokens){
        print_token(token);
    }
    std::cout<< std::endl;

}

void print_astobj(ASTobj* astobj,int t){
    if(astobj==nullptr)return ;
    t+=2;
    std::string blank="";
    for(int i=0;i<t;++i){blank+=" ";}
    if(astobj->_type==ASTtype::NUMBERLITERAL||astobj->_type==ASTtype::STRINGLITERAL){
        std::cout<<blank<<"type:"<<OnGetASTtypeName(astobj->_type)<<std::endl;
        std::cout<<blank<<"value:"<<astobj->_value<<std::endl;
    }
    else if(astobj->_type==ASTtype::CALLEXPRESSION){
        std::cout<<blank<<"type:"<<OnGetASTtypeName(astobj->_type)<<std::endl;
        std::cout<<blank<<"name:"<<astobj->_name<<std::endl;
        std::cout<<blank<<"params:"<<std::endl;
        print_astobj(astobj->_param.first,t);
        print_astobj(astobj->_param.second,t);

    }
    else {
        std::cout<<"can't recognize the astobj type! "<<std::endl;
    }


}

void print_astobj(ASTobj *astobjs){
    std::cout<< std::endl;
    std::cout<<"######  The ASTobj Struct.   ######"<<std::endl;
    std::cout<<"type:"<<OnGetASTtypeName(astobjs->_type)<<std::endl;
    std::cout<<"body:"<<std::endl;
    for(auto astobj:astobjs->_body){
        print_astobj(astobj,0);
        std::cout<< std::endl;
    }


}


void print_astobj(TASTobj* astobj,int t){
    if(astobj==nullptr)return ;
    t+=2;
    std::string blank="";
    for(int i=0;i<t;++i){blank+=" ";}
    if(astobj->_type==TASTtype::NumberLiteral){
        std::cout<<blank<<"type:"<<OnGetTASTtypeName(astobj->_type)<<std::endl;
        std::cout<<blank<<"value:"<<astobj->_value<<std::endl;
    }
    else if(astobj->_type==TASTtype::Identifier){
        std::cout<<blank<<"type:"<<OnGetTASTtypeName(astobj->_type)<<std::endl;
        std::cout<<blank<<"name:"<<astobj->_name<<std::endl;

    }
    else if(astobj->_type==TASTtype::CallExpression){
        std::cout<<blank<<"type:"<<OnGetTASTtypeName(astobj->_type)<<std::endl;
        std::cout<<blank<<"callee:"<<std::endl;
        print_astobj(astobj->_callee,t);

        std::cout<<blank<<"arguments:"<<std::endl;
        print_astobj(astobj->_arguments.first,t);
        print_astobj(astobj->_arguments.second,t);

    }
    else if(astobj->_type==TASTtype::ExpressionStatement){
        std::cout<<blank<<"type:"<<OnGetTASTtypeName(astobj->_type)<<std::endl;
        std::cout<<blank<<"expression:"<<std::endl;
        print_astobj(astobj->_expression,t);

    }
    else {
        std::cout<<"can't recognize the astobj type! "<<std::endl;
    }


}

void print_astobj(TASTobj *tastobjs){
    std::cout<< std::endl;
    std::cout<<"######  The Target ASTobj Struct.   ######"<<std::endl;
    std::cout<<"type:"<<OnGetTASTtypeName(tastobjs->_type)<<std::endl;
    std::cout<<"body:"<<std::endl;
    for(auto tastobj:tastobjs->_body){
//        std::cout<<"  type:"<<OnGetASTtypeName(m_tastobj->_type)<<std::endl;
//        std::cout<<"  expression:"<<std::endl;
        print_astobj(tastobj,0);
        std::cout<< std::endl;
    }

}

