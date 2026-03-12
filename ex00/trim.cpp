#include <iostream>
#include <string>

std::string trim(const std::string& str)
{
	size_t first = str.find_first_not_of(" \t\n\r");
	if (std::string::npos == first)
		return "";
	size_t last = str.find_last_not_of(" \t\n\r");
	return str.substr(first, (last - first + 1));
}
