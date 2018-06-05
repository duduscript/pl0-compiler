#ifndef WORD_H
#define WORD_H

#include "Token.h"

const int NUMBER_OF_KEYWORD = 14;

extern const std::string KeywordTable[];

class Word :public Token
{
public:
	Word();
	Word(std::string v, int l);
	~Word();
	void Print();
public:
	static int GetKeywordNum(std::string);
	static Tag GetKeywordTag(int t);
};


#endif // WORD_H
