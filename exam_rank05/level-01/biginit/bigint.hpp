#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class bigint {
	private:
		std::vector<unsigned char> digits_;

		void from_unsigned_long(unsigned long n);	// usado en constructor
		void normalize();	// elimina ceros a la izquierda

	public:
		//1.	rule of 3
		bigint();
		bigint(unsigned long n);
		bigint(const bigint& other);

		//	2
		bigint& operator=(const bigint& other);

		//	3
		friend std::ostream& operator<<(std::ostream& os, const bigint& b);

		// 4 ******	comparaciones basicas
		bool operator==(const bigint& other) const;
		bool operator!=(const bigint& other) const;

		bool operator<(const bigint& other) const;
		bool operator>(const bigint& other) const;

		bool operator<=(const bigint& other) const;
		bool operator>=(const bigint& other) const;

		// 5	******* suma con enteros pequenyos	
		bigint operator+(unsigned long n) const;
		bigint& operator+=(unsigned long n);

		// 6 completa entre bigints
		bigint operator+(const bigint& other) const;
		bigint& operator+=(const bigint& other);

		// 7 incremento 
		bigint& operator++();	// pre-increment
		bigint operator++(int);	// post-increment

		// 8 digit shift 
		bigint operator<<(unsigned long n) const;
		bigint& operator<<=(unsigned long n);

		//	9 digit shift derecho (divide por potencia de 10)
		//	acepta bigint porque el main hace: d >>= (bigint)2
		bigint operator>>(const bigint& other) const;
		bigint& operator>>=(const bigint& other);
}

