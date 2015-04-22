#include <iostream>
#include <sstream>

#include "Parse.h"
#include "Error.h"
#include "Token.h"

Parse::Parse() :look(0){}

Parse::Parse(std::string FileName) :lex(FileName), look(0)
{
	lex.Tokenizer();
}

Parse::~Parse(){}

void Parse::move()
{
	if (look != 0) {
		delete look;
		look = 0;
	}
	look = lex.GetToken();
}

void Parse::GrammerAnalyzier()
{
	lex.JudgeError();
	program();
	// icode.printCode();   测试输出中间代码
	// std::cout << "Over!" << std::endl;
}

ObjCode& Parse::getCode()
{
	return this->icode;
}

void Parse::program()
{
	block();
	icode.emitCode(OPR, 0, OPR_RET);
	move();
	if (look->GetTag() != PERIODSYM){
		printError(9, look->GetLine());
	}
}

void Parse::block()
{
	ident.currM[ident.currentLevel] += 3;
	icode.emitCode(INC, 0, 3);
	decls();
	stmts();
}

void Parse::decls()
{
	auto vardecl = [&]{ //定义变量
		int numOfVarDecl = 0;
		while (true){
			move();
			if (look->GetTag() != IDENTSYM)
				printError(4, look->GetLine());
			if (ident.id.find(look->GetLexeme()) != ident.id.end())
				printError(29, look->GetLine());

			ident.id[look->GetLexeme()] = Id(1,
											 ident.currentLevel, 
											 ident.currM[ident.currentLevel]++);
			numOfVarDecl++;

			move();
			if (look->GetTag() == SEMICOLOMSYM)
				break;
			else if (look->GetTag() == COMMASYM)
				continue;
			else
				printError(30, look->GetLine());
		}
		icode.emitCode(INC, 0, numOfVarDecl);
	};

	auto condecl = [&]{ //定义常量
		while (true){
			move();
			if (look->GetTag() != IDENTSYM)
				printError(4, look->GetLine());

			if (ident.id.find(look->GetLexeme()) != ident.id.end())
				printError(29, look->GetLine());
			std::string idName = look->GetLexeme();

			move();
			if (look->GetTag() == BECOMESSYM)
				printError(1, look->GetLine());
			if (look->GetTag() != EQLSYM)
				printError(2, look->GetLine());

			move();
			if (look->GetTag() != NUMBERSYM)
				printError(2, look->GetLine());
			auto convertStringToInt = [](std::string tmp){
				int sum = 0;
				std::stringstream ss;
				ss << tmp;
				ss >> sum;
				return sum;
			};
			ident.id[idName].kind = 2;
			ident.id[idName].value = convertStringToInt(look->GetLexeme());

			move();
			if (look->GetTag() == COMMASYM)
				continue;
			else if (look->GetTag() == SEMICOLOMSYM)
				break;
			else
				printError(30, look->GetLine());
		}
	};

	auto procdecl = [&]{ //定义函数
		while (true){
			move();
			if (look->GetTag() != IDENTSYM)
				printError(4, look->GetLine());
			if (ident.id.find(look->GetLexeme()) != ident.id.end())
				printError(29, look->GetLine());
			ident.id[look->GetLexeme()] = Id(3, 
											 ident.currentLevel++,		
											 icode.size() + 1); //proc的起始代码
			int tmpAdrr1 = icode.size();
			icode.emitCode(JMP, 0, 0);		//暂时不知道跳转地址，设为0
			
			move();
			if (look->GetTag() != SEMICOLOMSYM)
				printError(5, look->GetLine());
			block();
			icode.emitCode(OPR, 0, OPR_RET);
			ident.currentLevel--;
			icode.changeAdrr(tmpAdrr1, icode.size());	//修改跳转地址
			
			move();
			if (look->GetTag() != SEMICOLOMSYM)
				printError(5, look->GetLine());
			
			move();
			if (look->GetTag() != PROCSYM){
				lex.PutToken(look);
				break;
			} else {
				continue;
			}
		}
	};

	move();
	switch (look->GetTag()){
	case VARSYM:	vardecl();				break;
	case CONSTSYM:	condecl();				break;
	case PROCSYM:	procdecl();				break;
	default:		lex.PutToken(look);		return;
	}
	decls();
}

