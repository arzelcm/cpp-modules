#include <iostream>
#include <stdlib.h>
#include "Base/Base.hpp"
#include "A/A.hpp"
#include "B/B.hpp"
#include "C/C.hpp"

Base *generate(void)
{
	int i = std::rand() % 3;
	switch (i)
	{
	case 0:
		return new C();
		break;
	case 1:
		return new B();
		break;
	default:
		return new A();
		break;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base &p)
{
	try
	{
		dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
	}

	try
	{
		dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
	}

	try
	{
		dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
	}

	std::cout << "Unknown" << std::endl;
}

int main()
{
	std::srand(time(NULL));
	Base *ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;

	return 0;
}