#include <iostream>
#include <stdlib.h>
#include <limits>
#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &cpy)
{
	*this = cpy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &cpy)
{
	(void)cpy;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
}

static bool isChar(std::string &input)
{
	if (input.length() == 1 && std::isprint(input.at(0)) && !std::isdigit(input.at(0)))
		return true;
	return false;
}

static bool isPseudoLiteral(std::string &input)
{
	return input == "+inf" || input == "-inf" || input == "nan" || input == "+inff" || input == "-inff" || input == "nanf";
}

static int getOccurrences(std::string &str, char c)
{
	int occurrences = 0;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (str.at(i) == c)
			occurrences++;
	}
	return occurrences;
}

static bool isWellFormatted(std::string &input)
{
	if (getOccurrences(input, '.') > 1 || getOccurrences(input, 'f') > 1 || (!std::isdigit(input.at(0)) && input.at(0) != '+' && input.at(0) != '-'))
		return false;
	int inputLength = input.length();
	for (int i = 1; i < inputLength; i++)
	{
		char currentChar = input.at(i);

		if (!std::isdigit(currentChar) && currentChar != '.')
		{
			if (currentChar != 'f' || i != inputLength - 1)
				return false;
		}
	}
	return true;
}

static e_itype getType(std::string &input)
{
	if (input.empty())
		return UNDEFINED;
	if (isChar(input))
		return CHAR;
	if (isPseudoLiteral(input))
		return PSEUDO_LITERAL;
	if (!isWellFormatted(input))
		return UNDEFINED;
	if (input.find('f') != std::string::npos)
		return FLOAT;
	if (input.find('.') != std::string::npos)
		return DOUBLE;
	return INT;
}

static void handleUndefinedType(std::string &input)
{
	std::cout << "Input \"" << input << "\" cannot be casted." << std::endl;
}

static void convertToChar(std::string &input, e_itype &type)
{
	int realValue = std::atoi(input.c_str());

	std::cout << "char: ";
	if (type == CHAR)
		std::cout << "'" << input << "'";
	else if (type == PSEUDO_LITERAL)
		std::cout << "impossible";
	else if (realValue >= 0 && realValue <= 255 && std::isprint(realValue))
		std::cout << "'" << static_cast<unsigned char>(realValue) << "'";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
}

static bool doesOverflow(std::string &input)
{
	if (input.length() > 11)
		return true;

	long long num = std::atoll(input.c_str());
	return (num < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max());
}

static void convertToInt(std::string &input, e_itype &type)
{
	std::cout << "int: ";
	if (doesOverflow(input) || type == PSEUDO_LITERAL)
		std::cout << "impossible";
	else if (type == CHAR)
		std::cout << static_cast<int>(input.at(0));
	else
		std::cout << std::atoi(input.c_str());
	std::cout << std::endl;
}

static void convertToFloat(std::string &input, e_itype &type)
{
	std::cout.precision(1);
	std::cout.setf(std::ios::fixed);
	std::cout << "float: ";
	if (type == CHAR)
		std::cout << static_cast<float>(input.at(0));
	else
		std::cout << static_cast<float>(std::atof(input.c_str()));
	std::cout << "f" << std::endl;
	std::cout.unsetf(std::ios::fixed);
}

static void convertToDouble(std::string &input, e_itype &type)
{
	std::cout.precision(1);
	std::cout.setf(std::ios::fixed);
	std::cout << "double: ";
	if (type == CHAR)
		std::cout << static_cast<double>(input.at(0));
	else
		std::cout << static_cast<double>(std::atof(input.c_str()));
	std::cout << std::endl;
	std::cout.unsetf(std::ios::fixed);
}

void ScalarConverter::convert(std::string input)
{
	e_itype inputType = getType(input);

	if (inputType != UNDEFINED)
	{
		convertToChar(input, inputType);
		convertToInt(input, inputType);
		convertToFloat(input, inputType);
		convertToDouble(input, inputType);
	}
	else
		handleUndefinedType(input);
}
