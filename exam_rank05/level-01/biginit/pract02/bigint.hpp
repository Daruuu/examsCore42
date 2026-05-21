#ifndef BIGINT_HPP
#define BIGINT_HPP
#include <iostream>

class bigint
{
	private:
		std::string str;
	
	public:
		bigint();
		bigint(unsigned int n);
		bigint(const bigint& other);
		bigint& operator=(const bigint& other);

		std::string getStr();

		// suma
		bigint operator+(const bigint& other) const;
		bigint& operator+=(const bigint& other);
		
		// incremento	
		bigint operator++();
		bigint& operator++(int);

		//	shift decimal
		bigint operator<<(unsigned int n) const;
		bigint operator>>(unsigned int n) const;

		bigint& operator<<=(unsigned int n);
		bigint& operator>>=(unsigned int n);

		// shift decimal objeto

		bigint operator<<(const bigint& other) const;
		bigint operator>>(const bigint& other) const;

		bigint& operator<<=(const bigint& other);
		bigint& operator>>=(const bigint& other);

		//	comparaciones
		bool operator==(const bigint& other) const;
		bool operator!=(const bigint& other) const;
		bool operator<(const bigint& other) const;
		bool operator>(const bigint& other) const;
		bool operator<=(const bigint& other) const;
		bool operator>=(const bigint& other) const;
};

std::ostream& operator<<(std::ostream& os,const bigint& obj);

#endif BIGINT_HPP
