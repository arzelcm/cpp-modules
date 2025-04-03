#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
	this->_value = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed::Fixed(const int integer)
{
	this->_value = integer << this->fractBits;
}

Fixed::Fixed(const float floating)
{
	this->_value = roundf(floating * (1 << this->fractBits));
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	if (this == &fixed)
		return *this;
	this->_value = fixed.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return this->_value > fixed.getRawBits();
}

bool Fixed::operator<(const Fixed &fixed) const
{
	return this->_value < fixed.getRawBits();
}

bool Fixed::operator>=(const Fixed &fixed) const
{
	return this->_value >= fixed.getRawBits();
}

bool Fixed::operator<=(const Fixed &fixed) const
{
	return this->_value <= fixed.getRawBits();
}

bool Fixed::operator==(const Fixed &fixed) const
{
	return this->_value == fixed.getRawBits();
}

bool Fixed::operator!=(const Fixed &fixed) const
{
	return this->_value != fixed.getRawBits();
}

Fixed Fixed::operator+(const Fixed &fixed)
{
	Fixed _new = *this;
	_new.setRawBits(this->getRawBits() + fixed.getRawBits());
	return _new;
}

Fixed Fixed::operator-(const Fixed &fixed)
{
	Fixed _new = *this;
	_new.setRawBits(this->getRawBits() - fixed.getRawBits());
	return _new;
}

Fixed Fixed::operator*(const Fixed &fixed)
{
	Fixed _new = *this;
	this->_value *= fixed.getRawBits();
	this->_value = this->_value >> this->fractBits;
	return _new;
}

Fixed Fixed::operator/(const Fixed &fixed)
{
	Fixed _new = *this;
	_new.setRawBits((float)_new.getRawBits() / fixed.getRawBits() * (1 << this->fractBits));
	return _new;
}

Fixed &Fixed::operator++(void)
{
	this->_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed f = *this;
	this->_value++;
	return f;
}

int Fixed::getRawBits(void) const
{
	return this->_value;
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return (float)this->_value / (1 << this->fractBits);
}

int Fixed::toInt(void) const
{
	return this->_value >> this->fractBits;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

Fixed::~Fixed(void)
{
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return os;
}