#pragma once

#include <string>
#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cmath>

#define UNUSED(expr) do { (void)(expr); } while (0)

class ScalarConverter
{
	public:
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);

		static void	convert(std::string type);
	protected:
		ScalarConverter();
};
