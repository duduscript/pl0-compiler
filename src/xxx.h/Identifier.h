#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include <map>
#include <vector>

enum KIND {VAR = 1, CONST, PROC};

struct Id
{
	Id();
	Id(KIND, int, int);
	Id& operator=(const Id&);
	KIND kind;
	int value;
	int level;
	int addr;
};

class Identifier
{
public:
	Identifier();
public:
	std::map<std::string, Id> id;
	std::vector<int> currM;
	int currentLevel;
private:
	Identifier(const Identifier&)=delete;
	Identifier& operator=(const Identifier&)=delete;
};

#endif // IDENTIFIER_H
