#include "bigint.hpp"

void bigint::from_ulong(unsigned long n)
{
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
	if (this != &other)
	{
		digits_ = other.digits_;
	}
	return *this;
}

//	suma , suma-igual
bigint bigint::operator+(unsigned long n) const
{
}
bigint& bigint::operator+=(unsigned long n)
{
}
bigint bigint::operator+(const bigint& other) const
{
}
bigint& bigint::operator+=(const bigint& other)
{
}

//	pre- post increment
bigint& bigint::operator++()
{
	*this + 1;
	return *this;
}

bigint bigint::operator++(int)
{
	bigint old(*this);
	++(*this);
	return old;
}

//	======================================================
//	shift numero
bigint bigint::operator<<(unsigned long n) const
{
	bigint result(*this);

	if (digits_.size() == 1 && result.digits_[0] == 0)
		return result;
	for (unsigned long i = 0; i < n; ++i)
	{
		result.digits_.insert(result.digits_.begin(), 0);
	}
	return result;
}

bigint& bigint::operator<<=(unsigned long n)
{
	*this = *this << n;
	return *this;
}

//	objeto
//	tenemos que dividir
bigint bigint::operator>>(const bigint& n) const
{
	unsigned long shift = 0;
	for (int i = o)
}

bigint& bigint::operator>>=(const bigint& n);
{
}

//	======================================================
//	bools
bool bigint::operator==(const bigint& other) const
{
	return digits_ == other.digits_;
}

bool bigint::operator!=(const bigint& other) const
{
	return !(*this == other);
}

bool bigint::operator<(const bigint& other) const
{
	if (digits_.size() != other.digits_.size())
		return digits_.size() < other.digits_.size();
	for (int i =(int) digits_.size() - 1; i >= 0; --i)
	{
		if (digits_[i] != other.digits_[i])
			return digits_[i] < other.digits_[i];
	}
	return false;
}

bool bigint::operator<=(const bigint& other) const
{
	//return digits_.size() < other.digits_.size() || digits_.size() == other.digits_.size();
	return (*this < other || *this == other);
}

bool bigint::operator>(const bigint& other) const
{
	return other < *this;
}

bool bigint::operator>=(const bigint& other) const
{
	return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const bigint& b)
{
	if (b.digits_.empty())
	{
		return os << "0";
	}
	for (int i = (int) b.digits_.size() - 1; i >= 0; --i)
	{
		os << (int)b.digits_[i];
	}
	return os;
}

