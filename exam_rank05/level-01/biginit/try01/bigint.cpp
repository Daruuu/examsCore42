#include "bigint.hpp"
#include <sstream>

/* crea bigint = 0 */
bigint::bigint() : str("0") {}

/* convierte un entero a string */
bigint::bigint(unsigned int num)
{
    std::stringstream ss;
    ss << num;
    str = ss.str();
}

/* copia otro bigint */
bigint::bigint(const bigint& source)
{
    *this = source;
}

/* operator of assign */
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

/** addition of 2 numbers  using strings
 * igualar los tamanyos de los strings
*/
bigint bigint::operator+(const bigint& other) const
{
    std::string num1 = str;
    std::string num2 = other.str;
    std::string res;
    int carry = 0;

    // igualar tamaños
    while (num1.length() < num2.length())
        num1 = "0" + num1;

    while (num2.length() < num1.length())
        num2 = "0" + num2;

	// sumamos de derecha a izquierda
    for (int i = num1.length() - 1; i >= 0; i--)
    {
        int sum = (num1[i] - '0') + (num2[i] - '0') + carry;
        carry = sum / 10;
        res = char(sum % 10 + '0') + res;
    }

	// añadir carry final
    if (carry)
        res = '1' + res;
	// quitar ceros iniciales
    while (res.length() > 1 && res[0] == '0')
        res.erase(0,1);

    bigint result;
    result.str = res;
    return result;
}

/* usa operator+ y guarda resultado */
bigint& bigint::operator+=(const bigint& other)
{
    *this = *this + other;
    return *this;
}

//  pre-incremento: ++x incrementa el valor y retorna el objeto
bigint& bigint::operator++()
{
    *this = *this + bigint(1);
    return *this;
}

//  post-incremento: x++ , retornal el valor antiguo
bigint bigint::operator++(int)
{
    bigint temp = *this;
    *this = *this + bigint(1);
    return temp;
}

// shift left
/* añade ceros al final -> x * 10^n */
bigint bigint::operator<<(unsigned int n) const
{
    bigint temp = *this;
    temp.str.append(n, '0');
    return temp;
}

// shift right
/* elimina dígitos finales -> x / 10^n */
bigint bigint::operator>>(unsigned int n) const
{
    bigint temp = *this;

    if (n >= temp.str.length())
        temp.str = "0";
    else
        temp.str.erase(temp.str.length() - n, n);

    return temp;
}

/* shift left y asigna */
bigint& bigint::operator<<=(unsigned int n)
{
    *this = *this << n;
    return *this;
}

/* shift right y asigna */
bigint& bigint::operator>>=(unsigned int n)
{
    *this = *this >> n;
    return *this;
}

/* convierte string a unsigned int */
static unsigned int stringToUINT(const std::string& str)
{
    std::stringstream ss(str);
    unsigned int res;
    ss >> res;
    return res;
}
//	============================
//	========OPERATORS===========
//	============================

/* shift left usando bigint */
bigint bigint::operator<<(const bigint& other) const
{
    return *this << stringToUINT(other.str);
}

/* shift right usando bigint */
bigint bigint::operator>>(const bigint& other) const
{
    return *this >> stringToUINT(other.str);
}

/* shift left y asigna */
bigint& bigint::operator<<=(const bigint& other)
{
    *this = *this << stringToUINT(other.str);
    return *this;
}

/* shift right y asigna */
bigint& bigint::operator>>=(const bigint& other)
{
    *this = *this >> stringToUINT(other.str);
    return *this;
}

//	==================================
//	======== COMPARACIONES ===========
//	==================================
// comparisons igual
bool bigint::operator==(const bigint& other) const
{
    return str == other.str;
}

bool bigint::operator!=(const bigint& other) const
{
    return !(*this == other);
}

// comparisons menor
bool bigint::operator<(const bigint& other) const
{
    if (str.length() != other.str.length())
        return str.length() < other.str.length();

    return str < other.str;
}

// comparisons mayor
bool bigint::operator>(const bigint& other) const
{
    return other < *this;
}

// comparisons menor igual
bool bigint::operator<=(const bigint& other) const
{
    return !(*this > other);
}

// comparisons mayor igual
bool bigint::operator>=(const bigint& other) const
{
    return !(*this < other);
}

// print cout
std::ostream& operator<<(std::ostream& os, const bigint& obj)
{
    os << obj.getStr();
    return os;
}