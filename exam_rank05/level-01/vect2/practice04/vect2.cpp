#include "vect2.hpp"

vect2::vect2(): x(0), y(0)
{
}

vect2::vect2(int x, int y) : x(x), y(y)
{
}

vect2::vect2(const vect2& other)
{
	x = other.x;
	y = other.y;
}

vect2& vect2::operator=(const vect2& other)
{
	if (this != &other)
	{
		x = other.x;
		y = other.y;
	}
	return *this;
}

//operator
int vect2::operator[](int i) const
{
	return i == 0 ? x : y;
}

int& vect2::operator[](int i)
{
	return i == 0 ? x : y;
}

vect2& vect2::operator++()// pre
{
	++x;
	++y;
	return *this;
}

vect2 vect2::operator++(int)	//post
{
	vect2 old(*this);
	++*this;
	return old;
}

vect2& vect2::operator--()
{
	--x;
	--y;
	return *this;
}

vect2 vect2::operator--(int)
{
	vect2 old(*this);
	--*this;
	return old;
}

vect2 vect2::operator+(const vect2& o) const
{
	return vect2(x + o.x, y + o.y);
}

vect2& vect2::operator+=(const vect2& o)
{
	x += o.x;
	y += o.y;
	return *this;
}

vect2 vect2::operator-(const vect2& o) const
{
	return vect2(x - o.x, y - o.y);
}

vect2& vect2::operator-=(const vect2& o)
{
	x -= o.x;
	y -= o.y;
	return *this;
}

vect2 vect2::operator-()	// negacio -4, -1
{
	return vect2(-x, -y);
}

vect2 vect2::operator*(const vect2& other) const
{
	return vect2(x * other.x, y * other.y);
}

vect2& vect2::operator*=(int scalar)
{
	x *= scalar;
	y *= scalar;
	return *this;
}
vect2 vect2::operator*(int scalar) const
{
	return vect2(x * scalar, y * scalar);
}

bool vect2::operator==(const vect2& o) const
{
	return (x == o.x && y == o.y);
}

bool vect2::operator!=(const vect2& o) const
{
	return !(*this == o);
}

vect2 operator*(int scalar, const vect2& o)
{
	return o * scalar;
}

std::ostream& operator<<(std::ostream& os, const vect2& v)
{
	return os << "{" << v[0] << ", " << v[1] << "}";
}

