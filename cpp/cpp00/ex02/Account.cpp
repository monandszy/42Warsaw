#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Orthodox

void Account::displayAccountsInfos(void)
{
  
}

/* https://stackoverflow.com/questions/997946/how-can-i-get-current-time-and-date-in-c 

1992 01 04 _ 09 15 32
*/

void printCurrentDateTime()
{
  time_t t = std::time(0);
  std::tm now = *std::localtime(&t);
  char buf[80];
  strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", &now);
  std::cout << buf;
}

Account::Account(int initial_deposit)
{
  static int acc_index = 0;
  _accountIndex = acc_index;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
  printCurrentDateTime();
  std::cout << "index:" << _accountIndex;
  std::cout << ";ammount:" << _amount;
  std::cout << ";created" << std::endl;
  acc_index++;
}

Account::~Account(void)
{}

// Domain methods

void Account::makeDeposit(int deposit)
{
  (void) deposit;
}

bool Account::makeWithdrawal(int withdrawal)
{
  (void) withdrawal;
  return (true);
}

int Account::checkAmount(void) const
{
 return _amount; 
}

void Account::displayStatus(void) const
{
  
}

void Account::_displayTimestamp(void)
{
  
}

// Static Getters
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