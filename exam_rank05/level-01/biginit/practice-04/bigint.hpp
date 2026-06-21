#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint
{
	std::string str;

	//	canonical
	bigint();
	bigint(unsigned int n);
	bigint(const bigint& other);
	bigint& operator=(const bigint& other);

	std::string getstr();

	//	aritmetica 
	bigint operator+(const bigint& other) const;
	bigint& operator+=(const bigint& other);

	//	incremento
	bigint& operator++();
	bigint operator++(int);
}
#endif BIGINT_HPP
