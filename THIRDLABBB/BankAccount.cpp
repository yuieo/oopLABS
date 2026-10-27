/** @file BankAccount.cpp @brief Реализация банковского счёта. */

#include "BankAccount.h"

#include <iostream>
#include <stdexcept>

BankAccount::BankAccount(const std::string& ownerName)
    : owner(ownerName), balance()
{
}

void BankAccount::deposit(const Money& amount)
{
    if (amount == Money(0)) {
        throw std::invalid_argument("Сумма зачисления должна быть положительной.");
    }
    balance += amount;
}

void BankAccount::withdraw(const Money& amount)
{
    if (amount == Money(0)) {
        throw std::invalid_argument("Сумма снятия должна быть положительной.");
    }
    balance -= amount;
}

void BankAccount::transfer(BankAccount& recipient, const Money& amount)
{
    if (this == &recipient) {
        throw std::invalid_argument("Нельзя перевести деньги на тот же счёт.");
    }
    if (amount == Money(0)) {
        throw std::invalid_argument("Сумма перевода должна быть положительной.");
    }
    if (amount > balance) {
        throw std::invalid_argument("Недостаточно денег для перевода.");
    }

    recipient.balance += amount;
    balance -= amount;
}

void BankAccount::print() const
{
    std::cout << "Владелец счёта: " << owner << '\n';
    std::cout << "Баланс: ";
    balance.print();
}
