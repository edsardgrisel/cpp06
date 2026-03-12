#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>

static std::string formatFloat(float num)
{
	std::ostringstream oss;
	oss << std::setprecision(10) << num;
	std::string result = oss.str();

	if (result.find('.') == std::string::npos)
		result.append(".0");
	result.append("f");
	return result;
}

static std::string formatDouble(double num)
{
	std::ostringstream oss;
	oss << std::setprecision(10) << num;
	std::string result = oss.str();

	if (result.find('.') == std::string::npos)
		result.append(".0");
	return result;
}

std::string trim(const std::string& str)
{
	size_t first = str.find_first_not_of(" \t\n\r");
	if (std::string::npos == first)
		return "";
	size_t last = str.find_last_not_of(" \t\n\r");
	return str.substr(first, (last - first + 1));
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
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << formatFloat(static_cast<float>(c)) << std::endl;
	std::cout << "double: " << formatDouble(static_cast<double>(c)) << std::endl;
	return true;
}

bool convertInt(std::string str)
{
	int strLen = str.length();
	for (int i = 0; i < strLen; i++)
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
			continue;
		if(!isdigit(str[i]))
			return false;
	}
	int integer;
	try {
		integer = std::stoi(str);
	} catch (std::exception&) {
		std::cerr << "Integer overflow error." << std::endl;
		return true;
	}

	if (isprint(integer))
		std::cout << "char: '" << static_cast<char>(integer) << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	
	std::cout << "int: " << integer << std::endl;
	std::cout << "float: " << formatFloat(static_cast<float>(integer)) << std::endl;
	std::cout << "double: " << formatDouble(static_cast<double>(integer)) << std::endl;
	return true;
}

bool convertFloat(std::string str)
{
	bool isLeft = false;
	bool isRight = false;
	bool isDot = false;
	bool isF = false;
	int i = 0;

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

	if (!isLeft || !isDot || ! isRight || !isF)
		return false;
	

	float floatNum = std::stof(str);
	int integer = static_cast<int>(floatNum);

	if (isprint(integer))
		std::cout << "char: '" << static_cast<char>(integer) << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;

	std::cout << "int: " << integer << std::endl;
	std::cout << "float: " << formatFloat(floatNum) << std::endl;
	std::cout << "double: " << formatDouble(static_cast<double>(floatNum)) << std::endl;

	return true;
}

bool convertDouble(std::string str)
{
	// bool isLeft = false;
	// bool isRight = false;
	// bool isDot = false;
	// int i = 0;

	// while (str[i] && isdigit(str[i]))
	// {
	// 	isLeft = true;
	// 	i++;
	// }
	// if (!str[i])
	// 	return false;

	// if (str[i] && str[i] == '.')
	// {
	// 	isDot = true;
	// 	i++;
	// }
	// else
	// 	return false;

	// while (str[i] && isdigit(str[i]))
	// {
	// 	isRight = true;
	// 	i++;
	// }
	// if (!str[i])
	// 	return false;

	// if (str[i] && str[i] == 'f')
	// 	isF = true;
	
	// if (!isLeft || !isDot || ! isRight || !isF)
	// 	return false;

	// float floatNum = std::stof(str);
	// int integer = static_cast<int>(floatNum);

	// if (isprint(integer))
	// 	std::cout << "char: '" << static_cast<char>(integer) << "'" << std::endl;
	// else
	// 	std::cout << "char: " << "Non displayable" << std::endl;

	// std::cout << "int: " << integer << std::endl;
	// std::cout << "float: " << formatFloat(floatNum) << std::endl;
	// std::cout << "double: " << formatDouble(static_cast<double>(floatNum)) << std::endl;
	(void)str;
	return false;
	// return true;
}
