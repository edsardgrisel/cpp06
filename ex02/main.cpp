#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <chrono>
#include <random>
#include <iostream>

Base* generate(void)
{
	Base* result = nullptr;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::minstd_rand0 generator (seed);
	int type = generator() % 3;

	if (type == 0)
		result = new A();
	else if (type == 1)
		result = new B();
	else if (type == 2)
		result = new C();
	return result;
}


void identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	if (a)
	{
		std::cout << "A" << std::endl;
		return;
	}

	B* b = dynamic_cast<B*>(p);
	if (b)
	{
		std::cout << "B" << std::endl;
		return;
	}

	C* c = dynamic_cast<C*>(p);
	if (c)
	{
		std::cout << "C" << std::endl;
		return;
	}
}

void identify(Base& p)
{
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;

	} catch (std::exception) {}


	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	} catch (std::exception) {}


	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	} catch (std::exception) {}

}

int main()
{
	Base* base;

	for(int i = 0; i < 5; i++)
	{
		std::cout << "iteration " << i << std::endl;
		base = generate();
		std::cout << "Identify with pointer ";
		identify(base);
		std::cout << "Identify with reference ";
		identify(*base);
		std::cout << std::endl;
		delete base;
	}


	return 0;
}
