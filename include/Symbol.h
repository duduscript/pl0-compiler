#ifndef SYMBOL_H
#define SYMBOL_H

#include "Token.h"

const int SymbolNum = 16;
extern const std::string SymbolTable[];

class Symbol : public Token
{
public:
	Symbol();
	Symbol(std::string s,int l);
	~Symbol();
public:
	void Print();
public:
	static int GetSymbolNum(std::string);
	static Tag GetSymbolTag(int);
};

#endif // SYMBOL_H
