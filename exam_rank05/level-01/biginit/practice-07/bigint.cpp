#include "bigint.hpp"

const std::vector<unsigned char>& bigint::getStr() const
{
	return digits_;
}
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
	if (!n)
	{
		digits_.push_back(0);
		return;
	}
	while (n)
	{
		digits_.push_back(n % 10);
		n /= 10;
	}
}

void bigint::normalize()
{
	while (digits_.size() > 0 && digits_.back() == 0)
		digits_.pop_back();
}

//	suma
bigint bigint::operator+(const bigint& other) const
{
	bigint result;
	result.digits_.clear();

	std::size_t max = std::max(digits_.size(), other.digits_.size());

	unsigned char carry = 0;
	for (size_t i = 0; i < max; ++i)
	{
		unsigned long sum = carry;
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

bigint& bigint::operator+=(const bigint& other)
{
	*this =  *this + other;
	return *this;
}

bigint bigint::operator+(unsigned long n) const
{
	return *this + bigint(n);
}

bigint& bigint::operator+=(unsigned long n)
{
	*this = *this + n;
	return *this;
}

bigint& bigint::operator++()
{
	*this = *this + 1;
	return *this;
}

bigint bigint::operator++(int)
{
	bigint old(*this);
	++*this;
	return old;
}

//	true false
bool bigint::operator<(const bigint& other) const
{
	if (digits_.size() != other.digits_.size())
		return digits_.size() < other.digits_.size();

	for (int i= (int) digits_.size() - 1; i >= 0; --i)
	{
		if(digits_[i] != other.digits_[i])
			return digits_[i] < other.digits_[i];
	}
	return false;
}

bool bigint::operator<=(const bigint& other) const
{
	return *this == other || *this < other;
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
	return digits_ == other.digits_;
}

bool bigint::operator!=(const bigint& other) const
{
	return !(*this == other);
}

//	numero
bigint bigint::operator<<(unsigned long n) const
{
	if (digits_.size() == 1 && digits_[0] == 0)
		return bigint(0);
	bigint result = *this;
	result.digits_.insert(result.digits_.begin(), n, 0);
	return result;
}

bigint& bigint::operator<<=(unsigned long n)
{
	/*
	if (digits_.size() == 1 && digits_[0] == 0)
		return *this;
	digits_.insert(digits_.begin(), n, 0);
	return *this;
	*/
	return *this = *this << n;
}

//	objeto
bigint bigint::operator>>(const bigint& other) const
{
	unsigned long shift = 0;
	for (size_t i = other.digits_.size(); i -- > 0; )
	{
		shift = shift * 10 + other.digits_[i];
	}
	//	 check length
	if (shift >= digits_.size())
		return bigint(0UL);

	bigint result(*this);
	result.digits_.erase(result.digits_.begin(), result.digits_.begin() + shift);
	result.normalize();

	return result;
}

bigint& bigint::operator>>=(const bigint& other)
{
	return *this = *this >> other;
}

std::ostream& operator<<(std::ostream& os, const bigint& b)
{
	if (b.getStr().size() == 0)
	{
		return os << "0";
	}
	for (int i = (int)b.getStr().size() - 1; i >= 0; --i)
	{
		//os << (int)b.getStr().digits_[i];
		os << (int)b.getStr()[i];
	}
	return os;
}

