//
// Created by ZhugeKongan on 2022/7/25.
//

#ifndef TINYCOMPILER_TOOLS_H
#define TINYCOMPILER_TOOLS_H

#include "Enum.h"
#include <unordered_map>




#define DECLARE(sPreFix,sType,sName)\
private:\
	sType _sPreFix##sName;\
public:\
	bool OnSet##sName(const sType& sTemp)\
	{\
		_sPreFix##sName=sTemp;\
		return true;\
	}\
	sType OnGet##sName()\
	{\
		return _sPreFix##sName;\
	}                                  \


std::string OnGetTokentypeName(Tokentype type);

std::string OnGetASTtypeName(ASTtype type);

std::string OnGetTASTtypeName(TASTtype type);




#endif //TINYCOMPILER_TOOLS_H
