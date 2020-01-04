#pragma once

#include "Token.h"
#include <fstream>

class Lexer
{
public:
	Lexer(const std::string& fileName);

	bool isEof() const;
	Token getToken();

private:
	std::ifstream fIn;
	std::string curLine;
	size_t chIndex;
	size_t lineNumber;
};