#include "bigint.hpp"

// --- constructores ---

bigint::bigint() { digits_.push_back(0); }

bigint::bigint(unsigned long n) { from_ulong(n); }

bigint::bigint(const bigint& other) : digits_(other.digits_)
{
}

bigint& bigint::operator=(const bigint& other)
{
	if (this != &other)
		digits_ = other.digits_;
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
	while (digits_.size() > 1 && digits_.back() == 0)
		digits_.pop_back();
}

// --- salida ---

std::ostream& operator<<(std::ostream& os, const bigint& b)
{
	if (b.digits_.empty()) return os << "0";
	for (int i = (int)b.digits_.size() - 1; i >= 0; --i)
		os << (int)b.digits_[i];
	return os;
}

// --- comparaciones: solo implementa == y < ---

bool bigint::operator==(const bigint& other) const
{
	return digits_ == other.digits_;
}

bool bigint::operator!=(const bigint& other) const
{
	return !(*this == other);
}
bool bigint::operator>(const bigint& other) const
{
	return other < *this;
}
bool bigint::operator<=(const bigint& other) const
{
	return !(*this > other);
}
bool bigint::operator>=(const bigint& other) const
{
	return !(*this < other);
}

bool bigint::operator<(const bigint& other) const
{
	if (digits_.size() != other.digits_.size())
		return digits_.size() < other.digits_.size();
	for (int i = (int)digits_.size() - 1; i >= 0; --i)
		if (digits_[i] != other.digits_[i])
			return digits_[i] < other.digits_[i];
	return false;
}

// --- suma: solo implementa operator+ ---

bigint bigint::operator+(const bigint& other) const
{
	bigint res;
	res.digits_.clear(); // res nace con [0] por el ctor por defecto
	size_t n = digits_.size() > other.digits_.size()
					? digits_.size()
					: other.digits_.size();
	unsigned carry = 0;
	for (size_t i = 0; i < n || carry; ++i)
	{
		unsigned sum = carry;
		if (i < digits_.size()) sum += digits_[i];
		if (i < other.digits_.size()) sum += other.digits_[i];
		res.digits_.push_back(sum % 10);
		carry = sum / 10;
	}
	res.normalize();
	return res;
}

bigint bigint::operator+(unsigned long n) const { return *this + bigint(n); }

bigint& bigint::operator+=(const bigint& other)
{
	return *this = *this + other;
}

bigint& bigint::operator+=(unsigned long n) { return *this = *this + n; }
bigint& bigint::operator++() { return *this += 1; }

bigint bigint::operator++(int)
{
	bigint old(*this);
	++*this;
	return old;
}

// --- shifts: solo implementa << y >> ---

bigint bigint::operator<<(unsigned long n) const
{
	if (digits_.size() == 1 && digits_[0] == 0) return *this;
	bigint res(*this);
	res.digits_.insert(res.digits_.begin(), n, 0);
	return res;
}

bigint& bigint::operator<<=(unsigned long n) { return *this = *this << n; }

bigint bigint::operator>>(const bigint& other) const
{
	unsigned long shift = 0;
	for (size_t i = other.digits_.size(); i-- > 0;)
		shift = shift * 10 + other.digits_[i];
	if (shift >= digits_.size()) return bigint(0UL);
	bigint res(*this);
	res.digits_.erase(res.digits_.begin(), res.digits_.begin() + shift);
	res.normalize();
	return res;
}

bigint& bigint::operator>>=(const bigint& other)
{
	return *this = *this >> other;
}
