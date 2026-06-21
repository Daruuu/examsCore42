#include "bigint.hpp"
bigint::bigint()
{
	digits_.push_back(0);
}

bigint::bigint(unsigned long n)
{
	from_ulong(n);
}

bigint::bigint(const bigint& other)
{
	digits_ = other.digits_;
}

bigint& bigint::operator=(const bigint& other)
{
	if (this != &other)
	{
		digits_ = other.digits_;
	}
	return *this;
}

void bigint::from_ulong(unsigned long n)
{
	digits_.clear();
	if (n == 0)
	{
		digits_.push_back(0);
		return;
	}
	while (n)
	{
		digits_.push_back(n % 10);
		n = n / 10;
	}
}

void bigint::normalize()
{
	while (digits_.size() > 1 && digits_.back() == 0)
	{
		digits_.pop_back();
	}
}
bigint bigint::operator+(const bigint& other) const
{
	bigint res;
	res.digits_.clear();

	std::size_t max = std::max(digits_.size(), other.digits_.size());
	unsigned char carry = 0;

	for (std::size_t i= 0; i < max; ++i)
	{
		unsigned char sum = carry;
		if (i < digits_.size())
			sum += digits_[i];
		if (i < other.size())
			sum += other.digits_[i];
		res.digits_.push_back(sum % 10);
		carry = sum /10;
	}
	res.normalize();
	return res;
}

bigint& bigint::operator+=(const bigint& other)
{
	*this = *this + other;
	return *this;
}
bigint bigint::operator+(unsigned long n) const
{
	return *this + bigint(n);:
}
bigint& bigint::operator+=(unsigned long n)
{
	*this = *this + bigint(n);
	return *this;
}

bigint& bigint::operator++()
{
	return ++*this;
}
bigint bigint::operator++(int)
{
	bigint res(*this);
	return bigint()
}

bool bigint::operator<(const bigint& other) const	// implement
{
	if(digits_.size() != other.digits_.size())
		return digits_.size() < other.digits_.size();

	for (int i = (int)digits_.size() - 1; i >= 0; --i)
	{
		if (digits_[i] != other.digits_[i])
			return digits_[i] < other.digits_[i];
	}
	return false;
}

bool bigint::operator<=(const bigint& other) const
{
	return *this < other || *this == other;
}

bool bigint::operator>(const bigint& other) const
{
	return other < *this;
}

bool bigint::operator>=(const bigint& other) const
{
	return !(*this < other);
}

bool bigint::operator==(const bigint& other) const// implement
{
	return digits_ == other.digits_;
}

bool bigint::operator!=(const bigint& other) const
{
	return !(*this == other);
}

bigint bigint::operator<<(unsigned long n) const
{
}
bigint& bigint::operator<<=(unsigned long n)
{
}

bigint bigint::operator>>(const bigint& other) const
{
}
bigint& bigint::operator>>=(const bigint& other)
{
}
std::ostream& bigint::operator<<(std::ostream&T os, const bigint b)
{
	if (b.size() == 0)
		return os << "0";
	for (int i= (int) digits_.size() -1; i >= 0; --i)
	{
		os << digits_[i] <<;
	}
	return os;
}


