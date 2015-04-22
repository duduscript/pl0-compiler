#include <iostream>

#include "Vm.h"
#include "Code.h"
#include "ObjCode.h"

Vm::Vm(ObjCode& _objCode) :objCode(_objCode)
{
}

Vm::~Vm()
{
}

void Vm::pl0()
{
	Code* ir;
	bool writeSign = false, readSign = false;
	int sp = 0, bp = 1, ar = 0;
	size_t pc = 0;
	std::vector<int> stack(1000, 0);
	std::vector<int> level(20, -1);
	stack[0] = stack[1] = stack[2] = 0;
	level.push_back(0);
	auto base = [&](int l){
		int _base = bp;
		while (l > 0){
			_base = stack[_base - 1];
			--l;
		}
		return _base;
	};
	while (pc < stack.size() && ar >= 0){
		//std::cout << pc;
		ir = objCode.at(pc++);
		switch (ir->getOp()) {
		case LIT:
			stack[sp] = ir->getM();
			++sp;
			break;
		case OPR:
			switch (ir->getM()){
			case OPR_RET:
				sp = bp - 1;
				bp = stack[sp + 1];
				pc = stack[sp + 2];
				level[ar--] = -1;	//回到上一层
				break;
			case OPR_NEG:
				stack[sp - 1] = -stack[sp - 1];
				break;
			case OPR_ADD:
				--sp;
				stack[sp - 1] += stack[sp];
				break;
			case OPR_SUB:
				--sp;
				stack[sp - 1] -= stack[sp];
				break;
			case OPR_MUL:
				--sp;
				stack[sp - 1] *= stack[sp];
				break;
			case OPR_DIV:
				--sp;
				stack[sp - 1] /= stack[sp];
				break;
			case OPR_ODD:
				stack[sp - 1] = stack[sp - 1] % 2;
				break;
			case OPR_MOD:
				--sp;
				stack[sp - 1] = stack[sp - 1] % stack[sp];
				break;
			case OPR_EQL:
				--sp;
				stack[sp - 1] = stack[sp - 1] == stack[sp];
				break;
			case OPR_NEQ:
				--sp;
				stack[sp - 1] = stack[sp - 1] != stack[sp];
				break;
			case OPR_LSS:
				--sp;
				stack[sp - 1] = stack[sp - 1] < stack[sp];
				break;
			case OPR_LEQ:
				--sp;
				stack[sp - 1] = stack[sp - 1] <= stack[sp];
				break;
			case OPR_GTR:
				--sp;
				stack[sp - 1] = stack[sp - 1] > stack[sp];
				break;
			case OPR_GEQ:
				--sp;
				stack[sp - 1] = stack[sp - 1] >= stack[sp];
				break;
			default:
				break;
			}
			break;
		case LOD:
			stack[sp] = stack[base(ir->getL()) - 1 + ir->getM()];
			++sp;
			break;
		case STO:
			--sp;
			stack[base(ir->getL()) - 1 + ir->getM()] = stack[sp];
			break;
		case CAL:
			stack[sp] = base(ir->getL());
			stack[sp + 1] = bp;
			stack[sp + 2] = pc;
			bp = sp + 1;
			pc = ir->getM();
			level[ar] = sp;	
			for (int i = (ar - 1); i >= 0; --i){
				level[ar] -= level[i];
			}		//得到这个层的指令数
			++ar;	//调到下一层
			level[ar] = 3;	//层的大小初始为3
			break;
		case INC:
			sp += ir->getM();
			break;
		case JMP:
			pc = ir->getM();
			break;
		case JPC:
			--sp;
			if (stack[sp] == 0)
				pc = ir->getM();
			break;
		case SIO_OUT:
			--sp;
			writeSign = true;
			break;
		case SIO_IN:
			readSign = true;
			break;
		default:
			break;
		}
		/*
		std::cout << "| " << pc << "| " << bp << " |" << sp << " |" << ar << " |";
		for (int i = 0; i != sp; ++i){
			std::cout << stack[i] << " ";
		}
		std::cout << std::endl;
		*/
		if (writeSign){
			std::cout << "Output: " << stack[sp] << std::endl;
			writeSign = false;
		}
		if (readSign){
			std::cin >> stack[sp];
			++sp;
			readSign = false;
		}
	}
}
