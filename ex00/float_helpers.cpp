#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include "convert_helpers.hpp"
#include <cmath>

static bool validateFloat(std::string str)
{
	bool isLeft = false;
	bool isRight = false;
	bool isDot = false;
	bool isF = false;
	int i = 0;

	if (str == "-inff" || str == "+inff" || str =="nanf")
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
	if (!str[i])
		return false;

	if (str[i] && str[i] == 'f')
	{
		isF = true;
		i++;
	}
	if (str[i])
		return false;

	return isLeft && isDot && isRight && isF;
}

static void printFloat(std::string str)
{
	float floatNum;
	int integer;

	floatNum = std::stof(str);

	if (!std::isfinite(floatNum))
	{
		std::cout <<  "char: " << "imposible" << std::endl;
		std::cout << "int: " << "imposible" << std::endl;
	}
	else
	{
		integer = static_cast<int>(floatNum);

		if (floatNum < 0 || floatNum > 127)
			std::cout <<  "char: " << "Out of range" << std::endl;
		else if (isprint(integer))
			std::cout << "char: '" << static_cast<char>(integer) << "'" << std::endl;
		else
			std::cout << "char: " << "Non displayable" << std::endl;

		if (floatNum < -2147483648.0f || floatNum > 2147483647.0f)
			std::cout << "int: " << "Out of range" << std::endl;
		else
			std::cout << "int: " << integer << std::endl;
	}


	std::cout << "float: " << formatFloat(floatNum) << std::endl;
	std::cout << "double: " << formatDouble(static_cast<double>(floatNum)) << std::endl;
}

std::string formatFloat(float num)
{
	std::ostringstream oss;
	oss << std::setprecision(1) << std::fixed << num;
	std::string result = oss.str();

	result.append("f");
	return result;
}

bool convertFloat(std::string str)
{

	if (validateFloat(str))
	{
		printFloat(str);
		return true;
	}
	return false;
}