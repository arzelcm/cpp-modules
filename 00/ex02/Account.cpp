#include <iostream>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;
void	_displayTimestamp( void );

int Account::getNbAccounts(void)
{
	return _nbAccounts;
}
int Account::getTotalAmount(void)
{
	return _totalAmount;
}
int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}
int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts()
			  << ";total:" << Account::getTotalAmount()
			  << ";deposits:" << Account::getNbDeposits()
			  << ";withdrawals:" << Account::getNbWithdrawals()
			  << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = this->_nbAccounts++;
	if (initial_deposit < 0)
		return ;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	int	prevAmount;

	if (deposit < 0)
		return ;
	prevAmount = this->_amount;
	this->_amount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";p_amount:" << prevAmount
			  << ";deposit:" << deposit
			  << ";amount:" << this->_amount
			  << ";nb_deposits:" << this->_nbDeposits
			  << std::endl;
}
bool Account::makeWithdrawal(int withdrawal)
{
	int	prevAmount;

	prevAmount = this->_amount;;
	if (this->_amount - withdrawal > 0)
	{
		this->_amount -= withdrawal;
		this->_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
				  << ";p_amount:" << prevAmount
				  << ";withdrawal:" << withdrawal
				  << ";amount:" << this->_amount
				  << ";nb_withdrawals:" << this->_nbWithdrawals
				  << std::endl;
		return true;
	}
	else
	{
		_displayTimestamp();
		std::cout << "index:" << this->_accountIndex
				  << ";p_amount:" << prevAmount
				  << ";withdrawal:refused"
				  << std::endl;
		return false;
	}
}
int Account::checkAmount(void) const
{
	return this->_amount;
}
void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex
			  << ";amount:" << this->_amount
			  << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	std::time_t timestamp;
	std::time(&timestamp);
	char buffer[20];

	strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localtime(&timestamp));
	std::cout << "[" << buffer << "] ";
}

Account::Account(void)
{
	this->_accountIndex = this->_nbAccounts++;
}