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

	//	suma numero
	bigint operator+(unsigned long n) const;	
	bigint& operator+=(unsigned long n);	
	//	suma objeto 
	bigint operator+(const bigint& other) const;
	bigint& operator+=(const bigint& other);

	//	pre - post increment
	bigint& operator++();
	bigint operator++(int);
	
	//	shift izquierdo multiplica 42 << 3 = 42000
	bigint operator<<(unsigned long n) const;
	bigint& operator<<=(unsigned long n);
	//	shift derecho divide 
	bigint operator>>(const bigint& other) const;
	bigint& operator>>=(const bigint& other);

	//	bools main
	bool operator<(const bigint& other) const;
	bool operator<=(const bigint& other) const;
	bool operator>(const bigint& other) const;
	bool operator>=(const bigint& other) const;
	bool operator==(const bigint& other) const;
	bool operator!=(const bigint& other) const;
};

std::ostream& operator<<(std::ostream& os, const bigint b);

#endif
