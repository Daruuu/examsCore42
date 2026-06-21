#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>
class vect2 {
	int x_;
	int y_;

	vect2();
	vect2(int x, int y);
	vect2(const vect2& other);
	vect2& operator=(const vect2& other);

	vect2 operator+(const vect2& other) const;
	vect2& operator+=(const vect2& other);

	vect2 operator-(const vect2& other) const;
	vect2 operator-=(const vect2& other);
	vect2 operator-();

};
std::ostream& operator<<(std::ostream& os, const vect2& v1);
#endif
