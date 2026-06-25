#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2
{
	int x_;
	int y_;
public:
	//	OCF
	vect2();
	vect2(int x, int y);
	vect2(const vect2& other);
	vect2& operator=(const vect2& other);

	//	overload
	int operator[](int i) const;
	int& operator[](int i);

	//	suma y resta
	vect2 operator+(const vect2& other) const;
	vect2& operator+=(const vect2& other);
	vect2 operator-(const vect2& other) const;
	vect2& operator-=(const vect2& other);
	vect2 operator-() const;

	// multiplicar
	vect2 operator*(const vect2& other) const;
	vect2 operator*(int scalar) const;
	vect2& operator*=(int scalar);
	
	//	increment - decremento
	vect2& operator++();
	vect2 operator++(int);
	vect2& operator--();
	vect2 operator--(int);

	//	bools
	bool operator==(const vect2& other) const;
	bool operator!=(const vect2& other) const;
};

vect2 operator*(int scalar, const vect2& v);
std::ostream& operator<<(std::ostream& os, const vect2& v1);

#endif
