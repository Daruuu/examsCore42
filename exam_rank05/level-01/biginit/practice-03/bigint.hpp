#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <vector>
#include <iostream>

bigint {
	std::vector<unsigned char> digits_;
	void from_ulong(unsigned long n);
	void normalize();
public:
	//	
	bigint();
	bigint(unsigned long n);
	bigint(const bigint& other);
	bigint& operator=(const bigint& other);

	bigint operator+(const bigint& other) const;
	bigint& operator+=(const bigint& other);
	bigint operator+(unsigned long n) const;
	bigint& operator+=(unsigned long n);

	bigint& operator++();
	bigint operator++(int);

	bool operator<(const bigint& other) const;	// implement
	bool operator<=(const bigint& other) const;
	bool operator>(const bigint& other) const;
	bool operator>=(const bigint& other) const;
	bool operator==(const bigint& other) const;// implement
	bool operator!=(const bigint& other) const;

	bigint operator<<(unsigned long n) const;
	bigint& operator<<=(unsigned long n);

	bigint operator>>(const bigint& other) const;
	bigint& operator>>=(const bigint& other);

};
std::ostream& operator<<(std::ostream&T os, const bigint b);

#endif
