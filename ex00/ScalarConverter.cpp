#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "convert_helpers.hpp"


ScalarConverter::ScalarConverter() {}


ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(std::string str)
{
	std::string trimmedStr = trim(str);

	if (trimmedStr.length() == 0)
		std::cerr << "Error converting input." << std::endl;

	if (convertChar(trimmedStr) || convertInt(trimmedStr) || convertFloat(trimmedStr) || convertDouble(trimmedStr))
		return;
	else
		std::cerr << "Error converting input." << std::endl;
}

