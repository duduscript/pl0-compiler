#ifndef CODE_H
#define CODE_H

#include <string>

class Code
{
public:
	Code(int _op, int _l, int _m);
	void printCode() const;
	void changeAdrr(int);
	std::string getOp(int) const;
	std::string getALUOp(int) const;
	const int getOp() const;
	const int getL() const;
	const int getM() const;
private:
	const int op;	//Operation
	int l;			//L is lexicographical level
	int m;			//M is an address, data or ALU operatorion
private:
	Code()=delete;
	Code(const Code&)=delete;
	Code& operator=(const Code&)=delete;
};

#endif
