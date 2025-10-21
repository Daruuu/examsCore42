#include "bigint01.hpp"

bigint();
bigint(unsigned long long n);
bigint(const bigint& other);
bigint& operator=(const bigint& other);

std::string getStr() const;

//	add
bigint operator+(const bigint& other)const ;
bigint& operator+=(const bigint& other);

//	increment
bigint& operator++();	//	++x;
bigint operator++(int);	//	x++

//	shift with num
bigint operator<<(unsigned int n) const;
bigint operator>>(unsigned int n) const;

bigint& operator<<=(unsigned int n);
bigint& operator>>=(unsigned int n);

//	shift with object
bigint operator<<(const bigint& other)const;
bigint operator>>(const bigint& other)const;

bigint operator<<=(const bigint& other)const;
bigint operator>>=(const bigint& other)const;

bool operator==(const bigint& other) const;
bool operator!=(const bigint& other) const;
bool operator<(const bigint& other) const;
bool operator>(const bigint& other) const;
bool operator<=(const bigint& other) const;
bool operator>=(const bigint& other) const;

std::ostream& operator<<(std::ostream& output, const bigint& obj);


