#pragma once

enum struct TokenType
{
	Id,
	Integer,
	Float,
	Char,
	String,
	Keyword,
	Separator,
	Assigning,
	ArithmeticOperation,
	Comparison,
	Bracket,
	Error,
	Nothing
};