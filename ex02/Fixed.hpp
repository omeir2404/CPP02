#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
private:
	int _fixedPointValue;
	static const int _fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed(const int value);
	Fixed(const float value);
	Fixed &operator=(const Fixed &other);
	~Fixed();
	int toInt(void) const;
	float toFloat(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);
    friend std::ostream& operator<<(std::ostream& os, const Fixed& obj);
	
	friend bool operator>(const Fixed& a, const Fixed& b);
	friend bool operator<(const Fixed& a, const Fixed& b);
	friend bool operator>=(const Fixed& a, const Fixed& b);
	friend bool operator<=(const Fixed& a, const Fixed& b);
	friend bool operator==(const Fixed& a, const Fixed& b);
	friend bool operator!=(const Fixed& a, const Fixed& b);

	Fixed operator+(const Fixed& other);
	Fixed operator-(const Fixed& other);
	Fixed operator*(const Fixed& other);
	Fixed operator/(const Fixed& other);

	Fixed& operator++(); //pre-increment
	Fixed operator++(int); //post-increment
	Fixed& operator--();
	Fixed operator--(int);

	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
};

#endif