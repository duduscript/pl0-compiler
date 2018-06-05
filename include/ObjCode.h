#ifndef OBJCODE_H
#define OBJCODE_H

#include <vector>
class Code;

class ObjCode
{
public:
	ObjCode();
	ObjCode(ObjCode&);
	~ObjCode();
	void emitCode(int, int, int);
	void printCode() const;
	const int size() const;
	void changeAdrr(int, int);
	Code*& at(int);
	//const Code*& at(int) const;
private:
	std::vector<Code*> icode;
};

enum {
	LIT = 1, OPR, LOD, STO, CAL, INC, JMP, JPC, SIO_OUT, SIO_IN
};

enum {
	OPR_RET, OPR_NEG, OPR_ADD, OPR_SUB, OPR_MUL, OPR_DIV, OPR_ODD, OPR_MOD,
	OPR_EQL, OPR_NEQ, OPR_LSS, OPR_LEQ, OPR_GTR, OPR_GEQ
};

#endif // OBJCODE_H
