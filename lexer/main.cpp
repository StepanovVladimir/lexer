#include "Lexer.h"
#include <iostream>

using namespace std;

int main()
{
    Lexer lexer("input.txt");
	while (!lexer.isEof())
	{
		Token token = lexer.getToken();
		token.lineNumber++;
	}
}