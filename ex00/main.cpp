#include "ScalarConverter.hpp"

int	main(int ac, char **argv)
{
	(void)argv;
	(void)ac;
	// if (ac != 2)
	// 	return (1);
	ScalarConverter::convert("0");
	std::cout << "--------------------------------" << std::endl;
	ScalarConverter::convert("nan");
	std::cout << "--------------------------------" << std::endl;
	ScalarConverter::convert("42.0f");

	// ScalarConverter::convert(argv[1]);
	return (0);
}
