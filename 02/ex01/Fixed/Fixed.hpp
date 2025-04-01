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
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
	~Fixed(void);
};

std::ostream& operator<<(std::ostream& os, const Fixed &fixed);