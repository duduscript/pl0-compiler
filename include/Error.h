#ifndef ERROR_H
#define ERROR_H

#include <string>

extern const std::string parseErrors[];

void printError(int errorId, int line);

#endif
