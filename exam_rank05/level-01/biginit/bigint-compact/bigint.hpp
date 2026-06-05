#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <vector>

class bigint {
	std::vector<unsigned char> digits_;

	void from_ulong(unsigned long n);
	void normalize();

public:
	bigint();
	bigint(unsigned long n);
	bigint(const bigint& other);
	bigint& operator=(const bigint& other);

	friend std::ostream& operator<<(std::ostream& os, const bigint& b);

	bool operator==(const bigint& other) const;
	bool operator!=(const bigint& other) const;
	bool operator<(const bigint& other) const;
	bool operator>(const bigint& other) const;
	bool operator<=(const bigint& other) const;
	bool operator>=(const bigint& other) const;

	bigint operator+(const bigint& other) const;
	bigint operator+(unsigned long n) const;

	bigint& operator+=(const bigint& other);
	bigint& operator+=(unsigned long n);

	bigint& operator++();
	bigint operator++(int);

	bigint operator<<(unsigned long n) const;
	bigint& operator<<=(unsigned long n);
	bigint operator>>(const bigint& other) const;
	bigint& operator>>=(const bigint& other);
};

#endif
