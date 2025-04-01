#pragma once

class Fixed
{
private:
	int _value;
	static const int fractBits = 8;

public:
	Fixed(void);
	Fixed(const Fixed &fixed);
	~Fixed(void);
	Fixed &operator=(const Fixed &fixed);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};