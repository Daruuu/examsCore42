#ifndef VECT2_HPP
#define VECT2_HPP
#include <iosfwd>

class  vect2
{
	int x_;
	int y_;
public:
	vect2();
	vect2(int x, int y);
	vect2(const vect2& other);
	vect2& operator=(const vect2& other);
	~vect2();

	friend std::ostream& operator<<(std::ostream& os, const vect2& v1)
	{
		return os << "v1: " << "{" << v1[0] << ", " << v1[1] << "}";
	}

	int& operator[](int i) const
	{
		return i == 0 ? x_: y_;
	}

	int operator[](int i)
	{
		return i == 0 ? x_ : y_;
	}

	vect2 operator+(const vect2& other) const
	{
		return vect2(x_ + other.x_, y_ + other.y_);
	}
	vect2& operator+=(const vect2& other)
	{
		x_ += other.x_;
		y_ += other.y_;
		return *this;
	}

	vect2 operator-(const vect2& other) const
	{
		return vect2(x_ - other.y_, y_ - other.y_);
	}

	vect2& operator-=(const vect2& other)
	{
		x_ -= other.x_;
		y_ -= other.y_;
		return *this;
	}

	vect2 operator-() const
	{
		return vect2(-x, -y_);
	}

	vect2 operator*(const vect2& other) const;
	vect2& operator*=(int scalar);

};

#endif
