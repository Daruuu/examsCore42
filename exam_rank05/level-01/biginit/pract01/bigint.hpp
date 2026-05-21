#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint
{
private:
	std::string str;

public:
	//	CONSTRUCTORS CANONICAL
	bigint();
	bigint(unsigned int num);
	bigint(const bigint& other);
	bigint& operator=(const bigint& other);

	//	GETTER STR
	std::string getStr() const;
	
	//	SUMA
	bigint operator+(const bigint& other) const;
	bigint& operator+=(const bigint& other);

	//	INCREMENTO	
	bigint& operator++();	// pre-incremento ++x
	bigint operator++(int);	// post-incremento x++
	 
	//	SHIFT DECIMAL << >> 	
	bigint operator<<(unsigned int n) const;	// multiply x 10^n
	bigint operator>>(unsigned int n) const;	// divide / 10^n
	
	//	SHIFT AND ASSIGN
	bigint operator<<=(unsigned int n);
	bigint operator>>=(unsigned int n);

	//	COMPARASIONES : 6
	bool operator==(const bigint& other) const;
	bool operator!=(const bigint& other) const;

	bool operator<(const bigint& other) const;
	bool operator>(const bigint& other) const;

	bool operator<=(const bigint& other) const;
	bool operator>=(const bigint& other) const;
};

std::ostream& operator<<(std::ostream& os, const bigint& obj);

#endif
