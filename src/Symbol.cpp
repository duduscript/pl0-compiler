#include <iostream>

#include "Symbol.h"

Symbol::Symbol(){}

Symbol::Symbol(std::string s,int l) :Token(s,GetSymbolTag(GetSymbolNum(s)),l){}

Symbol::~Symbol(){}

void Symbol::Print()
{
	if (BADTOKEN == GetTag())
		std::cout << GetLexeme()
				  << "    (BADTOKEN)("
				  << GetLine ()
				  << ")" 
				  << std::endl;
	else
		std::cout << GetLexeme()
				  << "   (symbol)(" 
				  << GetLine()
				  << ")"
				  << std::endl;
}

int Symbol::GetSymbolNum(std::string s)
{
	for (int i = 0; i != SymbolNum; ++i)
	{
		if (SymbolTable[i] == s)
			return i;
	}
	return -1;
}
Tag Symbol::GetSymbolTag(int t)
{
	if (t == 0)				return PLUSSYM;
	else if (t == 1)		return MINUSYM;
	else if (t == 2)		return MULSYM;
	else if (t == 3)		return SLASHSYM;
	else if (t == 4)		return EQLSYM;
	else if (t == 5)		return NEQSYM;
	else if (t == 6)		return LESSYM;
	else if (t == 7)		return LEQSYM;
	else if (t == 8)		return GTRSYM;
	else if (t == 9)		return GEQSYM;
	else if (t == 10)		return LPARENTSYM;
	else if (t == 11)		return RPARENTSYM;
	else if (t == 12)		return COMMASYM;
	else if (t == 13)		return SEMICOLOMSYM;
	else if (t == 14)		return PERIODSYM;
	else if (t == 15)		return BECOMESSYM;
	else					return BADTOKEN;
}

const std::string SymbolTable[] =
{
	"+",	"-",	"*",	"/",
	"=",	"<>",	"<",	"<=",
	">",	">=",	"(",	")",
	",",	";",	".",	":="
};
