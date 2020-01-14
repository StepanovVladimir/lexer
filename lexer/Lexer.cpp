#include "Lexer.h"
#include "CharsIds.h"
#include "Keywords.h"
#include "LexerMachine.h"

using namespace std;

Lexer::Lexer(const string& fileName)
	: fIn(fileName)
	, chIndex(1)
	, lineNumber(0)
{
}

bool Lexer::isEof() const
{
	return fIn.eof();
}

Token Lexer::getToken()
{
	size_t stateId = 0;
	string value;

	while (!fIn.eof())
	{
		if (chIndex > curLine.size())
		{
			getline(fIn, curLine);
			chIndex = 0;
			++lineNumber;
		}

		while (chIndex <= curLine.length())
		{
			map<char, size_t>::const_iterator iter;
			if (chIndex < curLine.length())
			{
				iter = CHARS_IDS.find(curLine[chIndex]);
			}
			else
			{
				iter = CHARS_IDS.find('\n');
			}

			size_t nextState;
			TokenType type = LEXER_MACHINE[stateId].tokenType;
			if (iter != CHARS_IDS.end())
			{
				nextState = LEXER_MACHINE[stateId].transitions[iter->second];
			}
			else
			{
				nextState = LEXER_MACHINE[stateId].transitions[LEXER_MACHINE[0].transitions.size() - 1];
			}

			if (nextState == -1)
			{
				return Token{ TokenType::Error, value + curLine[chIndex], lineNumber };
			}
			else if (nextState == 0)
			{
				if (type == TokenType::Nothing || type == TokenType::Error)
				{
					stateId = nextState;
					value = "";
					++chIndex;
				}
				else
				{
					if (type == TokenType::Id && KEYWORDS.find(value) != KEYWORDS.end())
					{
						return Token{ TokenType::Keyword, value, lineNumber };
					}
					return Token{ type, value, lineNumber };
				}
			}
			else
			{
				value += curLine[chIndex];
				stateId = nextState;
				++chIndex;
			}
		}
	}
	
	return Token{ LEXER_MACHINE[stateId].tokenType, value, lineNumber };
}