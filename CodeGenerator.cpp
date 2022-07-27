//
// Created by ZhugeKongan on 2022/7/27.
//

#include "CodeGenerator.h"

Generator::Generator(){
    string2ops["add"]="+";
    string2ops["subtract"]="-";
    string2ops["multiply"]="*";
    string2ops["division"]="/";

}
Generator& Generator::OnGetGenerator() {
    static Generator mGenerator;
    return mGenerator;
}

bool Generator::gHeader(std::ofstream &file){
    file<<"/*#### Created by ZhugeKongan.  ####*/\n";
    file<<"#include <stdio.h>\n";
    file<<"#include <stdlib.h>\n";
    file<<"\n\n";
    file<<"int main(void){\n";

    return true;
}

bool Generator::gEnder(std::ofstream &file){
    file<<"\n";

    file<<"\t return 0;\n";
    file<<"}\n";
    return true;
}

std::string Generator::gExpression(TASTobj *tastobj){
    if(tastobj== nullptr)return "";
    std::string resluts="";
    if(tastobj->_type==TASTtype::CallExpression){
        resluts+="(";
        resluts+=gExpression(tastobj->_arguments.first);
        resluts+= gExpression(tastobj->_callee);
        resluts+=gExpression(tastobj->_arguments.second);
        resluts+=")";
    }
    else if(tastobj->_type==TASTtype::Identifier){
        if(Generator::OnGetGenerator().string2ops.find(tastobj->_name)!=Generator::OnGetGenerator().string2ops.end()){
            resluts+=Generator::OnGetGenerator().string2ops[tastobj->_name];
        }
        else{
            throw "dinnot support generate the ops:"+tastobj->_name;
        }
    }
    else if(tastobj->_type==TASTtype::NumberLiteral){
        resluts+=tastobj->_value;
    }
    else{
        throw "Not support the generate TASTtype !";
    }
    return resluts;
}

bool Generator::run(TASTobj *tastobjs,std::string opath) {

    if(tastobjs->_type!=TASTtype::Program)return false;

    std::ofstream file;
    file.open(opath,std::ios_base::out);
    if(!file.is_open()){
        std::cout<<"open file error!"<<opath<<std::endl;
        return false;
    }

    try {
        Generator::OnGetGenerator().gHeader(file);
        for(auto tastobj:tastobjs->_body){
            if(tastobj->_type!=TASTtype::ExpressionStatement)continue;
            std::string cur_exp="";
            cur_exp=Generator::OnGetGenerator().gExpression(tastobj->_expression);
            file<<"\t"<<cur_exp<<";\n";
        }
        Generator::OnGetGenerator().gEnder(file);

    }
    catch(char const* strs){
        std::cout<<"Generator Error:"<<strs<<std::endl;
        return false;
    }

    file.close();

    return true;
}