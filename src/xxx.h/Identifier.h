#ifndef IDENTIFIER_H
#define IDENTIFIER_H

#include <map>
#include <vector>

struct Id
{
	Id();
	Id(int, int, int);
	Id& operator=(Id&);
	int kind;
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
};

#endif // IDENTIFIER_H
