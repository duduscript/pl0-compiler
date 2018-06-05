#include <iostream>
#include <string>
#include <iomanip>

#include "ObjCode.h"
#include "Code.h"

ObjCode::ObjCode()
{
}

ObjCode::ObjCode(ObjCode &obj)
{
	std::cout << "ObjCode Copy Construct" << std::endl;
	Code* pCode;
	for (int i = 0; i != obj.size(); ++i){
		pCode = new Code(obj.at(i)->getOp(), obj.at(i)->getL(), obj.at(i)->getM());
		icode.push_back(pCode);
		pCode = NULL;
	}
}

ObjCode::~ObjCode()
{
	for (size_t i = 0; i != icode.size(); ++i)
		delete icode[i];
}

void ObjCode::printCode() const
{
	std::cout << "**************************************************" << std::endl;
	std::cout << "  n   op  l  m" << std::endl;
	std::cout << "**************************************************" << std::endl;
	for (size_t i = 0; i != icode.size(); ++i){
		std::cout << std::setw(3) << i << "  ";
		icode[i]->printCode();
	}
}
void ObjCode::emitCode(int op, int l, int m)
{
	icode.push_back(new Code(op, l, m));
}

const int ObjCode::size() const
{
	return icode.size();
}
void ObjCode::changeAdrr(int a, int x)
{
	icode[a]->changeAdrr(x);
}

Code*& ObjCode::at(int index)
{
	return icode[index];
}

//const Code*& ObjCode::at(int index) const
//{
//	return icode[index];
//}
