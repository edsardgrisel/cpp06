#include <iostream>
#include <string>
#include "convert_helpers.hpp"

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