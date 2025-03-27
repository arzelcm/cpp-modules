#include "Harl.hpp"

Harl::Harl(void)
{
	this->complains[0] = "DEBUG";
	this->complains[1] = "INFO";
	this->complains[2] = "WARNING";
	this->complains[3] = "ERROR";
	this->complainsFun[0] = &Harl::debug;
	this->complainsFun[1] = &Harl::info;
	this->complainsFun[2] = &Harl::warning;
	this->complainsFun[3] = &Harl::error;
}

std::string *Harl::getComplains(void)
{
	return this->complains;
}

void Harl::complain(std::string level)
{
	for (int i = 0; i < COMPLAINS_AMOUNT; i++)
	{
		if (this->complains[i] == level)
		{
			(this->*complainsFun[i])();
			break;
		}
	}
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
