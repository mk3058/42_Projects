#include "Account.hpp"

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

// void Account::_displayTimestamp() {
//     std::cout << "[19920104_091532] ";
// }

void Account::_displayTimestamp() {
    std::time_t now_time;
    std::time(&now_time);
    struct tm *local_time = std::localtime(&now_time);

    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", local_time);
    std::cout << buffer << " ";
}

Account::Account(int initial_deposit)
    : _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0),
      _nbWithdrawals(0) {
    Account::_totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << checkAmount()
              << ";created" << std::endl;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << checkAmount()
              << ";closed" << std::endl;
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts
              << ";total:" << Account::_totalAmount
              << ";deposits:" << Account::_totalNbDeposits
              << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << checkAmount()
              << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << checkAmount() << ";deposit:" << deposit;
    this->_amount += deposit;
    this->_nbDeposits++;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
    std::cout << ";amount:" << checkAmount()
              << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

int Account::checkAmount() const { return (this->_amount); }

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << checkAmount() << ";withdrawal:";
    if (withdrawal > checkAmount()) {
        std::cout << "refused" << std::endl;
        return (false);
    }
    this->_amount -= withdrawal;
    this->_nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    Account::_totalAmount -= withdrawal;
    std::cout << withdrawal << ";amount:" << checkAmount()
              << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
}