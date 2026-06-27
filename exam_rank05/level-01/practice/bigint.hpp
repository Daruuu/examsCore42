#include <iostream>
#include <vector>

class bigint
{
	std::vector<unsigned char> digits_;
	void from_ulong(unsigned long n);
	void normalize();

public:
	bigint();
	bigint(unsigned long n);
	bigint(const bigint& other);
	bigint& operator=(const bigint& other);

	bigint operator+(unsigned long n) const;
	bigint& operator+=(unsigned long n);
	bigint operator+(const bigint& other) const;
	bigint& operator+(const bigint& other);
	
	bigint& operator++();
	bigint operator++(int);

	//	shift izquierda multiplica
	bigint operator<<(unsigned long n) const;
	bigint& operator<<=(unsigned long n);

	//	shift derecha divide
	bigint operator>>(const bigint& other) const;
	bigint& operator>>=(const bigint& other);

	//	bools
	bool operator<(const bigint& other) const;
	bool operator<=(const bigint& other) const;
	bool operator>(const bigint& other) const;
	bool operator>=(const bigint& other) const;
	bool operator==(const bigint& other) const;
	bool operator!=(const bigint& other) const;

};

std::ostream& operator<<(std::ostream& os, const bigint& b);
