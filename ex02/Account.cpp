#include "Account.hpp"
#include <ctime>
#include <iostream>
#include <ostream>

//---------------
// Static methods
//---------------

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts()
{
	return (_nbAccounts);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void Account::_displayTimestamp()
{
	char res[20];
	std::time_t t = time(0);
	std::tm *rt = localtime(&t);
	std::strftime(res, 19, "[%Y%m%d_%H%M%S] ", rt);
	std::cout << res;
}

void Account::displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() << ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

//--------------
//Normal methods
//--------------

Account::~Account()
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_displayTimestamp();
	std::cout << "index:";
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	std::cout << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;
}

void Account::makeDeposit(int deposit)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit << ";amount:" << this->_amount + deposit << ";nb_deposits:" << this->_nbDeposits + 1 << std::endl;
	this->_amount += deposit;
	this->_nbDeposits ++;
	this->_totalNbDeposits ++;
	this->_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
	if (withdrawal >= this->_amount)
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	std::cout << withdrawal << ";amount:" << this->_amount - withdrawal << ";nb_withdrawals:" << this->_nbWithdrawals + 1 << std::endl;
	this->_amount -= withdrawal;
	this->_nbWithdrawals ++;
	this->_totalNbWithdrawals ++;
	this->_totalAmount -= withdrawal;
	return (true);
}

int Account::checkAmount() const
{
	return (this->_amount);
}

void Account::displayStatus() const
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}
