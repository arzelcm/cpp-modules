#pragma once

class Fixed
{
private:
	int _value;
	static const int fractBits = 8;

public:
	Fixed(void);
	Fixed(const Fixed &fixed);
	Fixed(const int integer);
	Fixed(const float floating);
	Fixed &operator=(const Fixed &fixed);
	bool operator>(const Fixed &fixed) const;
	bool operator<(const Fixed &fixed) const;
	bool operator>=(const Fixed &fixed) const;
	bool operator<=(const Fixed &fixed) const;
	bool operator==(const Fixed &fixed) const;
	bool operator!=(const Fixed &fixed) const;
	Fixed &operator+(const Fixed &fixed);
	Fixed &operator-(const Fixed &fixed);
	Fixed &operator*(const Fixed &fixed);
	Fixed &operator/(const Fixed &fixed);
	Fixed &operator++(void);
	Fixed operator++(int);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);
	~Fixed(void);
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);