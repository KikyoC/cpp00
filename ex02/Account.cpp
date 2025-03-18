#include "Account.hpp"
#include <iostream>
#include <chrono>

//---------------
// Static methods
//---------------
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
	std::chrono::time_point now = std::chrono::system_clock::now();
	auto duration = now.time_since_epoch();
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
	std::cout << milliseconds;
}

//--------------
//Normal methods
//--------------

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_nbAccounts++;
	this->_totalAmount += initial_deposit;
}

void Account::makeDeposit(int deposit)
{
	this->_amount += deposit;
	this->_nbDeposits ++;
	this->_totalNbDeposits ++;
	this->_totalAmount += deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal >= this->_amount)
		return (false);
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

}
