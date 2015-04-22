#include "Identifier.h"

Id::Id(){}

Id::Id(int _kind, int _level, int _addr) :kind(_kind), level(_level), addr(_addr)
{
}

void Id::operator=(Id& _id)
{
	this->kind = _id.kind;
	this->level = _id.level;
	this->addr = _id.addr;
}

Identifier::Identifier() :currentLevel(0)
{
	currM.resize(10, 0);
}
