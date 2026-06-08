#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2 {
	int	x_;
	int	y_;
public:

	vect2();
	vect2(int x, int y);
	vect2(const vect2& other);
	vect2& operator=(const vect2& other);
	~vect2();

	//	acceso [0]=x , [1]=y
	int& operator[](int i);
	int operator[](int i) const;

	//	suma y resta
	vect2 operator+(const vect2& other) const;
	vect2& operator+=(const vect2& other);

	vect2 operator-(const vect2& other) const;
	vect2& operator-=(const vect2& other);

	vect2 operator-() const;	// nwgacion -v
								//
	//	MULTIPLICACION
	vect2 operator*(const vect2& other) const;	//	elemento a elemento
	vect2 operator*(int scalar) const;		//por escalar
	vect2& operator*=(int scalar);

	//	5. incremento | decremento 	
	vect2& operator++();
	vect2 operator++(int);

	vect2& operator--();
	vect2 operator--(int);

	//	6. comparacion
	bool operator==(const vect2& other) const;
	bool operator!=(const vect2& other) const;

	//	7. salida y 3 * v
	friend vect2 operator*(int scalar, const vect2& v);
	friend std::ostream& operator<<(std::ostream& os, const vect2& v);
};

