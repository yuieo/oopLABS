/** @file BankAccount.cpp @brief Реализация банковского счёта. */

#include "BankAccount.h"

#include <iostream>
#include <stdexcept>
#include <utility>

BankAccount::BankAccount(const std::string& ownerName)
    : owner(ownerName), balance()
{
}

void BankAccount::deposit(const Money& amount)
{
    if (amount == Money(0)) {
        throw std::invalid_argument("Сумма зачисления должна быть положительной.");
    }
    std::string record = "Зачисление: " + amount.toString();
    // Готовим строку и место для неё до изменения баланса.
    history.reserve(history.size() + 1);
    balance += amount;
    history.push_back(std::move(record));
}

void BankAccount::withdraw(const Money& amount)
{
    if (amount == Money(0)) {
        throw std::invalid_argument("Сумма снятия должна быть положительной.");
    }
    std::string record = "Снятие: " + amount.toString();
    history.reserve(history.size() + 1);
    balance -= amount;
    history.push_back(std::move(record));
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

    std::string outgoing = "Перевод на счёт «" + recipient.owner + "»: " + amount.toString();
    std::string incoming = "Перевод со счёта «" + owner + "»: " + amount.toString();
    history.reserve(history.size() + 1);
    recipient.history.reserve(recipient.history.size() + 1);

    recipient.balance += amount;
    balance -= amount;
    history.push_back(std::move(outgoing));
    recipient.history.push_back(std::move(incoming));
}

void BankAccount::print() const
{
    std::cout << "Владелец счёта: " << owner << '\n';
    std::cout << "Баланс: ";
    balance.print();
}

void BankAccount::printHistory() const
{
    std::cout << "История счёта «" << owner << "»:\n";
    if (history.empty()) {
        std::cout << "Операций пока нет.\n";
        return;
    }
    for (const std::string& record : history) {
        std::cout << record << '\n';
    }
}
