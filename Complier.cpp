//
// Created by ZhugeKongan on 2022/7/27.
//

#include "Complier.h"

Complier& Complier::OnGetComplier() {
    static Complier mComplier;
    return mComplier;
}

bool Complier::Init(){
    std::cout << "####  tinyComplier by ZhugeKongan!  ####" << std::endl;
    return true;
}

bool Complier::run(){
    std::ifstream file;
    file.open(Complier::OnGetComplier().OnGetInFiles(),std::ios_base::in);
    if(!file.is_open()){
        std::cout<<"open file error!"<<Complier::OnGetComplier().OnGetInFiles()<<std::endl;
        return false;
    }
    std::string inputs;
//    std::vector<ASTobj> astobjs;
    ASTobj* astobjs=new ASTobj();
    astobjs->_type=ASTtype::PROGRAM;

    while(std::getline(file,inputs)){
        std::cout<<inputs<<std::endl;
        if(inputs.size()==0)continue;

        try{
            auto tokens= tokenizer(inputs);
            //print_tokens(tokens);
            if(tokens.size()==0)continue;
            //auto astobj=Parser::OnGetParser().parseTokens(tokens);
            int t=0;
            auto astobj=Parser::OnGetParser().parseExpr(tokens,t);
            if(astobj!=nullptr)astobjs->_body.emplace_back(astobj);


        }
        catch(char const* strs){
            std::cout<<"compiler error:"<<strs<<std::endl;
        }
    }
    file.close();

    print_astobj(astobjs);
    auto tastobj=Transformer::OnGetTransformer().run(astobjs);
    print_astobj(tastobj);

    if(Generator::OnGetGenerator().run(tastobj,Complier::OnGetComplier().OnGetOutFiles())){
        std::cout<<"Code Generator successfully !"<<std::endl;
    }


    return true;
}
