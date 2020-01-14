#pragma once

enum struct TokenType
{
	Id,
	Integer,
	Float,
	Binary,
	Hexadecimal,
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