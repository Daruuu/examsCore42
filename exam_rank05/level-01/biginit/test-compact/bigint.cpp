#include "bigint.hpp"
#include <vector>

bigint::bigint() : digits_.push_back(0)
{
}

bigint::bigint(const bigint& other)
{
	digits_ = other.digits_;
}

bigint& bigint::operator=(const bigint& other)
{
	if (*this != other)
		digits_ = other.digits_;
	return *this;
}

bigint::bigint(unsigned long n)
{
	from_unsigned_long(n);
}

void bigint::from_unsigned_long(unsigned long n)
{
	digits_.clear();
	if (n == 0)
	{
		digits_.push_back(0);
		return;
	}
	while (n)
	{
		digits_.push_back(static_cast<unsigned char>(n % 10));
		n /= 10;
	}
}

//	 remove 0 
void bigint::normalize()
{
	while (digits_.size() > 1 && digits_.back() == 0)
		digits_.pop_back();
}

std::ostream& operator<<(std::ostream& os, const bigint& b)
{
	if (b.digits_.empty())
		return os << "0";
	for (int i = (int)b.digits_.size() - 1; i >= 0; --i)
		os << (int)b.digits_[i];
}

bool bigint::operator<(const bigint& other) const
{
	if (digits_.size() != other.digits_.size())
		return digits_.size() < other.digits_.size();

	for (int i = digits_.size() - 1; i >= 0; --i)
	{
		if (digits_[i] != other.digits_[i])
			return digits_[i] < other.digits_[i];
	}
	return false;
}

bool bigint::operator<=(const bigint& other) const
{
	return !(*this > other);
}

bool bigint::operator>(const bigint& other) const
{
	return other < *this;
}

bool bigint::operator>=(const bigint& other) const
{
	return !(*this < other);
}

bool bigint::operator!=(const bigint& other) const
{
	return !(*this == other);
}

bool bigint::operator==(const bigint& other) const
{
	return digits_ == other.digits_;
}

bigint bigint::operator+(const bigint& other) const
{
	bigint res;
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

bigint bigint::operator+(unsigned long n) const
{
	return *this + bigint(n);
}

bigint& bigint::operator+=(const bigint& other)
{
	return *this = *this + other;
}

bigint bigint::operator+=(unsigned long n)
{
	return *this + bigint(n);
}

bigint& bigint::operator++()
{
	*this += 1;
}

bigint bigint::operator++(int)
{
	bigint old(*this);
	++*this;
	return old;
}
