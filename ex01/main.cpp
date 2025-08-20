#include "Data.hpp"
#include "Serializer.hpp"

int main(void)
{
	Data info;

	info.rawData = 42;

	std::cout << &info << std::endl;
	Serializer::deserialize(Serializer::serialize(&info));
	std::cout << &info << std::endl;

	return (0);
}
