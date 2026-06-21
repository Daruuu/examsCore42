#include "bigint.hpp"
#include <sstream>

	//	CONSTRUCTORS CANONICAL
bigint::bigint(): str("0")
{
}

bigint::bigint(unsigned int num)
{
	std::stringstream ss;
	ss << num;
	str = ss.str();
}

//	copy
bigint::bigint(const bigint& other)
{
	*this = other;
}

bigint& bigint::operator=(const bigint& other)
{
	if (this != &other)
	{
		str = other.str;
	}
	return (*this);
}

	//	GETTER STR
std::string bigint::getStr() const
{
	return (str);
}
	
	//	SUMA
bigint bigint::operator+(const bigint& other) const
{
	std::string num1 = str;
	std::string num2 = other.str;
	std::string result;
	int carry = 0;

	while (num1.length() < num2.length())
	{
		num1 = "0" + num1;
	}
	while (num2.length() < num1.length())
	{
		num2 += "0";
	}
	for (int i = num1.length() - 1; i >= 0; i--)
	{
		int sum = (num1[i] - '0') + (num2[i] - '0') + carry;
		carry = sum / 10;
		result = char(sum % 10 + '0') + result;
	}
	//	add carry al final
	if (carry)	
	{
		result = '1' + result;
	}
	while (result.length() > 1 && result[0] == '0')
	{
		result.erase(0, 1);
	}

	bigint resFinal;
	resFinal.str = result;

	return resFinal;
}

bigint& bigint::operator+=(const bigint& other)
{
	*this = *this + other;
	return *this;
}

	//	INCREMENTO	
bigint& bigint::operator++()	// pre-incremento ++x
{
	*this = *this + bigint(1);
	return *this;
}

bigint bigint::operator++(int)// post-incremento x++
{
	bigint tmp = *this;
	*this = *this + bigint(1);
	return tmp;
}
 
//	SHIFT DECIMAL << >> 	
//	add zeros at end of number
bigint bigint::operator<<(unsigned int n) const	// multiply x 10^n
{
	bigint tmp = *this;
	tmp.str.append(n, '0');
	return tmp;
}

//	add zeros at start of number
bigint bigint::operator>>(unsigned int n) const	// divide / 10^n
{
	bigint tmp = *this;
	if (n >= tmp.str.length())
		tmp.str = "0";
	else
	{
		tmp.str.erase(tmp.str.length() - n, n);
	}
	return tmp;
}

//	SHIFT AND ASSIGN
bigint bigint::operator<<=(unsigned int n)
{
	*this = *this << n;
	return *this;
}

bigint bigint::operator>>=(unsigned int n)
{
	*this = *this >> n;
	return *this;
}

//	AUXILIAR FUNCTION
static unsigned int stringToInt(const std::string& str)
{
	std::stringstream ss(str);
	unsigned int res;
	ss >> res;
	return res;
}

// shift usando bigint
bigint bigint::operator<<(const bigint& other) const 
{
	return *this << stringToInt(other.str);
}

bigint bigint::operator>>(const bigint& other) const
{
	return *this >> stringToInt(other.str);
}

bigint& bigint::operator<<=(const bigint& other)
{
	*this = *this << stringToInt(other.str);
	return *this;
}

bigint& bigint::operator>>=(const bigint& other)
{
	*this = *this << stringToInt(other.str);
	return *this;
}

//	COMPARASIONES : 6
bool bigint::operator==(const bigint& other) const
{
	return str == other.str;
}

bool bigint::operator!=(const bigint& other) const
{
	return str != other.str;
}

bool bigint::operator<(const bigint& other) const
{
	if (str.length() != other.str.length())
		return (str.length() < other.str.length());
	return str < other.str;
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

std::ostream& operator<<(std::ostream& os, const bigint& obj)
{
	os << obj.getStr();
	return os;
}
