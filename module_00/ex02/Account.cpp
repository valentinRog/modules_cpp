#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
  _accountIndex = _nbAccounts;
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "amount:" << initial_deposit << ";";
  _nbAccounts++;
  _amount = initial_deposit;
  _totalAmount += initial_deposit;
  _nbDeposits = 0;
  _nbWithdrawals = 0;
  std::cout << "created" << std::endl;
}

Account::~Account() {
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

int Account::getNbAccounts() { return _nbAccounts; }

int Account::getTotalAmount() { return _totalAmount; }

int Account::getNbDeposits() { return _totalNbDeposits; }

int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void Account::displayAccountsInfos() {
  std::cout << "accounts:" << _nbAccounts << ";";
  std::cout << "total:" << _totalAmount << ";";
  std::cout << "deposits:" << _totalNbDeposits << ";";
  std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "p_amount:" << _amount << ";";
  std::cout << "deposit:" << deposit << ";";
  _amount += deposit;
  _totalAmount += deposit;
  _nbDeposits++;
  _totalNbDeposits++;
  std::cout << "amount:" << _amount << ";";
  std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "p_amount:" << _amount << ";";
  if (withdrawal > _amount) {
	std::cout << "withdrawal:refused" << std::endl;
	return false;
  }
  std::cout << "withdrawal:" << withdrawal << ";";
  _amount -= withdrawal;
  _totalAmount -= withdrawal;
  _nbWithdrawals++;
  _totalNbWithdrawals++;
  std::cout << "amount:" << _amount << ";";
  std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
  return true;
}

int Account::checkAmount(void) const {
	return _amount >= 0;
}

void Account::displayStatus(void) const {
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "amount:" << _amount << ";";
  std::cout << "deposits:" << _nbDeposits << ";";
  std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}
