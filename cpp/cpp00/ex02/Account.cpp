#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Orthodox
// [19920104_091532] index:0;amount:42;created
Account::Account(int initial_deposit)
{
  _accountIndex = _nbAccounts;
	_amount = initial_deposit;
  _totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex;
  std::cout << ";amount:" << _amount;
  std::cout << ";created" << std::endl;
  _nbAccounts++;
}

Account::~Account(void)
{
  _displayTimestamp();
  std::cout << "index:" << _accountIndex;
  std::cout << ";amount:" << _amount;
  std::cout << ";closed" << std::endl;
}

// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void Account::displayAccountsInfos(void)
{
  _displayTimestamp();
  std::cout << "accounts:" << _nbAccounts;
  std::cout << ";total:" << _totalAmount;
  std::cout << ";deposits:" << _totalNbDeposits;
  std::cout << ";withdrawals:" << _totalNbWithdrawals;
  std::cout << std::endl;
}

// Domain methods
// index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void Account::makeDeposit(int deposit)
{
  _displayTimestamp();
  std::cout << "index:" << _accountIndex;
  std::cout << ";p_amount:" << _amount;
  std::cout << ";deposit:" << deposit;
  _amount += deposit;
  _totalAmount += deposit;
  _nbDeposits++;
  _totalNbDeposits++;
  std::cout << ";amount:" << _amount;
  std::cout << ";nb_deposits:" << _nbDeposits;
  std::cout << std::endl;
  (void) deposit;
}
// [19920104_091532] index:0;p_amount:47;withdrawal:refused
// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool Account::makeWithdrawal(int withdrawal)
{
  _displayTimestamp();
  std::cout << "index:" << _accountIndex;
  std::cout << ";p_amount:" << _amount;
  if (withdrawal > _amount)
    std::cout << ";withdrawal:refused";
  else
  {
    std::cout << ";withdrawal:" << withdrawal;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << ";amount:" << _amount;
    std::cout << ";nb_withdrawals:" << _nbWithdrawals;
  }
  std::cout << std::endl;
  return (true);
}

int Account::checkAmount(void) const
{
 return _amount; 
}

// index:0;amount:42;deposits:0;withdrawals:0
void Account::displayStatus(void) const
{
  _displayTimestamp();
  std::cout << "index:" << _accountIndex;
  std::cout << ";amount:" << _amount;
  std::cout << ";deposits:" << _nbDeposits;
  std::cout << ";withdrawals:" << _nbWithdrawals;
  std::cout << std::endl;
}

/* https://stackoverflow.com/questions/997946/how-can-i-get-current-time-and-date-in-c 

1992 01 04 _ 09 15 32
*/
void Account::_displayTimestamp(void)
{
  time_t t = std::time(0);
  std::tm now = *std::localtime(&t);
  char buf[80];
  strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", &now);
  std::cout << buf;
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