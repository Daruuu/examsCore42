#include "bigint.hpp"

Bigint::Bigint()
{
	digits_.push_back(0);
}

Bigint::~Bigint()
{
}

void Bigint::from_unsigned_long(unsigned long n)
{
	if (n == 0)
	{
		digits_.push_back(0);
		return;
	}
	while (n > 0)
	{
		digits_.push_back(static_cast<unsigned char>(n % 10));
		n /= 10;
	}
}

// 1470 ->> 0 7 4 1
void Bigint::normalize()
{
	while (digits_.size() > 1 && digits_.back() == 0)
	{
		digits_.pop_back();
	}
}

Bigint::Bigint(unsigned long n)
{
	from_unsigned_long(n);
}

Bigint::Bigint(const Bigint& other) : digits_(other.digits_)
{
}

Bigint& Bigint::operator=(const Bigint& other)
{
	if (this != &other)
	{
		digits_ = other.digits_;
	}
	return *this;
}

//	imprimir del final al principio
std::ostream& operator<<(std::ostream& os, const Bigint& b)
{
	if (b.digits_.empty())
		return os << "0";

	for (int i = b.digits_.size() - 1; i >= 0; --i)
	{
		os << (int)b.digits_[i];
	}
	return (os);
}

//	===================================================

bool Bigint::operator==(const Bigint& other) const
{
	return (digits_ == other.digits_);
}

bool Bigint::operator<(const Bigint& other) const
{
	if (digits_.size() != other.digits_.size())
		return (digits_.size() < other.digits_.size());

	for (int i = digits_.size() - 1; i >= 0; --i)
	{
		if (digits_[i] != other.digits_[i])
			return digits_[i] < other.digits_[i];
	}
	return false;
}

bool Bigint::operator>(const Bigint& other) const
{
	return (other < *this);
}

bool Bigint::operator!=(const Bigint& other) const
{
	return !(*this == other);
}

bool Bigint::operator<=(const Bigint& other) const
{
	return (*this < other || *this == other);
}

bool Bigint::operator>=(const Bigint& other) const
{
	return !(*this < other);
}

//	=======================================================

Bigint Bigint::operator+(const Bigint& other) const
{
	Bigint res;
	res.digits_.clear();

	size_t max = std::max(digits_.size(), other.digits_.size());
	unsigned char carry = 0;

	for (size_t i = 0; i < max; ++i)
	{
		unsigned int suma = carry;
		if (i < digits_.size())
			suma += digits_[i];
		if (i < other.digits_.size())
			suma += other.digits_[i];

		res.digits_.push_back(suma % 10);
		carry = suma / 10;
	}
	res.normalize();

	return res;
}

Bigint& Bigint::operator++()
{
	*this += 1;
	return *this;
}

Bigint Bigint::operator++(int)
{
	Bigint tmp(*this);
	++(*this);
	return (tmp);
}

