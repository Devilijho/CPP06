#include "ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <string>

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other){UNUSED(other);}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){UNUSED(other);return (*this);}

void ScalarConverter::convert(std::string type)
{
	char	charConverted = atoi(type.c_str());
	int		intConverted = atoi(type.c_str());
	bool isPossibleChar = true;

	for (unsigned long i = 0; i < type.length(); i++)
	{
		if (std::isdigit(type[i]) == false)
		{
			isPossibleChar = false;
			break;
		}
	}
	if (isPossibleChar)
		std::cout << "char: " << "Impossible" << std::endl;
	else if (charConverted < 32 || charConverted > 127)
		std::cout << "char: " << "Non displayable" << std::endl;
	else
		std::cout << "char: '" << charConverted << "'" << std::endl;

	// if (isPossibleInt)
	std::cout << "int: " << intConverted << std::endl;
	// else
	// std::cout << "char: " << "Impossible" << std::endl;


	std::cout << "float: " << std::stof(type) << "f" << std::endl;
	std::cout << "double: " << std::stof(type) << "" <<std::endl;
}
