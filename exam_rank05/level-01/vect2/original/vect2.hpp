#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

/*
 * vect2: vector 2D de enteros (x, y)
 *
 * Orden recomendado en el examen:
 *   1. OCF          2. []     3. + - (y += -= -unario)
 *   4. * (×2 tipos) 5. ++ --  6. == !=  7. << y friend 3*v
 */
class vect2 {
	int x_;
	int y_;

public:
	// --- 1. OCF (Orthodox Canonical Form) ---
	vect2();                          // (0, 0)
	vect2(int x, int y);              // (x, y)
	vect2(const vect2& other);        // copia
	vect2& operator=(const vect2& other);
	~vect2();

	// --- 2. Acceso [0]=x, [1]=y ---
	int& operator[](int i);
	int operator[](int i) const;

	// --- 3. Suma y resta ---
	vect2 operator+(const vect2& other) const;
	vect2& operator+=(const vect2& other);
	vect2 operator-(const vect2& other) const;
	vect2& operator-=(const vect2& other);
	vect2 operator-() const;          // negación: -v

	// --- 4. Multiplicación ---
	vect2 operator*(const vect2& other) const;  // elemento a elemento
	vect2 operator*(int scalar) const;          // por escalar
	vect2& operator*=(int scalar);

	// --- 5. Incremento / decremento (+1 a x e y) ---
	vect2& operator++();              // pre:  ++v
	vect2 operator++(int);            // post: v++
	vect2& operator--();              // pre:  --v
	vect2 operator--(int);            // post: v--

	// --- 6. Comparación ---
	bool operator==(const vect2& other) const;
	bool operator!=(const vect2& other) const;

	// --- 7. Salida y 3 * v ---
	friend vect2 operator*(int scalar, const vect2& v);
	friend std::ostream& operator<<(std::ostream& os, const vect2& v);
};

#endif
