#include <iostream>

#include "Word.h"

Word::Word(){}

Word::Word(std::string v, int l) :Token(v, GetKeywordTag(GetKeywordNum(v)), l){}

Word::~Word(){}

void Word::Print()
{
	Tag t = GetTag();
	if (t != IDENTSYM)
		std::cout << GetLexeme()
				  << "   (Keyword)(" 
				  << GetLine() 
				  << ")"
				  << std::endl;
	else
		std::cout << GetLexeme() 
				  << "    (IDENT)(" 
				  << GetLine() 
				  << ")" 
				  << std::endl;
}

Tag Word::GetKeywordTag(int t)
{
	if (t == 0)				return BEGINSYM;
	else if (t == 1)		return ENDSYM;
	else if (t == 2)		return IFSYM;
	else if (t == 3)		return THENSYM;
	else if (t == 4)		return WHILESYM;
	else if (t == 5)		return DOSYM;
	else if (t == 6)		return CALLSYM;
	else if (t == 7)		return CONSTSYM;
	else if (t == 8)		return VARSYM;
	else if (t == 9)		return PROCSYM;
	else if (t == 10)		return WRITESYM;
	else if (t == 11)		return READSYM;
	else if (t == 12)		return ELSESYM;
	else if (t == 13)		return ODDSYM;
	else					return IDENTSYM;
}

int Word::GetKeywordNum(std::string s)
{
	for (int i = 0; i != NUMBER_OF_KEYWORD; ++i)
		if (KeywordTable[i] == s)
			return i;
	return -1;
}

const std::string KeywordTable[NUMBER_OF_KEYWORD] =
{
	"begin",  "end",   "if",    "then",   "while",
	"do",	  "call",  "const", "var",    "procedure",
	"write",  "read",  "else",  "odd"
};
