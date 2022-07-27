//
// Created by ZhugeKongan on 2022/7/27.
//

#include "Tools.h"

std::string OnGetTokentypeName(Tokentype type)
{
    switch (type)
    {
        case PAREN:
            return "PAREN";
        case NAME:
            return "NAME";
        case NUMBER:
            return "NUMBER";
        case STRING:
            return "STRING";
        default:
            return "";
            break;
    }
    return "";
}

std::string OnGetASTtypeName(ASTtype type)
{
    switch (type)
    {
        case PROGRAM:
            return "PROGRAM";
        case CALLEXPRESSION:
            return "CALLEXPRESSION";
        case NUMBERLITERAL:
            return "NUMBERLITERAL";
        case STRINGLITERAL:
            return "STRINGLITERAL";
        default:
            return "";
            break;
    }
    return "";
}



std::string OnGetTASTtypeName(TASTtype type)
{
    switch (type)
    {
        case Program:
            return "Program";
        case ExpressionStatement:
            return "ExpressionStatement";
        case CallExpression:
            return "CallExpression";
        case Identifier:
            return "Identifier";
        case NumberLiteral:
            return "NumberLiteral";
        default:
            return "";
            break;
    }
    return "";
}
