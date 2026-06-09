#include "vect2.hpp"

vect2::vect2() : x_(0), y_(0){}

vect2::vect2(int x, int y) : x_(x), y_(y){}

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

//	 2 : sobrecarga
int& vect2::operator[](int i)
{
	return i == 0 ? x_ : y_;
}

int vect2::operator[](int i) const
{
	return i == 0 ? x_ : y_;
}

//	3.	suma y resta

vect2 vect2::operator+(const vect2& other) const
{
	return vect2(x_ + other.x_, y_ + other.y_);
}

vect2& vect2::operator+=(const vect2& other)
{
	x_ += other.x_;
	y_ += other.y_;
	return *this;
}

vect2 vect2::operator-(const vect2& other) const
{
	return vect2(x_ - other.x_, y_ - other.y_);
}

vect2& vect2::operator-=(const vect2& other)
{
	x_ -= other.x_;
	y_ -= other.y_;
	return *this;
}

vect2 vect2::operator-() const
{
	return vect2(-x_, -y_);
}

//	4. MULTIPLICACION
vect2 vect2::operator*(const vect2& other) const
{
	return vect2(x_ * other.x_, y_ * other.y_);
}

vect2 vect2::operator*(int scalar) const
{
	return vect2(x_ * scalar, y_ * scalar);
}

vect2& vect2::operator*=(int scalar)
{
	x_ *= scalar;
	y_ *= scalar;
	return *this;
}

//	5. incremento / decremento
vect2& vect2::operator++()
{
	++x_;
	++y_;
	return *this;
}

vect2 vect2::operator++(int)
{
	vect2 old(*this);
	++*this;
	return old;
}

vect2& vect2::operator--()
{
	--x_;
	--y_;
	return *this;
}

vect2 vect2::operator--(int)
{
	vect2 old(*this);
	--x_;
	--y_;
	return old;
}

bool vect2::operator==(const vect2& other) const
{
	return (x_ == other.x_ && y_ == other.y_);
}

bool vect2::operator!=(const vect2& other) const
{
	return !(*this == other);
}

vect2 operator*(int scalar, const vect2& other)
{
	return other * scalar;
}

std::ostream& operator<<(std::ostream& os, const vect2& v)
{
	return os << "{" << v[0] << ", " << v[1] << "}";
}
