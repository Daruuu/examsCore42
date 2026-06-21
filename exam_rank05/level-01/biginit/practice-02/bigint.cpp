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
//	rm zeros
void bigint::normalize()
{
	while (digits_.size() > 1 && digits_.back() == 0)
		digits_.pop_back();
}
//	suma objs
bigint bigint::operator+(const bigint& other) const	
{
}
bigint bigint::operator+(unsigned long n) const
{
}
bigint& bigint::operator+=(const bigint& other)	
{
}
bigint& bigint::operator+=(unsigned long n)	
{
}

bigint& bigint::operator++()
bigint bigint::operator++(int)

bigint bigint::operator<<(unsigned long n) const
bigint& bigint::operator<<=(unsigned long n)
bigint bigint::operator>>(const bigint& other) const
bigint& bigint::operator>>=(const bigint& other)

//	bools
bool bigint::operator<(const bigint& other) const	//implementa
{
	if (digits_.size() != other.digits_.size())
		return digits_.size() < other.digits_.size();
	for (int i = (int) digits_.size() - 1; i >= 0; --i)
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
}

bool bigint::operator>=(const bigint& other) const
{
}

bool bigint::operator==(const bigint& other) const	// implementa
{
	return digits_ != other.digits_;
}

bool bigint::operator!=(const bigint& other) const
{
}

std::ostream& operator<<(std::ostream& os, const bigint& b)
{
}

