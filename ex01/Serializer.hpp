#pragma once

#include <cstdint>
#include <string>
#include <iostream>
#include "Data.hpp"

class Serializer
{
	public:
		~Serializer();
		Serializer(const Serializer &other);
		Serializer &operator=(const Serializer &other);

		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);
	protected:
		Serializer();
};
