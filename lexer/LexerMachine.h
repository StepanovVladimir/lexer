#pragma once

#include "Token.h"
#include <array>

struct State
{
	std::array<int, 24> transitions;
	TokenType tokenType;
};

const std::array<State, 31> LEXER_MACHINE
{
	State{{ 1, 1, 1, 1, 1, 2, 3, 3, 13, 13, 14, 13, 18, 18, 19, 23, -1, 26, 27, 28, 30, 0, 0, -1 }, TokenType::Nothing},

	State{{ 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, TokenType::Id},
	
	State{{ 0, 0, 9, 0, 11, 3, 3, 3, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, TokenType::Integer},
	State{{ 0, 0, 0, 0, 0, 3, 3, 3, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, TokenType::Integer},

	State{{ -1, -1, -1, -1, -1, 5, 5, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, TokenType::Error},
	State{{ 0, 0, 0, 6, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, TokenType::Float},
	State{{ -1, -1, -1, -1, -1, -1, -1, -1, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, TokenType::Error},
	State{{ -1, -1, -1, -1, -1, 8, 8, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, TokenType::Error},
	State{{ 0, 0, 0, 0, 0, 8, 8, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, TokenType::Float},

	State{{ -1, -1, -1, -1, -1, 10, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, TokenType::Error},
	State{{ 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, TokenType::Binary},

	State{{ -1, 12, 12, 12, -1, 12, 12, 12, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, TokenType::Error},
	State{{ 0, 12, 12, 12, 0, 12, 12, 12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, TokenType::Hexadecimal},

	State{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, TokenType::ArithmeticOperation},
	State{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 16, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, TokenType::ArithmeticOperation},
	
	State{{ 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0, 15 }, TokenType::Nothing},
	State{{ 16, 16, 16, 16, 16, 16, 16, 16, 16, 17, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16 }, TokenType::Error},
	State{{ 16, 16, 16, 16, 16, 16, 16, 16, 16, 17, 0, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16 }, TokenType::Error},
	
	State{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, TokenType::Separator},
	
	State{{ 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, -1, 21, 20, 21, 21, 21, 21, 21, -1, 21 }, TokenType::Error},
	State{{ 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, -1, 21 }, TokenType::Error},
	State{{ -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 22, -1, -1, -1, -1, -1, -1, -1, -1, -1 }, TokenType::Error},
	State{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, TokenType::Char},

	State{{ 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 25, 24, 23, 23, 23, 23, 23, -1, 23 }, TokenType::Error},
	State{{ 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, 23, -1, 23 }, TokenType::Error},
	State{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, TokenType::String},

	State{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0 }, TokenType::Assigning},

	State{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 0, 29, 0, 0, 0, 0 }, TokenType::Comparison},
	State{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 29, 0, 0, 0, 0, 0, 0 }, TokenType::Comparison},
	State{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, TokenType::Comparison},

	State{{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, TokenType::Bracket}
};