#include <cstdint>

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP


struct Data {
	int numberA = 1;
	int numberB = 2;
};

class Serializer
{
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);


private:
	Serializer();
	Serializer(const Serializer& other);
	Serializer& operator=(const Serializer& other);
	~Serializer();
};

#endif // SERIALIZER_HPP