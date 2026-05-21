#include "bigint.hpp"

Bigint::Bigint()
{
	digits_.push_back(0);

}
Bigint::Bigint(const Bigint &src)
{

}

// Recuerda: Si entra `1337`, tu vector debe quedar como `[7, 3, 3, 1]`.

Bigint::Bigint(unsigned long n)
{
	while (n != 0)
	{
		digits_.push_back(n%10);
		n = n/10;
	}
}

~Bigint::Bigint()
{

}

std::ostream& operator<<(std::ostream& os, const Bigint& b)
{
	if (b.digits_.empty())
		return os << "0";

	for (int i = (int)b.digits_.size() - 1; i >= 0; --i)
	{
		os << (int)b.digits_[i];
	}
	return os;
}
