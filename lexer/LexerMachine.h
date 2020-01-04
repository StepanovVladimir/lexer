#pragma once

#include "Token.h"
#include <array>

struct State
{
	std::array<int, 17> transitions;
	TokenType tokenType;
};

const std::array<State, 23> LEXER_MACHINE
{
	State{{ 1, 2, 5, 5, 6, 10, 10, 11, 15, -1, 18, 19, 20, 22, 0, 0, -1 }, TokenType::Nothing},

	State{{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, TokenType::Id},
	
	State{{ 0, 2, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, TokenType::Integer},
	State{{ -1, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, TokenType::Error},
	State{{ 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, TokenType::Float},
	
	State{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, TokenType::ArithmeticOperation},
	State{{ 0, 0, 0, 8, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, TokenType::ArithmeticOperation},
	
	State{{ 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 7 }, TokenType::Nothing},
	State{{ 8, 8, 8, 9, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 }, TokenType::Error},
	State{{ 8, 8, 8, 9, 0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8 }, TokenType::Error},
	
	State{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, TokenType::Separator},
	
	State{{ 13, 13, 13, 13, 13, 13, 13, -1, 13, 12, 13, 13, 13, 13, 13, -1, 13 }, TokenType::Error},
	State{{ 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, -1, 13 }, TokenType::Error},
	State{{ -1, -1, -1, -1, -1, -1, -1, 14, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, TokenType::Error},
	State{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, TokenType::Char},

	State{{ 15, 15, 15, 15, 15, 15, 15, 15, 17, 16, 15, 15, 15, 15, 15, -1, 15 }, TokenType::Error},
	State{{ 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, -1, 15 }, TokenType::Error},
	State{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, TokenType::String},

	State{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0 }, TokenType::Assigning},

	State{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 0, 21, 0, 0, 0, 0 }, TokenType::Comparison},
	State{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 21, 0, 0, 0, 0, 0, 0 }, TokenType::Comparison},
	State{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, TokenType::Comparison},

	State{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, TokenType::Bracket}
};