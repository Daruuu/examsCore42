#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <vector>

class bigint {
	std::vector<unsigned char> digits_;
	void from_ulong(unsigned long n);
	void normalize();

public:
	const std::vector<unsigned char>& getStr() const;

	bigint();
	bigint(unsigned long n);
	bigint(const bigint& other);
	bigint& operator=(const bigint& other);

	//	suma
	bigint operator+(const bigint& other) const;
	bigint& operator+=(const bigint& other);
	bigint operator+(unsigned long n) const;
	bigint& operator+=(unsigned long n);

	bigint& operator++();
	bigint operator++(int);

	//	true false
	bool operator<(const bigint& other) const;
	bool operator<=(const bigint& other) const;
	bool operator>(const bigint& other) const;
	bool operator>=(const bigint& other) const;
	bool operator==(const bigint& other) const;
	bool operator!=(const bigint& other) const;

	//	numero
	bigint operator<<(unsigned long n) const;
	bigint& operator<<=(unsigned long n);
	//	objeto
	bigint operator>>(const bigint& other) const;
	bigint& operator>>=(const bigint& other);

};

std::ostream& operator<<(std::ostream& os, const bigint& b);
#endif
