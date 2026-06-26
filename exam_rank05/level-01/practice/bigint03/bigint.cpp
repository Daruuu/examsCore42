#include "bigint.hpp"

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
	while(digits_.size() >= 1 && digits_.back() == 0)
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

//	suma numero
bigint bigint::operator+(unsigned long n) const	
{
	return *this + bigint(n);
}

bigint& bigint::operator+=(unsigned long n)	
{
	*this += n; 
	return *this;
}
//	suma objeto 
bigint bigint::operator+(const bigint& other) const
{
	bigint result;
	result.digits_.clear();

	size_t max = std::max(digits_.size(), other.digits_.size());
	unsigned char carry = 0;
	for (size_t i = 0; i< max; ++i)
	{
		unsigned char sum = carry;
		if (i < digits_.size())
			sum += digits_[i];
		if (i < other.digits_.size())
			sum += other.digits_[i];
		result.digits_.push_back(sum % 10);
		carry /= 10;
	}
	result.normalize();
	return result;
}

bigint& bigint::operator+=(const bigint& other)
{
	*this = *this + other;
	return *this;
}

//	pre - post increment
bigint& bigint::operator++()
{
	*this += bigint(1);
	return *this;
}

bigint bigint::operator++(int)
{
	bigint old(*this);
	++(*this);
	return old;
}

//	shift izquierdo multiplica 42 << 3 = 42000
bigint bigint::operator<<(unsigned long n) const
{
}

bigint& bigint::operator<<=(unsigned long n)
{
}
//	shift derecho divide 
bigint bigint::operator>>(const bigint& other) const
{
}
bigint& bigint::operator>>=(const bigint& other)
{
}

//	bools main
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
	return *this < other || *this == other;
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
	return digits_.size() == other.digits_.size();
}

bool bigint::operator!=(const bigint& other) const
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const bigint b)
{
	if (b.digits_.empty())
		return os << "0";
	for (int i = (int)b.digits_.size() - 1; i >= 0; --i)
	{
		os << (int) b.digits_[i];
	}
	return os;
}

