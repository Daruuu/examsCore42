#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint
{
private:
	std::string str;

public:
	bigint();
	bigint(unsigned int num);
	bigint(const bigint& source);
	bigint& operator=(const bigint& source);

	std::string getStr() const;

	// addition
	bigint operator+(const bigint& other) const;
	bigint& operator+=(const bigint& other);

	// increments
	bigint& operator++();
	bigint operator++(int);

	// shift with number
	bigint operator<<(unsigned int n) const;
	bigint operator>>(unsigned int n) const;
	bigint& operator<<=(unsigned int n);
	bigint& operator>>=(unsigned int n);

	// shift with bigint
	bigint operator<<(const bigint& other) const;
	bigint operator>>(const bigint& other) const;
	bigint& operator<<=(const bigint& other);
	bigint& operator>>=(const bigint& other);

	// comparisons
	bool operator==(const bigint& other) const;
	bool operator!=(const bigint& other) const;
	bool operator<(const bigint& other) const;
	bool operator>(const bigint& other) const;
	bool operator<=(const bigint& other) const;
	bool operator>=(const bigint& other) const;
};

std::ostream& operator<<(std::ostream& os, const bigint& obj);

#endif