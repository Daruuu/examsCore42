#include "bigint02.hpp"
#include <algorithm>
#include <cctype>

bigint::bigint() {
    digits_.push_back(0);
}

bigint::bigint(unsigned long n) {
    from_unsigned_long(n);
}

bigint::bigint(const bigint& other) {
    digits_ = other.digits_;
}

bigint& bigint::operator=(const bigint& other) {
    if (this != &other) {
        digits_ = other.digits_;
    }
    return *this;
}

// ------------------------------------------------------------------
// Utilidades internas
// ------------------------------------------------------------------
void bigint::from_unsigned_long(unsigned long n) {
    digits_.clear();
    if (n == 0) {
        digits_.push_back(0);
        return;
    }
    while (n > 0) {
        digits_.push_back(static_cast<unsigned char>(n % 10));
        n /= 10;
    }
}

void bigint::normalize() {
    while (digits_.size() > 1 && digits_.back() == 0)
        digits_.pop_back();
}

// ------------------------------------------------------------------
// Comparaciones
// ------------------------------------------------------------------
bool bigint::operator==(const bigint& other) const {
    return digits_ == other.digits_;
}

bool bigint::operator!=(const bigint& other) const {
    return !(*this == other);
}

bool bigint::operator<(const bigint& other) const {
    if (digits_.size() != other.digits_.size())
        return digits_.size() < other.digits_.size();

    for (int i = (int)digits_.size() - 1; i >= 0; --i) {
        if (digits_[i] != other.digits_[i])
            return digits_[i] < other.digits_[i];
    }
    return false; // iguales
}

bool bigint::operator<=(const bigint& other) const {
    return *this < other || *this == other;
}

bool bigint::operator>(const bigint& other) const {
    return other < *this;
}

bool bigint::operator>=(const bigint& other) const {
    return !(*this < other);
}

// ------------------------------------------------------------------
// Suma
// ------------------------------------------------------------------

// Suma con entero pequeño (bigint + unsigned long)
bigint bigint::operator+(unsigned long n) const {
    return *this + bigint(n);
}

bigint& bigint::operator+=(unsigned long n) {
    *this = *this + bigint(n);
    return *this;
}


bigint bigint::operator+(const bigint& other) const {
    bigint result;
    result.digits_.clear();

    std::size_t max_size = std::max(digits_.size(), other.digits_.size());
    unsigned char carry = 0;

    for (std::size_t i = 0; i < max_size || carry; ++i) {
        unsigned char sum = carry;
        if (i < digits_.size())     sum += digits_[i];
        if (i < other.digits_.size()) sum += other.digits_[i];
        result.digits_.push_back(sum % 10);
        carry = sum / 10;
    }
    result.normalize();
    return result;
}

bigint& bigint::operator+=(const bigint& other) {
    *this = *this + other;
    return *this;
}

// ------------------------------------------------------------------
// Incremento
// ------------------------------------------------------------------
bigint& bigint::operator++() {        // pre-incremento
    *this += bigint(1UL);
    return *this;
}

bigint bigint::operator++(int) {      // post-incremento
    bigint old = *this;
    ++(*this);
    return old;
}

// ------------------------------------------------------------------
// Digit shift izquierdo (multiplicar por 10^n)
// ------------------------------------------------------------------
bigint bigint::operator<<(unsigned long n) const {
    if (digits_.size() == 1 && digits_[0] == 0)
        return bigint(0UL);

    bigint result = *this;
    result.digits_.insert(result.digits_.begin(), n, 0);
    return result;
}

bigint& bigint::operator<<=(unsigned long n) {
    if (digits_.size() == 1 && digits_[0] == 0)
        return *this;
    digits_.insert(digits_.begin(), n, 0);
    return *this;
}

// ------------------------------------------------------------------
// Digit shift derecho (dividir por 10^n)
// ------------------------------------------------------------------
bigint bigint::operator>>(const bigint& n) const {
    unsigned long shift = 0;
    // Convertir n a unsigned long (seguro porque el main usa 2)
    for (std::size_t i = n.digits_.size(); i-- > 0; ) {
        shift = shift * 10 + n.digits_[i];
    }

    if (shift >= digits_.size())
        return bigint(0UL);

    bigint result = *this;
    result.digits_.erase(result.digits_.begin(),
                         result.digits_.begin() + shift);
    result.normalize();
    return result;
}

bigint& bigint::operator>>=(const bigint& n) {
    *this = *this >> n;
    return *this;
}

// ------------------------------------------------------------------
// Salida
// ------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os, const bigint& b) {
    if (b.digits_.empty()) {
        os << "0";
        return os;
    }
    for (int i = (int)b.digits_.size() - 1; i >= 0; --i)
        os << (int)b.digits_[i];
    return os;
}
