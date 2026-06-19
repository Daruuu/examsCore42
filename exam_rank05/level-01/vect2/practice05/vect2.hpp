#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2{
	int x_;
	int y_;

public:
	//	ocr
	vect2();
	vect2(int x, int y);
	vect2(const vect2& other);
	vect2& operator=(const vect2& other);

	//	operator
	int& operator[](int i);
	int operator[](int i) const;

	//	aritmeticos
	vect2 operator+(const vect2& other) const;
	vect2& operator+=(const vect2& other);
	vect2 operator-(const vect2& other) const;
	vect2& operator-=(const vect2& other);
	vect2 operator-() const;

	//	multiplicacion
	vect2 operator*(const vect2& other) const;
	vect2 operator*(int scalar) const;
	vect2& operator*=(int scalar);

	//incremento
	vect2& operator++();
	vect2 operator++(int);
	vect2& operator--();
	vect2 operator--(int);

	bool operator==(const vect2& other) const;	
	bool operator!=(const vect2& other) const;	

};
vect2 operator*(int scalar,const vect2& other);
std::ostream& operator<<(std::ostream& os, const vect2& v1);
#endif
