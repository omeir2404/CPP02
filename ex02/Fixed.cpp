#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
}

Fixed::Fixed(const Fixed &other) {
    *this = other;
}

Fixed::Fixed(const int value) {
    this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::Fixed(const float value) {
    this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other)
        this->_fixedPointValue = other.getRawBits();
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}

Fixed::~Fixed() {
}

int Fixed::getRawBits(void) const {
    return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
    this->_fixedPointValue = raw;
}

int Fixed::toInt(void) const {
    return this->_fixedPointValue >> this->_fractionalBits;
}

float Fixed::toFloat(void) const {
    return (float)this->_fixedPointValue / (1 << this->_fractionalBits);
}

bool operator>(const Fixed& a, const Fixed& b) {
    return a.getRawBits() > b.getRawBits();
}

bool operator<(const Fixed& a, const Fixed& b) {
    return a.getRawBits() < b.getRawBits();
}

bool operator>=(const Fixed& a, const Fixed& b) {
    return a.getRawBits() >= b.getRawBits();
}

bool operator<=(const Fixed& a, const Fixed& b) {
    return a.getRawBits() <= b.getRawBits();
}

bool operator==(const Fixed& a, const Fixed& b) {
    return a.getRawBits() == b.getRawBits();
}

bool operator!=(const Fixed& a, const Fixed& b) {
    return a.getRawBits() != b.getRawBits();
}

Fixed Fixed::operator+(const Fixed& other) {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) {
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++() {
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed& Fixed::operator--() {
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    operator--();
    return tmp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return a > b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return a < b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return a > b ? a : b;
}
