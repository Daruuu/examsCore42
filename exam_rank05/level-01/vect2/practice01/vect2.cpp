#include "vect2.hpp"

vect2::vect2() : x_(0), y_(0)
{}

vect2::vect2(int x, int y) : x_(x), y_(y)
{}

vect2::vect2(const vect2& other)
{
	x_ = other.x_;
	y_ = other.y_;
}

vect2& vect2::operator=(const vect2& other)
{
	if (this != &other)
	{
		x_ = other.x_;
		y_ = other.y_;
	}
	return *this;
}

vect2::~vect2()
{}

	//	acceso [0]=x , [1]=y
int& vect2::operator[](int i)
{
	return i == 0 ? x_ : y_;
}

int vect2::operator[](int i) const
{
	return i == 0 ? x_ : y_;
}

//	suma y resta
vect2 vect2::operator+(const vect2& other) const
{
	return vect2(x_ + other.x_, y_ + other.y_);
}

vect2& vect2::operator+=(const vect2& other)
{

}

vect2 vect2::operator-(const vect2& other) const
{

}
vect2& vect2::operator-=(const vect2& other)
{

}

vect2 vect2::operator-() const	// nwgacion -v
{

}
