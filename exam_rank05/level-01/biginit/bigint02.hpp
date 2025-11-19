#ifndef BINGINT_HPP
#define BINGINT_HPP

#include <iostream>
#include <vector>

class Bigint
{
	Biginit();
	Biginit(unsigned long long n);
	Biginit(const bigint& other);
	Biginit &operator=(const Biginit& other);

	//	getters
	std::string getStr() const;

	//	add 	
	Biginit operator+(const Biginit& other) const;
	Biginit& operator+=(const Biginit& other);

	//	increment
	Biginit& operator++();		// ++x
	Biginit operator++(int);	// x++

	//	shift with num
	Biginit operator<<(unsigned int n) const;
	Biginit operator>>(unsigned int n) const;

	Biginit& operator<<=(unsigned int n);
	Biginit& operator>>=(unsigned int n);
	
	//	shift with objects	
	Biginit operator<<(const Biginit& other) const;
	Biginit operator>>(const Biginit& other) const;

	Biginit operator<<=(const Biginit& other)const ;
	
}

#endif
