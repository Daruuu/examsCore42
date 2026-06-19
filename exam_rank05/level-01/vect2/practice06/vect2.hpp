#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>
#include <vector>

class vect2
{
	int x_;
	int y_;
public:
	vect2();
	vect2(int x, int y);
	vect2(const vect2& other);
	vect2& operator=(const vect2& other);

	//posiiton
	int operator[](int i) const;
	int& operator[](int i);

	// aritmetica
	vect2 operator+(const vect2& other) const;
	vect2& operator+=(const vect2& other);
	vect2 operator-(const vect2& other) const;
	vect2& operator-=(const vect2& other);
	vect2 operator-() const;

	//	multiplicar
	vect2 operator*(const vect2& other) const;
	vect2 operator*(int scalar) const;
	vect2& operator*=(int scalar);

	// comparacion	
	bool operator==(const vect2& other) const;
	bool operator!=(const vect2& other) const;

	//	increment pre - post
	vect2& operator++();
	vect2 operator++(int);
	vect2& operator--();
	vect2 operator--(int);

};

vect2 operator*(int scala, const vect2& other);
std::ostream& operator<<(std::ostream& os, const vect2& v1);

#endif
