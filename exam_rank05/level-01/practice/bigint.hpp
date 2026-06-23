#ifndef BIGINT_HPP
#define BIGINT_HPP
#include <iostream>
#include <vector>

class bigint
{
	std::vector<unsigned char> digits_;
	void from_ulong(unsigned long n);
	void normalize();

public:
	//	OCF
	bigint();
	bigint(unsigned long n);
	bigint(const bigint& other);
	bigint& operator=(const bigint& other);

	//	+ - objecto numero
	bigint operator+(const bigint& other) const;
	bigint& operator+=(const bigint& other);

	bigint operator+(unsigned long n) const;
	bigint& operator+=(unsigned long n);

	//	pre post increment
	bigint& operator++();
	bigint operator++(int);

	//	bool
	bool operator<(const bigint& other) const;
	bool operator<=(const bigint& other) const;
	bool operator>(const bigint& other) const;
	bool operator>=(const bigint& other) const;
	bool operator==(const bigint& other) const;
	bool operator!=(const bigint& other) const;

	//	shift << >>
	bigint operator<<(unsigned long n) const;
	bigint& operator<<=(unsigned long n);
	bigint operator>>(const bigint& other) const; 
	bigint& operator>>(const bigint& other); 

};
std::ostream& operator<<(std::ostream& os, const bigint& b);
#endif
