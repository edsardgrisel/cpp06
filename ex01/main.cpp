#include "Serializer.hpp"
#include <iostream>

void printData(Data* data)
{
	std::cout << "a: " << data->numberA << ", b: " << data->numberB << std::endl;
}

int main()
{
	Data* data = new Data();
	printData(data);
	uintptr_t dataPtr = Serializer::serialize(data);
	std::cout << "data pointer value: " << std::hex << data << std::endl;
	std::cout << "dataPtr value: " << std::hex << dataPtr << std::endl;
	printData(Serializer::deserialize(dataPtr));
	delete data;
	return 0;
}
