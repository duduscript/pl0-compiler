#include <iostream>

#include "Code.h"

Code::Code(int _op, int _l, int _m) :op(_op), l(_l), m(_m){}

void Code::printCode() const
{
	std::cout << getOp(op) << "  " << l << "  ";
	if (op == 2)
		std::cout << getALUOp(m) << std::endl;
	else std::cout << m << std::endl;
}
void Code::changeAdrr(int x)
{
	m = x;
}
std::string Code::getOp(int op) const
{
	switch (op) {
	case 1:
		return "LIT";
		break;
	case 2:
		return "OPR";
		break;
	case 3:
		return "LOD";
		break;
	case 4:
		return "STO";
		break;
	case 5:
		return "CAL";
		break;
	case 6:
		return "INC";
		break;
	case 7:
		return "JMP";
		break;
	case 8:
		return "JPC";
		break;
	case 9:
		return "SIO_OUT";
		break;
	case 10:
		return "SIO_IN";
		break;
	default:
		return "";
		break;
	}
}

std::string Code::getALUOp(int m) const
{
	switch (m) {
	case 0:
		return "OPR_RET";
		break;
	case 1:
		return "OPR_NEG";
		break;
	case 2:
		return "OPR_ADD";
		break;
	case 3:
		return "OPR_SUB";
		break;
	case 4:
		return "OPR_MUL";
		break;
	case 5:
		return "OPR_DIV";
		break;
	case 6:
		return "OPR_ODD";
		break;
	case 7:
		return "OPR_MOD";
		break;
	case 8:
		return "OPR_EQL";
		break;
	case 9:
		return "OPR_NEQ";
		break;
	case 10:
		return "OPR_LSS";
		break;
	case 11:
		return "OPR_LEQ";
		break;
	case 12:
		return "OPR_GTR";
		break;
	case 13:
		return "OPR_GEQ";
		break;
	default:
		return "";
		break;
	}
}

const int Code::getOp() const
{
	return op;
}

const int Code::getL() const
{
	return l;
}

const int Code::getM() const
{
	return m;
}
