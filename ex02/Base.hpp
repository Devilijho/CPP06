#pragma once

#include <ctime>
#include <random>
#include <iostream>

class A;
class B;
class C;

class Base
{
	public:
		virtual ~Base();
};

Base* generate(void);
void identify(Base *p);
void identify(Base &p);

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
