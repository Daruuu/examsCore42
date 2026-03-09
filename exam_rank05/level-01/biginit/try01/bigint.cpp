#include "bigint.hpp"
#include <sstream>

bigint::bigint() : str("0") {}

bigint::bigint(unsigned int num)
{
    std::stringstream ss;
    ss << num;
    str = ss.str();
}

bigint::bigint(const bigint& source)
{
    *this = source;
}

bigint& bigint::operator=(const bigint& source)
{
    if (this != &source)
        str = source.str;
    return *this;
}

std::string bigint::getStr() const
{
    return str;
}

// addition
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
        int sum = (num1[i] - '0') + (num2[i] - '0') + carry;
        carry = sum / 10;
        res = char(sum % 10 + '0') + res;
    }

    if (carry)
        res = '1' + res;

    while (res.length() > 1 && res[0] == '0')
        res.erase(0,1);

    bigint result;
    result.str = res;
    return result;
}

bigint& bigint::operator+=(const bigint& other)
{
    *this = *this + other;
    return *this;
}

// increments
bigint& bigint::operator++()
{
    *this = *this + bigint(1);
    return *this;
}

bigint bigint::operator++(int)
{
    bigint temp = *this;
    *this = *this + bigint(1);
    return temp;
}

// shift left
bigint bigint::operator<<(unsigned int n) const
{
    bigint temp = *this;
    temp.str.append(n, '0');
    return temp;
}

// shift right
bigint bigint::operator>>(unsigned int n) const
{
    bigint temp = *this;

    if (n >= temp.str.length())
        temp.str = "0";
    else
        temp.str.erase(temp.str.length() - n, n);

    return temp;
}

bigint& bigint::operator<<=(unsigned int n)
{
    *this = *this << n;
    return *this;
}

bigint& bigint::operator>>=(unsigned int n)
{
    *this = *this >> n;
    return *this;
}

static unsigned int stringToUINT(const std::string& str)
{
    std::stringstream ss(str);
    unsigned int res;
    ss >> res;
    return res;
}

// shift with bigint
bigint bigint::operator<<(const bigint& other) const
{
    return *this << stringToUINT(other.str);
}

bigint bigint::operator>>(const bigint& other) const
{
    return *this >> stringToUINT(other.str);
}

bigint& bigint::operator<<=(const bigint& other)
{
    *this = *this << stringToUINT(other.str);
    return *this;
}

bigint& bigint::operator>>=(const bigint& other)
{
    *this = *this >> stringToUINT(other.str);
    return *this;
}

// comparisons
bool bigint::operator==(const bigint& other) const
{
    return str == other.str;
}

bool bigint::operator!=(const bigint& other) const
{
    return !(*this == other);
}

bool bigint::operator<(const bigint& other) const
{
    if (str.length() != other.str.length())
        return str.length() < other.str.length();

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