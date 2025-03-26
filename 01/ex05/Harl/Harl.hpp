#pragma once
#include <iostream>
#define COMPLAINS_AMOUNT 4

class Harl
{
public:
	Harl();
	void complain(std::string level);

private:
	std::string complains[COMPLAINS_AMOUNT];
	void (Harl::* complainsFun[COMPLAINS_AMOUNT])(void);
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};