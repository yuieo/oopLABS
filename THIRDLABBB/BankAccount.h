/** @file BankAccount.h @brief Объявление класса банковского счёта. */

#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H

#include "Money.h"

#include <string>
#include <vector>

/** @brief Банковский счёт с владельцем, балансом и историей успешных операций. */
class BankAccount
{
private:
    std::string owner; ///< Имя владельца счёта.
    Money balance; ///< Сумма на счёте.
    std::vector<std::string> history; ///< Записи успешных операций за текущий запуск.

public:
    /**
     * @brief Создаёт счёт с нулевым балансом.
     * @param ownerName Имя владельца счёта.
     */
    explicit BankAccount(const std::string& ownerName);

    /**
     * @brief Зачисляет деньги на счёт.
     * @param amount Положительная сумма зачисления.
     * @throws std::invalid_argument Если сумма равна нулю.
     * @throws std::overflow_error Если баланс стал бы слишком большим.
     */
    void deposit(const Money& amount);

    /**
     * @brief Снимает деньги со счёта.
     * @param amount Положительная сумма снятия.
     * @throws std::invalid_argument Если сумма равна нулю или превышает баланс.
     */
    void withdraw(const Money& amount);

    /**
     * @brief Переводит деньги на другой счёт.
     * @param recipient Счёт получателя.
     * @param amount Положительная сумма перевода.
     * @throws std::invalid_argument При нулевой сумме, нехватке денег
     * или переводе на тот же счёт.
     * @throws std::overflow_error При переполнении баланса получателя.
     * @note При отказе оба баланса сохраняются.
     */
    void transfer(BankAccount& recipient, const Money& amount);

    /** @brief Выводит владельца и баланс счёта. */
    void print() const;

    /** @brief Выводит историю успешных операций в порядке выполнения. */
    void printHistory() const;
};

#endif
