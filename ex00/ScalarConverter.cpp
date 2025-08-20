#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter &other){UNUSED(other);}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){UNUSED(other);return (*this);}

void ScalarConverter::convert(std::string input) {
	char c = 0;
	int i = 0;
	float f = 0.0f;
	double d = 0.0;
	bool charOk = true, intOk = true, floatOk = true, doubleOk = true;

	if (input == "nan" || input == "nanf") {
		charOk = intOk = false;
		f = 0.0f / 0.0f;
		d = 0.0 / 0.0;
	}
	else if (input == "+inf" || input == "+inff" || input == "inf" || input == "inff") {
		charOk = intOk = false;
		f = 1.0f / 0.0f;
		d = 1.0 / 0.0;
	}
	else if (input == "-inf" || input == "-inff") {
		charOk = intOk = false;
		f = -1.0f / 0.0f;
		d = -1.0 / 0.0;
	}
	else if (input.length() == 1 && !isdigit(input[0])) {
		c = input[0];
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);
	}
	else {
		char *end;
		d = strtod(input.c_str(), &end);

		if (*end && *end != 'f') {
			charOk = intOk = floatOk = doubleOk = false;
		} else {
			f = static_cast<float>(d);
			if (d >= (static_cast<double>(INT_MIN)) && d <= static_cast<double>(INT_MAX)) {
				i = static_cast<int>(d);
				if (i >= 0 && i <= 127)
					c = static_cast<char>(i);
				else
					charOk = false;
			} else {
				intOk = charOk = false;
			}
		}
	}

	if (!charOk)
		std::cout << "char: impossible" << std::endl;
	else if (c < 32 || c > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;

	if (!intOk)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;

	if (!floatOk)
		std::cout << "float: impossible" << std::endl;
	else if (isnan(f))
		std::cout << "float: nanf" << std::endl;
	else if (isinf(f))
		std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << std::endl;
	else {
		std::cout << "float: " << f;
		if (f == static_cast<int>(f))
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}

	if (!doubleOk)
		std::cout << "double: impossible" << std::endl;
	else if (isnan(d))
		std::cout << "double: nan" << std::endl;
	else if (isinf(d))
		std::cout << "double: " << (d > 0 ? "+inf" : "-inf") << std::endl;
	else {
		std::cout << "double: " << d;
		if (d == static_cast<int>(d))
			std::cout << ".0";
		std::cout << std::endl;
	}
}
