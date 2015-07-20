#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include "Tag.h"

class Token
{
public:
	Token();
	Token(std::string s, Tag t, int l);
	virtual  ~Token();
public:
	Tag			 GetTag();
	int			 GetLine();
	void		 ChangeTag(Tag t);
	std::string	 GetLexeme();
public:
	virtual  void  Print();
private:
	Token(const Token&) = delete;
	Token& operator=(const Token&) = delete;
	std::string lexeme;
	Tag tag;
	int line;
};

#endif // TOKEN_H
