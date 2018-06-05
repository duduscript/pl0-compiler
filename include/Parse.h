#ifndef PARSE_H
#define PARSE_H

#include "Lexer.h"
#include "ObjCode.h"
#include "Identifier.h"

class Token;

class Parse
{
public:
	Parse();
	Parse(std::string);
	~Parse();
public:
	void move();
	void program();
	void block();
	void decls();
	void stmts();
	void cond();
	void expr();
	void term();
	void factor();
	void GrammerAnalyzier();
	void PrintTemineCode();
	ObjCode& getCode();
private:
    Parse(const Parse&)=delete;
    Parse& operator=(const Parse&)=delete;
	Lexer lex;
	Token* look;
	ObjCode icode;
	Identifier ident;
};

#endif
