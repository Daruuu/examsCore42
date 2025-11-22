#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <algorithm>
#include <vector>

/*
 * Clase bigint: Representa un entero sin signo de precisión arbitraria
 * 
 * Los dígitos se almacenan en orden INVERSO en el vector:
 * - El número 1337 se guarda como [7, 3, 3, 1]
 * - Esto facilita las operaciones matemáticas (suma, shift, etc.)
 */
class bigint {
	private:
		// Vector que almacena los dígitos en orden inverso (0-9)
		std::vector<unsigned char> digits_;

		// Convierte un unsigned long a bigint (usado en constructores)
		void from_unsigned_long(unsigned long n);
		
		// Elimina ceros a la izquierda (ej: 00042 -> 42)
		// Importante: siempre deja al menos un dígito (0)
		void normalize();

	public:
		// ============ CONSTRUCTORES Y DESTRUCTOR (Rule of 3) ============
		
		// Constructor por defecto: crea bigint con valor 0
		bigint();
		
		// Constructor desde unsigned long: convierte número normal a bigint
		bigint(unsigned long n);
		
		// Constructor de copia: crea una copia exacta de otro bigint
		bigint(const bigint& other);

		// ============ OPERADOR DE ASIGNACIÓN ============
		
		// Asigna el valor de otro bigint a este
		// Retorna referencia para permitir encadenamiento: a = b = c
		bigint& operator=(const bigint& other);

		// ============ SALIDA POR STREAM ============
		
		// Permite imprimir el bigint con std::cout << bigint
		// Imprime en base 10 sin ceros a la izquierda
		friend std::ostream& operator<<(std::ostream& os, const bigint& b);

		// ============ OPERADORES DE COMPARACIÓN ============
		
		// Compara si dos bigints son iguales
		bool operator==(const bigint& other) const;
		
		// Compara si dos bigints son diferentes
		bool operator!=(const bigint& other) const;

		// Compara si este bigint es menor que otro
		// Primero compara tamaño, luego dígito por dígito
		bool operator<(const bigint& other) const;
		
		// Compara si este bigint es mayor que otro
		bool operator>(const bigint& other) const;

		// Compara si este bigint es menor o igual que otro
		bool operator<=(const bigint& other) const;
		
		// Compara si este bigint es mayor o igual que otro
		bool operator>=(const bigint& other) const;

		// ============ OPERADORES DE SUMA ============
		
		// Suma un unsigned long a este bigint (crea nuevo bigint)
		// Ejemplo: bigint(10) + 5 = bigint(15)
		bigint operator+(unsigned long n) const;
		
		// Suma y asigna un unsigned long a este bigint
		// Ejemplo: a += 5 modifica a directamente
		bigint& operator+=(unsigned long n);

		// Suma dos bigints (crea nuevo bigint con el resultado)
		// Usa algoritmo de suma con acarreo (carry)
		bigint operator+(const bigint& other) const;
		
		// Suma y asigna otro bigint a este
		bigint& operator+=(const bigint& other);

		// ============ OPERADORES DE INCREMENTO ============
		
		// Pre-incremento: ++a (incrementa y retorna el nuevo valor)
		bigint& operator++();
		
		// Post-incremento: a++ (retorna valor anterior, luego incrementa)
		bigint operator++(int);

		// ============ OPERADORES DE DIGIT SHIFT (IZQUIERDA) ============
		
		// Shift izquierdo: multiplica por 10^n
		// Ejemplo: 42 << 3 = 42000 (añade 3 ceros a la derecha)
		bigint operator<<(unsigned long n) const;
		
		// Shift izquierdo con asignación
		bigint& operator<<=(unsigned long n);

		// ============ OPERADORES DE DIGIT SHIFT (DERECHA) ============
		
		// Shift derecho: divide por 10^n (elimina n dígitos de la derecha)
		// Ejemplo: 1337 >> 2 = 13 (elimina 2 dígitos)
		// Acepta bigint porque el main hace: d >>= (const bigint)2
		bigint operator>>(const bigint& other) const;
		
		// Shift derecho con asignación
		bigint& operator>>=(const bigint& other);
};

#endif
