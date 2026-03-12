#include <string>
#include <iostream>
#include "convert_helpers.hpp"

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