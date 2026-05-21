#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <vector>
#include <iostream>

class bigint {
public:
    // Constructores
    bigint();                          // por defecto = 0
    explicit bigint(unsigned long n);  // desde entero sin signo
    bigint(const bigint& other);       // copia

    // Asignación
    bigint& operator=(const bigint& other);

	// Nuevas sobrecargas para sumar con enteros pequeños
    bigint operator+(unsigned long n) const;
    bigint& operator+=(unsigned long n);

    // Operadores aritméticos
    bigint operator+(const bigint& other) const;
    bigint& operator+=(const bigint& other);
    bigint& operator++();             // pre-incremento
    bigint  operator++(int);          // post-incremento

    // Digit shifts (base 10)
    bigint operator<<(unsigned long n) const;
    bigint& operator<<=(unsigned long n);
    bigint operator>>(const bigint& n) const;  // acepta bigint como pide el main
    bigint& operator>>=(const bigint& n);

    // Comparaciones
    bool operator==(const bigint& other) const;
    bool operator!=(const bigint& other) const;
    bool operator<(const bigint& other) const;
    bool operator<=(const bigint& other) const;
    bool operator>(const bigint& other) const;
    bool operator>=(const bigint& other) const;

    // Para impresión
    friend std::ostream& operator<<(std::ostream& os, const bigint& b);

private:
    std::vector<unsigned char> digits_;   // dígitos en base 10, little-endian

    void normalize();                    // elimina ceros a la izquierda
    void from_unsigned_long(unsigned long n);
};

#endif
