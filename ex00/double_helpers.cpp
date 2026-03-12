#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "convert_helpers.hpp"

static bool validateDouble(std::string str)
{
	bool isLeft = false;
	bool isRight = false;
	bool isDot = false;
	int i = 0;

	if (str == "-inf" || str == "+inf" || str =="nan")
		return true;

	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;

	while (str[i] && isdigit(str[i]))
	{
		isLeft = true;
		i++;
	}
	if (!str[i])
		return false;

	if (str[i] && str[i] == '.')
	{
		isDot = true;
		i++;
	}
	else
		return false;

	while (str[i] && isdigit(str[i]))
	{
		isRight = true;
		i++;
	}
	if (str[i])
		return false;

	return (isLeft && isDot && isRight);
}

static void printDouble(std::string str)
{
	double doubleNum;
	int integer;
	
	doubleNum = std::stod(str);

	if (str == "-inf" || str == "+inf" || str =="nan")
	{
		std::cout <<  "char: " << "imposible" << std::endl;
		std::cout << "int: " << "imposible" << std::endl;
	}
	else
	{
		integer = static_cast<int>(doubleNum);
		if (doubleNum < 0 || doubleNum > 127)
			std::cout <<  "char: " << "Out of range" << std::endl;
		else if (isprint(integer))
			std::cout << "char: '" << static_cast<char>(integer) << "'" << std::endl;
		else
			std::cout << "char: " << "Non displayable" << std::endl;

		if (doubleNum < -2147483648.0 || doubleNum > 2147483647.0)
			std::cout << "int: " << "Out of range" << std::endl;
		else
			std::cout << "int: " << integer << std::endl;
	}
	
	std::cout << "float: " << formatFloat(static_cast<float>(doubleNum)) << std::endl;
	std::cout << "double: " << formatDouble(doubleNum) << std::endl;
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

bool convertDouble(std::string str)
{
	if (validateDouble(str))
	{
		printDouble(str);
		return true;
	}
	return false;
}