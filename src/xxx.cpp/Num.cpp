#include <iostream>
#include <sstream>
#include <iomanip>

#include "../xxx.h/Num.h"
#include "../xxx.h/Token.h"
#include "../xxx.h/Error.h"

Num::Num(){}

Num::Num(std::string s, int l) :Token(s, NUMBERSYM, l), value(0)
{
	if (GetLexeme().size() > 8){
		printError(25, GetLine());
	}
	std::istringstream tmp(GetLexeme());
	tmp >> value;
}

Num::~Num(){}

int Num::GetValue()
{
	return value;
}

void Num::Print()
{
	std::cout << value 
			  << "     (number)(" 
			  << Num::GetLine() 
			  << ")" 
			  << std::endl;
}
