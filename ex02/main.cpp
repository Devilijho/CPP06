#include "Base.hpp"

int main(void)
{
	{
		Base *ptr = generate();
		identify(ptr);

		Base *ptrrr = new A();
		identify(ptrrr);

		delete ptrrr;
	}
	{
		Base *ptr = generate();
		Base &ref = *ptr;
		identify(ref);

		Base *ptrrr = new A();
		Base &refff = *ptrrr;
		identify(refff);
	}
	{
		identify(NULL);
	}
	return (0);
}
