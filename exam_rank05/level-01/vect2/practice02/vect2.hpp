#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
	int x_;
	int y_;

public:
	//	1. OCF
	vect2();
	vect2(int x, int y);
	vect2(const vect2& other);
	vect2& operator=(const vect2& other);
	~vect2();

	//	2.	sobrecarga  posicion
	int& operator[](int i);
	int operator[](int i) const;

	//	3.	suma y resta	
	vect2 operator+(const vect2& other) const;
	vect2& operator+=(const vect2& other);

	vect2 operator-(const vect2& other) const;
	vect2& operator-=(const vect2& other);

	vect2 operator-() const;

	//	4. MULTILICACION 
	vect2 operator*(const vect2& other) const;
	vect2 operator*(int scalar) const;
	vect2& operator*=(int scalar);

	// 5 incremento / decremento
	vect2& operator++();
	vect2 operator++(int);

	vect2& operator--();
	vect2 operator--(int);
	
	//	 comparaciones
	bool operator==(const vect2& other) const;
	bool operator!=(const vect2& other) const;
};

vect2 operator*(int scalar, const vect2& other);
std::ostream& operator<<(std::ostream& os, const vect2& v);
#endif 
