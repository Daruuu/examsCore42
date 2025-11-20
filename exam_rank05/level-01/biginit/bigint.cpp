#include <vector>
#include "bigint.hpp"

//1.	rule of 3
bigint::bigint()
{
	digits_.push_back(0);
}

void bigint::from_unsigned_long(unsigned long n)	// usado en constructor
{
	digits_.clear();
	if (n == 0)
	{
		digits_.push_back(0);
		return ;
	}
	while (n > 0)
	{
		digits_.push_back(static_cast<unsigned char>(n % 10));
		n /= 10;
	}
}

bigint::bigint(unsigned long n)
{
	from_unsigned_long(n);
}

void bigint::normalize()	// elimina ceros a la izquierda
{
	while (digits_.size() > 1 && digits_.back() == 0)
		digits_.pop_back();
}

// COPY
bigint::bigint(const bigint& other) : digits_(other.digits_)
{
}

//	2
// asignacion 
bigint& bigint::operator=(const bigint& other)
{
	if (this != &other)
		digits_ = other.digits_;
	return *this;
}

//	3
std::ostream& operator<<(std::ostream& os, const bigint& b)
{
	if (b.digits_.empty())
		return os << "0";

	for (int i = (int)b.digits_.size() - 1; i >= 0; --i)
		os << (int) b.digits_[i];
}

// 4 ******	comparaciones basicas

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
		return ( digits_.size() < other.digits_.size() );

	for (int i = (int)digits_.size() - 1; i >= 0; --i)
	{
		if (digits_[i] != other.digits_[i])
			return digits_[i] < other.digits_[i];
	}
	return false;
}

bool bigint::operator>(const bigint& other) const
{
	return other < *this;
}

bool bigint::operator<=(const bigint& other) const
{
	return ( *this < other || *this == other );
}

bool bigint::operator>=(const bigint& other) const
{
	return !(*this < other);
}

// 5	******* suma con enteros pequenyos	
bigint bigint::operator+(unsigned long n) const
{
	return ( *this + bigint(n) );
}

bigint& bigint::operator+=(unsigned long n)
{
	*this = *this + n;
	return *this;
}

// 6 completa entre bigints
bigint bigint::operator+(const bigint& other) const
{
	bigint res;

	res.digits_.clear();
	size_t n = std::max(digits_.size(), other.digits_.size());

	unsigned char carry = 0;

	for (size_t i = 0; i < n || carry; ++i)
	{
		unsigned int sum = carry;
		if (i < digits_.size())
			sum += digits_[i];
		if (i < other.digits_.size())
			sum += other.digits_[i];
		res.digits_.push_back(sum % 10);
		carry = sum / 10;
	}
	res.normalize();
	return res;
}

bigint& bigint::operator+=(const bigint& other)
{
	*this = *this + other;
	return *this;
}

// 7 incremento 
bigint& bigint::operator++();	// pre-increment
bigint bigint::operator++(int);	// post-increment

// 8 digit shift 
bigint bigint::operator<<(unsigned long n) const;
bigint& bigint::operator<<=(unsigned long n);

//	9 digit shift derecho (divide por potencia de 10)
//	acepta bigint porque el main hace: d >>= (bigint)2
bigint bigint::operator>>(const bigint& other) const;
bigint& bigint::operator>>=(const bigint& other);

}

