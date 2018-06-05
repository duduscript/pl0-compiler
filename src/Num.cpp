#include <iostream>
#include <sstream>
#include <iomanip>

#include "Num.h"
#include "Token.h"
#include "Error.h"

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
