#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>

class bigint
{
private:
	std::string str; // guarda el número como string

public:

	/* ===== CONSTRUCTORES ===== */

	bigint();                       // crea bigint = 0
	bigint(unsigned int num);      // convierte int -> string
	bigint(const bigint& source);  // copy constructor
	bigint& operator=(const bigint& source); // asignación


	/* ===== GETTER ===== */

	std::string getStr() const;    // devuelve el string interno


	/* ===== OPERADORES DE SUMA ===== */

	bigint operator+(const bigint& other) const; // suma dos bigint
	bigint& operator+=(const bigint& other);     // suma y asigna


	/* ===== INCREMENTOS ===== */

	bigint& operator++();   // prefijo ++x
	bigint operator++(int); // postfijo x++


	/* ===== SHIFT DECIMAL ===== */

	bigint operator<<(unsigned int n) const; // multiplica por 10^n
	bigint operator>>(unsigned int n) const; // divide por 10^n

	bigint& operator<<=(unsigned int n); // shift y asigna
	bigint& operator>>=(unsigned int n);

	// shift usando bigint
	bigint operator<<(const bigint& other) const;
	bigint operator>>(const bigint& other) const;

	bigint& operator<<=(const bigint& other);
	bigint& operator>>=(const bigint& other);


	/* ===== COMPARACIONES ===== */

	bool operator==(const bigint& other) const;
	bool operator!=(const bigint& other) const;
	bool operator<(const bigint& other) const;
	bool operator>(const bigint& other) const;
	bool operator<=(const bigint& other) const;
	bool operator>=(const bigint& other) const;
};


/* ===== OUTPUT ===== */

std::ostream& operator<<(std::ostream& os, const bigint& obj);

#endif