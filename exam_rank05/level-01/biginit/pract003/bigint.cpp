#include "bigint.hpp"
#include <sstream>

//	canonical
bigint::bigint() : str("0")
{
}

bigint::bigint(unsigned int n)
{
	std::stringstream ss;
	ss << n;
	str = ss.str();
}

bigint::bigint(const bigint& other)
{
	*this = other;
}

bigint& bigint::operator=(const bigint& other)
{
	if (this != &other)
		str = other.str;
	return *this;
}

std::string bigint::getstr()
{
}

//	aritmetica 
bigint operator+(const bigint& other) const
{
}
bigint& operator+=(const bigint& other)
{
}

//	incremento
bigint& operator++()
{
}
bigint operator++(int)
{
}
