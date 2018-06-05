#include "Identifier.h"

Id::Id(){}

Id::Id(KIND _kind, int _level, int _addr) :
	kind(_kind), level(_level), addr(_addr)
{
}

Id& Id::operator=(const Id& _id)
{
	if (this == &_id) return *this;
	this->kind = _id.kind;
	this->level = _id.level;
	this->addr = _id.addr;
	return *this;
}

Identifier::Identifier() :currentLevel(0)
{
	currM.resize(10, 0);
}
