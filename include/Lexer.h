#ifndef LEXER_H
#define LEXER_H

#include <list>
#include <fstream>

class Token;

class Lexer
{
public:
	Lexer();
	Lexer(std::string FileName);
	~Lexer();
public:
	void Tokenizer();
	void PrintList();
	void JudgeError();
	Token* GetToken();
	void PutToken(Token*& p);
	void PlusLine();
private:
	std::fstream in;
	std::list<Token*> TokenList;
	int line;
private:
	Lexer(const Lexer&)=delete;
	Lexer& operator=(const Lexer&)=delete;
};


#endif // LEXER_H
