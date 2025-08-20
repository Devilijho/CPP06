#include "Serializer.hpp"
#include "Data.hpp"
#include <cstddef>

Serializer::Serializer(){}

Serializer::~Serializer(){}

Serializer::Serializer(const Serializer &other){(void)(other);}

Serializer &Serializer::operator=(const Serializer &other){(void)(other);return (*this);}

uintptr_t Serializer::serialize(Data *ptr)
{
	uintptr_t data_ptr;

	if (ptr == NULL)
		return 0x0;
	data_ptr = reinterpret_cast<uintptr_t>(ptr);

	return data_ptr;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data *info_ptr;

	info_ptr = reinterpret_cast<Data *>(raw);

	return (info_ptr);
}
