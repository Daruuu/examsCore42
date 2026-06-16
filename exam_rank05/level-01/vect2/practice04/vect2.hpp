#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>
#include <vector>

class vect2{
	int x;
	int y;
public:
	vect2();
	vect2(int x, int y);
	vect2(const vect2& other);
	vect2& operator=(const vect2& other);

	//operator
	int operator[](int i) const;
	int& operator[](int i);

	vect2& operator++();	// pre
	vect2 operator++(int);	//post
	vect2& operator--();
	vect2 operator--(int);
	
	vect2 operator+(const vect2& o) const;
	vect2& operator+=(const vect2& o);
	vect2 operator-(const vect2& o) const;
	vect2& operator-=(const vect2& o);
	vect2 operator-();	// negacio -4, -1

	vect2 operator*(const vect2& other) const;
	vect2& operator*=(int scalar);
	vect2 operator*(int scalar) const;

	bool operator==(const vect2& o) const;
	bool operator!=(const vect2& o) const;
};

vect2 operator*(int scalar, const vect2& o);
std::ostream& operator<<(std::ostream& os, const vect2& v);

#endif
