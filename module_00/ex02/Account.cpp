#include "Account.hpp"
#include <ctime>
#include <iomanip>
#include <iostream>

int Account::_nbAccounts         = 0;
int Account::_totalAmount        = 0;
int Account::_totalNbDeposits    = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) {
    _displayTimestamp();
    _accountIndex = _nbAccounts;
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << initial_deposit << ";";
    _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += initial_deposit;
    _nbDeposits    = 0;
    _nbWithdrawals = 0;
    std::cout << "created" << std::endl;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "closed" << std::endl;
}

int Account::getNbAccounts() { return _nbAccounts; }

int Account::getTotalAmount() { return _totalAmount; }

int Account::getNbDeposits() { return _totalNbDeposits; }

int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";";
    std::cout << "total:" << _totalAmount << ";";
    std::cout << "deposits:" << _totalNbDeposits << ";";
    std::cout << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit( int deposit ) {
    _displayTimestamp();
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

bool Account::makeWithdrawal( int withdrawal ) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    if ( withdrawal > _amount ) {
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

int Account::checkAmount() const { return _amount >= 0; }

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp() {
    time_t now = time( 0 );
    tm    *ltm = localtime( &now );

    std::cout << "[";
    std::cout << ltm->tm_year + 1900;
    std::cout << std::setfill( '0' ) << std::setw( 2 ) << ltm->tm_mon;
    std::cout << std::setfill( '0' ) << std::setw( 2 ) << ltm->tm_mday;
    std::cout << "_";
    std::cout << std::setfill( '0' ) << std::setw( 2 ) << ltm->tm_hour;
    std::cout << std::setfill( '0' ) << std::setw( 2 ) << ltm->tm_min;
    std::cout << std::setfill( '0' ) << std::setw( 2 ) << ltm->tm_sec;
    std::cout << "] ";
}
