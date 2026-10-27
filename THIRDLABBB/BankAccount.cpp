/** @file BankAccount.cpp @brief Реализация банковского счёта. */

#include "BankAccount.h"

#include <iostream>

BankAccount::BankAccount(const std::string& ownerName)
    : owner(ownerName), balance()
{
}

void BankAccount::print() const
{
    std::cout << "Владелец счёта: " << owner << '\n';
    std::cout << "Баланс: ";
    balance.print();
}
