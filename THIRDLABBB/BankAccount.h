/** @file BankAccount.h @brief Объявление класса банковского счёта. */

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include "Money.h"

#include <string>

/** @brief Банковский счёт с владельцем и балансом. */
class BankAccount
{
private:
    std::string owner; ///< Имя владельца счёта.
    Money balance; ///< Сумма на счёте.

public:
    /**
     * @brief Создаёт счёт с нулевым балансом.
     * @param ownerName Имя владельца счёта.
     */
    explicit BankAccount(const std::string& ownerName);

    /** @brief Выводит владельца и баланс счёта. */
    void print() const;
};

#endif