void Parse::stmts()
{
	move();
	std::string tmp;
	int tmpIfAdrr1, tmpIfAdrr2;//用于case IFSYM的临时变量
	int tmpWhileAdrr1, tmpWhileAdrr2;//用于case WHILESYM的临时变量
	switch (look->GetTag())
	{
	case IDENTSYM://assign
		if (ident.id.find(look->GetLexeme()) == ident.id.end())
			printError(11, look->GetLine());

		if (ident.id[look->GetLexeme()].kind != 1)
			printError(12, look->GetLine());
		tmp = look->GetLexeme();
		
		move();
		if (look->GetTag() != BECOMESSYM)
			printError(13, look->GetLine());
		expr();
		icode.emitCode(STO,
					   abs(ident.id[tmp].level - ident.currentLevel),
					   ident.id[tmp].addr);
		break;
	case CALLSYM://call
		move();
		if (look->GetTag() != IDENTSYM)
			printError(14, look->GetLine());

		if (ident.id.find(look->GetLexeme()) == ident.id.end())
			printError(11, look->GetLine());

		if (ident.id[look->GetLexeme()].kind == 1 ||
			ident.id[look->GetLexeme()].kind == 2)
				printError(15, (*look).GetLine());

		tmp = look->GetLexeme();
		icode.emitCode(CAL,
					   abs(ident.id[tmp].level - ident.currentLevel),
					   ident.id[tmp].addr);
		break;
	case BEGINSYM://begin
		while (true){
			stmts();
			move();
			if (look->GetTag() != ENDSYM && 
				look->GetTag() != SEMICOLOMSYM)
					printError(5, look->GetLine());
			if (look->GetTag() == ENDSYM)
				break;
			else
				continue;
		}
		break;
	case IFSYM://if
		cond();

		move();
		if (look->GetTag() != THENSYM)
			printError(16, look->GetLine());
		tmpIfAdrr1 = icode.size();
		icode.emitCode(JPC, 0, 0);
		stmts();
		tmpIfAdrr2 = icode.size();
		icode.emitCode(JMP, 0, 0);
		icode.changeAdrr(tmpIfAdrr1, icode.size());
		
		move();
		if (look->GetTag() != ELSESYM)
			lex.PutToken(look);
		else
			stmts();
		icode.changeAdrr(tmpIfAdrr2, icode.size());
		break;
	case WHILESYM://while
		tmpWhileAdrr1 = icode.size();
		cond();
		tmpWhileAdrr2 = icode.size();
		
		move();
		icode.emitCode(JPC, 0, 0);
		if (look->GetTag() != DOSYM)
			printError(18, look->GetLine());
		stmts();
		icode.emitCode(JMP, 0, tmpWhileAdrr1);
		icode.changeAdrr(tmpWhileAdrr2, icode.size());
		break;
	case READSYM://read
		move();
		if (look->GetTag() != IDENTSYM)
			printError(27, look->GetLine());
		if (ident.id.find(look->GetLexeme()) == ident.id.end())
			printError(11, look->GetLine());
		if (ident.id[look->GetLexeme()].kind == 3)
			printError(35, look->GetLine());
		icode.emitCode(SIO_IN, 0, 2);
		tmp = look->GetLexeme();
		icode.emitCode(STO,
					   abs(ident.id[tmp].level - ident.currentLevel),
					   ident.id[tmp].addr);
		break;
	case WRITESYM://write
		expr();
		icode.emitCode(SIO_OUT, 0, 1);
		break;
	case PERIODSYM://.
		break;
	default:
		lex.PutToken(look);
		break;
	}
}

void Parse::cond()
{
	move();
	if (look->GetTag() != ODDSYM){
		lex.PutToken(look);
		expr();

		move();
		auto tmp = look->GetTag();
		expr();
		switch (tmp) {
		case EQLSYM:
			icode.emitCode(OPR, 0, OPR_EQL);
			break;
		case NEQSYM:
			icode.emitCode(OPR, 0, OPR_NEQ);
			break;
		case LESSYM:
			icode.emitCode(OPR, 0, OPR_LSS);
			break;
		case LEQSYM:
			icode.emitCode(OPR, 0, OPR_LEQ);
			break;
		case GTRSYM:
			icode.emitCode(OPR, 0, OPR_GTR);
			break;
		case GEQSYM:
			icode.emitCode(OPR, 0, OPR_GEQ);
			break;
		default:
			printError(20, look->GetLine());
			break;
		}
	} else {
		expr();
	}
}

void Parse::expr()
{
	int op;
	move();
	if (look->GetTag() == MINUSYM)
		icode.emitCode(OPR, 0, OPR_NEG);
	if (look->GetTag() != PLUSSYM && 
		look->GetTag() != MINUSYM)
			lex.PutToken(look);
	term();
	while (true){
		move();
		if (look->GetTag() == PLUSSYM ||
			look->GetTag() == MINUSYM){
			op = look->GetTag();
		} else {
			lex.PutToken(look);
			break;
		}
		term();
		if (op == PLUSSYM)
			icode.emitCode(OPR, 0, OPR_ADD);
		if (op == MINUSYM)
			icode.emitCode(OPR, 0, OPR_SUB);
	}
}

void Parse::term()
{
	int op;
	factor();
	while (true){
		move();
		if (look->GetTag() == MULSYM ||
			look->GetTag() == SLASHSYM){
			op = look->GetTag();
		} else {
			lex.PutToken(look);
			break;
		}
		factor();
		if (op == MULSYM)
			icode.emitCode(OPR, 0, OPR_MUL);
		if (op == SLASHSYM)
			icode.emitCode(OPR, 0, OPR_DIV);
	}
}

void Parse::factor()
{
	move();
	if (look->GetTag() == LPARENTSYM){
		expr();
		move();
		if (look->GetTag() != RPARENTSYM)
			printError(22, look->GetLine());
	} else {
		if (look->GetTag() != IDENTSYM && look->GetTag() != NUMBERSYM)
			printError(23, look->GetLine());
	}
	if (look->GetTag() == IDENTSYM && ident.id[look->GetLexeme()].kind == 2)
		icode.emitCode(LIT, 
					   0,
					   ident.id[look->GetLexeme()].value);
	if (look->GetTag() == IDENTSYM && ident.id[look->GetLexeme()].kind == 1)
		icode.emitCode(LOD,
					   abs(ident.id[look->GetLexeme()].level - ident.currentLevel),
					   ident.id[look->GetLexeme()].addr);
	if (look->GetTag() == NUMBERSYM){
		auto convertStringToInt = [](std::string tmp){
			int sum = 0;
			std::stringstream ss;
			ss << tmp;
			ss >> sum;
			return sum;
		};
		icode.emitCode(LIT, 
					   0,
					   convertStringToInt(look->GetLexeme()));
	}
}
