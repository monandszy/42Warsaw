#include "Account.hpp"
#include "Utils.hpp"
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
	_nbDeposits = 0;
	_nbWithdrawals = 0;
  printCurrentDateTime();
  std::cout << "index:" << _accountIndex;
  std::cout << ";ammount:" << _amount;
  std::cout << ";created" << std::endl;
  _nbAccounts++;
}

Account::~Account(void)
{}

// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void Account::displayAccountsInfos(void)
{
  printCurrentDateTime();
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
  printCurrentDateTime();
  std::cout << "index:" << _accountIndex;
  std::cout << ";p_ammount:" << _amount;
  std::cout << ";deposit:" << deposit;
  _amount += deposit;
  _nbDeposits++;
  std::cout << ";ammount:" << _amount;
  std::cout << ";nb_deposit:" << _nbDeposits;
  std::cout << std::endl;
  (void) deposit;
}
// [19920104_091532] index:0;p_amount:47;withdrawal:refused
// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool Account::makeWithdrawal(int withdrawal)
{
  (void) withdrawal;
  return (true);
}

int Account::checkAmount(void) const
{
 return _amount; 
}

// index:0;amount:42;deposits:0;withdrawals:0
void Account::displayStatus(void) const
{
  printCurrentDateTime();
  std::cout << "index:" << _accountIndex;
  std::cout << ";ammount:" << _amount;
  std::cout << ";deposits:" << _nbDeposits;
  std::cout << ";withdrawals:" << _nbWithdrawals;
  std::cout << std::endl;
}

void Account::_displayTimestamp(void)
{
  std::cout << "TIME";
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