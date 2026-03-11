#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "Please provide 1 arg" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
