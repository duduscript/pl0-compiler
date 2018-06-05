#include "Token.h"

Token::Token(){}

Token::Token(std::string s, Tag t, int l) :lexeme(s), tag(t), line(l){}

Token::~Token(){}

Tag Token::GetTag()
{
	return tag;
}

int Token::GetLine()
{
	return line;
}

void Token::ChangeTag(Tag t)
{
	tag = t;
}

void Token::Print()
{}

std::string Token::GetLexeme()
{
	return lexeme;
}
