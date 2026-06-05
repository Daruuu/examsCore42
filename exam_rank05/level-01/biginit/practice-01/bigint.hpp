#ifndef bigint
#define bigint

#include <iostream>
#include <vector>

class Bigint {
	std::vector<unsigned char> digits_;

	void from_unsigned_long(unsigned long n);
	void normalize();
public:
	Bigint();
	Bigint(unsigned long n);
	Bigint(const Bigint& other);
	Bigint& operator=(const Bigint& other);
	~Bigint();

	friend std::ostream& operator<<(std::ostream& os, const Bigint& b);

	bool operator==(const Bigint& other) const;
	bool operator<(const Bigint& other) const;

	bool operator>(const Bigint& other) const;

	bool operator<=(const Bigint& other) const;
	bool operator>=(const Bigint& other) const;

	bool operator!=(const Bigint& other) const;

	//	
	Bigint operator+(const Bigint& other) const;
	Bigint& operator+=(const Bigint& other);

	Bigint& operator++();
	Bigint operator++(int);
};

#endif 
