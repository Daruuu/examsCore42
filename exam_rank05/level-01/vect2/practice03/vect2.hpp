#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2 {
	int x;
	int y;
public:
	vect2();
	vect2(int x, int y);
	vect2(const vect2& other);
	vect2& operator=(const vect2& other);
	~vect2();

	//	ACCESO A 0 Y 1
	int operator[](int i);
	int& operator[](int i) const;

	// 3 suma resta
	vect2 operator+(const vect2& other) const;
	vect2& operator+=

};

friend std::ostream& operator<<(std::ostream& os, vect2& v);
