#include "bigint.hpp" 

void bigint::from_ulong(unsigned long n)
{
	digits_.clear();
	if (!n)
	{
		digits_.push_back(0);
		return ;
	}
	while (n)
	{
		digits_.push_back(n % 10);
		n /= 10;
	}
}

void bigint::normalize()
{
	while (digits_.size() > 1 && digits_.back() == 0)
		digits_.pop_back();
}

//	OCF
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
	if (*this != other)
	{
		digits_ = other.digits_;
	}
	return *this;
}

//	+ - objecto numero
bigint bigint::operator+(const bigint& other) const
{

}

bigint& bigint::operator+=(const bigint& other)
{
	*this = *this + other;
	return *this;
}

bigint bigint::operator+(unsigned long n) const
{
}
bigint& bigint::operator+=(unsigned long n)
{
}

//	pre post increment
bigint& bigint::operator++()
{
	*this = *this + bigint(1);
	return *this;
}

bigint bigint::operator++(int)
{
	bigint old(*this);
	++*this;
	return old;
}

//	bool
bool bigint::operator<(const bigint& other) const
{
	return digits_.size() < other.digits_.size();
}
bool bigint::operator<=(const bigint& other) const
{
	return digits_.size() < other.digits_.size() && digits_.size() == other.digits_.size();
}
bool bigint::operator>(const bigint& other) const
{
	return other < *this;
}
bool bigint::operator>=(const bigint& other) const
{
	return other < *this || other == *this;
}
bool bigint::operator==(const bigint& other) const
{
	if (digits_.size() != other.digits_.size())
		return digits_.size() < other.digits_.size();

}
bool bigint::operator!=(const bigint& other) const
{
	return !(*this == other);
}

//	shift << >>
bigint bigint::operator<<(unsigned long n) const
{
}
bigint& bigint::operator<<=(unsigned long n)
{
}
bigint bigint::operator>>(const bigint& other) const
{
	unsigned long shift = 0;
	for (size_t i = other.digits_.size(); i-- > 0;)
	{
		shift = shift * 10 + other.digits_[i];
	}
	if (shift >= digits_.size())
		return bigint(0);

	
}
bigint& bigint::operator>>(const bigint& other)
{
	*this = *this >> n;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const bigint& b)
{
	if (b.digits_.empty())
	{
		os << "0";
		return os;
	}
	for (int i = (int)b.digits_.size() - 1; i >= 0;--i)
	{
		os << (int) b.digits_[i];
	}
	return os;
}
