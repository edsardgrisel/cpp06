#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

std::string formatFloat(float num)
{
	std::ostringstream oss;
	oss << std::setprecision(10) << num;
	std::string result = oss.str();

	if (result.find('.') == std::string::npos)
		result.append(".0");
	result.append("f");
	return result;
}

std::string formatDouble(double num)
{
	std::ostringstream oss;
	oss << std::setprecision(10) << num;
	std::string result = oss.str();

	if (result.find('.') == std::string::npos)
		result.append(".0");
	return result;
}

bool convertChar(std::string str)
{
	if (str.length() != 3)
		return false;
	if (str[0] != '\'' || str[2] != '\'')
		return false;
	if (!std::isprint(str[1]))
		return false;
	char c = str[1];
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << formatFloat(static_cast<float>(c)) << std::endl;
	std::cout << "double: " << formatDouble(static_cast<double>(c)) << std::endl;
	return true;
}

bool convertInt(std::string str)
{
	(void)str;
	return false;
}

bool convertFloat(std::string str)
{
	(void)str;
	return false;
}

bool convertDouble(std::string str)
{
	(void)str;
	return false;
}

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
	if (convertChar(str) || convertInt(str) || convertFloat(str) || convertDouble(str))
		return;
	else
		std::cout << "Error converting input." << std::endl;
}

