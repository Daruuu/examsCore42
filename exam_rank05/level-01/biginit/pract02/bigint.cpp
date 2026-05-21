#include "bigint.hpp"
#include <sstream>

bigint::bigint() : str("0")
{
}

bigint::bigint(unsigned int n)
{
	std::stringstream ss;
	ss << n;
	str = ss.str();
}

bigint::bigint(const bigint& other)
{
	*this = other;
}

bigint& bigint::operator=(const bigint& other)
{
	if (this != &other)
		str = other.str;
	return *this;
}

std::string bigint::getStr()
{
	return str;
}

	// suma
bigint bigint::operator+(const bigint& other) const
{
	std::string num1 = str;
	std::string num2 = other.str;
	std::string res;
	int carry = 0;

	while (num1.length() < num2.length())
		num1 = "0" + num1;
	while (num2.length() < num1.length())
		num2 = "0" + num2;

	for (int i = num1.length() - 1; i >= 0; i--)
	{
		int	 sum = (num1[i] - '0') + (num2[i] - '0') + carry;
		carry = sum / 10;
		res = char (sum % 10 + '0') + res;
	}
	if (carry)
		res = '1' + res;
	while (res.length() > 1 && res[0] == '0')
		res.erase(0, 1);

	bigint result;
	result.str = res;
	return result;
}

bigint& bigint::operator+=(const bigint& other)
{
	*this = *this + other;
	return *this;
}

// incremento	
bigint  bigint::operator++()
{
	*this = *this + bigint(1);
	return *this;
}

bigint&  bigint::operator++(int)
{
	bigint tmp = *this;
	*this = *this + bigint(1);
	return tmp;
}

//	shift decimal
bigint  bigint::operator<<(unsigned int n) const
{
	bigint tmp = *this;
	tmp.str.append(n, '0');
	return tmp;
}

bigint  bigint::operator>>(unsigned int n) const
{
	bigint tmp = *this;

	if (n >= tmp.str.length())
		tmp.str = "0";
	else
		tmp.str.erase(tmp.str.length() -n, n);
	return tmp;
}

bigint&  bigint::operator<<=(unsigned int n);
bigint&  bigint::operator>>=(unsigned int n);

// shift decimal objeto

bigint  bigint::operator<<(const bigint& other) const;
bigint  bigint::operator>>(const bigint& other) const;

bigint&  bigint::operator<<=(const bigint& other);
bigint&  bigint::operator>>=(const bigint& other);

//	comparaciones
bool  bigint::operator==(const bigint& other) const;
bool  bigint::operator!=(const bigint& other) const;
bool  bigint::operator<(const bigint& other) const;
bool  bigint::operator>(const bigint& other) const;
bool  bigint::operator<=(const bigint& other) const;
bool  bigint::operator>=(const bigint& other) const;

std::ostream& operator<<(std::ostream& os,const bigint& obj);
