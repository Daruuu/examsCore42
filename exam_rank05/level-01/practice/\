#include  "bigint.hpp"

void from_ulong(unsigned long n);
void normalize();

bigint();
bigint(unsigned long n);
bigint(const bigint& other);
bigint& operator=(const bigint& other);

bigint bigint::operator+(unsigned long n) const
{
	return *this + bigint(n);
}

bigint& bigint::operator+=(unsigned long n)
{
	*this = *this + bigint(n);
	return *this;
}

bigint bigint::operator+(const bigint& other) const
{
	bigint result;
	result.digits_.clear();

	std::size_t max = std::max(digits_.size(), other.digits_.size());
	unsigned char carry = 0;

	for (size_t i = 0; i < max || carry; ++i)
	{
		unsigned char sum = carry;
		if (i < digits_.size())
			sum += digits_[i];
		if (i < other.digits_.size())
			sum += other.digits_[i];
		result.digits_.push_back(sum % 10);
		carry = sum / 10;
	}
	result.normalize();
	return result;
}
bigint& bigint::operator+(const bigint& other)
{
}

bigint& bigint::operator++()
{

}
bigint bigint::operator++(int)
{
	bigint old(*this);
	++(*this);
	return *this;
}

//	shift izquierda multiplica
bigint operator<<(unsigned long n) const;
bigint& operator<<=(unsigned long n);

//	shift derecha divide
bigint operator>>(const bigint& other) const;
bigint& operator>>=(const bigint& other);

//	bools
bool operator<(const bigint& other) const;
bool operator<=(const bigint& other) const;
bool operator>(const bigint& other) const;
bool operator>=(const bigint& other) const;
bool operator==(const bigint& other) const;
bool operator!=(const bigint& other) const;

std::ostream& operator<<(std::ostream& os, const bigint& b);
