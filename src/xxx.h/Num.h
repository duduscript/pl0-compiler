#ifndef NUM_H
#define NUM_H

#include "token.h"

class Num : public Token
{
public:
	Num();
	Num(std::string, int);
	~Num();
public:
	void Print();
	int GetValue();
private:
	int value;
};

#endif // NUM_H