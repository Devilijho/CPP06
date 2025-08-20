#include "Base.hpp"
#include <cstddef>
#include <exception>
#include <typeinfo>

Base::~Base(){}

Base* generate(void)
{
	Base *base_ptr = NULL;
	srand(time(0));
	int randomNum = rand() % 3;

	try
	{
		switch (randomNum)
		{
			case 0:
				base_ptr = new A();
				break;
			case 1:
				base_ptr = new B();
				break;
			case 2:
				base_ptr = new C();
				break;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (NULL);
	}

	return (base_ptr);
}

void identify(Base *p)
{
	A *a_ptr = dynamic_cast<A*>(p);
	B *b_ptr = dynamic_cast<B*>(p);
	C *c_ptr = dynamic_cast<C*>(p);

	if (a_ptr)
		std::cout << "Pointed class type is A" << std::endl;
	else if (b_ptr)
		std::cout << "Pointed class type is B" << std::endl;
	else if (c_ptr)
		std::cout << "Pointed class type is C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a_ptr = dynamic_cast<A&>(p);
		(void)a_ptr;
		std::cout << "Referenced class type is A" << std::endl;
	}
	catch (std::bad_cast &e)
	{
		try
		{
			B &b_ptr = dynamic_cast<B&>(p);
			(void)b_ptr;
			std::cout << "Referenced class type is B" << std::endl;
		}
		catch (std::bad_cast &e)
		{
			try
			{
				C &c_ptr = dynamic_cast<C&>(p);
				(void)c_ptr;
				std::cout << "Referenced class type is C" << std::endl;
			}
			catch (std::bad_cast &e){}
		}
	}
}
