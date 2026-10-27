#include "Money.h"
#include "BankAccount.h"

#include <iostream>
#include <stdexcept>
#include <cassert>

/**
 * @file main.cpp
 * @brief Демонстрация и проверка программы «Счёт в банке».
 */

/**
 * @brief Демонстрирует операторы Money и операции банковского счёта.
 * @return Код завершения программы.
 * @note Проверки assert работают при сборке без определения NDEBUG.
 */
int main()
{
    assert(Money::getObjectCount() == 0);
    std::cout << "=== Денежные суммы и операторы ===\n";
    std::cout << "Объектов до создания: " << Money::getObjectCount() << '\n';

    {
        Money amount;
        const Money payment(12550);
        Money copy(payment);
        assert(Money::getObjectCount() == 3);

        // Money wrong = 12550; // explicit запрещает неявное преобразование.

        std::cout << "\nНачальная сумма amount: ";
        amount.print();
        assert(payment.getPrintCount() == 0);
        std::cout << "\nВыводов payment до обращения: " << payment.getPrintCount() << '\n';
        payment.print();
        std::cout << "Выводов payment после обращения: " << payment.getPrintCount() << '\n';
        assert(payment.getPrintCount() == 1);
        std::cout << "Копия payment: ";
        copy.print();

        amount += payment;
        std::cout << "\nПосле прибавления: ";
        amount.print();

        amount -= Money(2550);
        std::cout << "После вычитания: ";
        amount.print();

        try {
            amount -= payment;
        }
        catch (const std::invalid_argument& error) {
            std::cout << "Отказ: " << error.what() << '\n';
        }
        std::cout << "После отклонённой операции: ";
        amount.print();

        amount *= 3;
        std::cout << "\nПосле умножения на 3: ";
        amount.print();

        amount /= 7;
        std::cout << "После деления на 7: ";
        amount.print();

        try {
            amount /= 0;
        }
        catch (const std::invalid_argument& error) {
            std::cout << "Отказ: " << error.what() << '\n';
        }
        std::cout << "После попытки деления на ноль: ";
        amount.print();

        std::cout << "\npayment + 24 руб. 50 коп.: ";
        (payment + Money(2450)).print();

        std::cout << "payment - 25 руб. 50 коп.: ";
        (payment - Money(2550)).print();

        std::cout << "payment * 2: ";
        (payment * 2).print();

        std::cout << "payment / 2: ";
        (payment / 2).print();

        std::cout << "Исходная сумма payment: ";
        payment.print();

        std::cout << "\nРезультат ++copy: ";
        (++copy).print();

        std::cout << "Результат copy++ (старая сумма): ";
        (copy++).print();
        std::cout << "copy после copy++: ";
        copy.print();

        std::cout << "\nРезультат --copy: ";
        (--copy).print();

        std::cout << "Результат copy-- (старая сумма): ";
        (copy--).print();
        std::cout << "copy после copy--: ";
        copy.print();

        assert(amount == Money(4285));
        assert(payment == Money(12550));
        assert(copy == payment);

        std::cout << "\n=== Сравнение сумм ===\n";
        std::cout << "amount: " << amount.toString() << '\n';
        std::cout << "payment: " << payment.toString() << '\n';
        std::cout << "copy: " << copy.toString() << '\n';
        std::cout << "\ncopy == payment (равны): " << (copy == payment ? "да" : "нет") << '\n';
        std::cout << "copy != payment (различаются): " << (copy != payment ? "да" : "нет") << '\n';
        std::cout << "amount < payment (меньше): " << (amount < payment ? "да" : "нет") << '\n';
        std::cout << "amount > payment (больше): " << (amount > payment ? "да" : "нет") << '\n';
        std::cout << "copy <= payment (меньше или равно): " << (copy <= payment ? "да" : "нет") << '\n';
        std::cout << "copy >= payment (больше или равно): " << (copy >= payment ? "да" : "нет") << '\n';

        std::cout << "\nОбъектов после создания: " << Money::getObjectCount() << '\n';
    }

    std::cout << "Объектов после уничтожения: " << Money::getObjectCount() << '\n';
    assert(Money::getObjectCount() == 0);

    std::cout << "\n=== Банковские счета ===\n";
    {
        BankAccount account("Иван");
        account.print();
        account.printHistory();

        account.deposit(Money(100000));
        std::cout << "\nПосле зачисления 1000 рублей:\n";
        account.print();

        account.withdraw(Money(25000));
        std::cout << "\nПосле снятия 250 рублей:\n";
        account.print();

        try {
            account.withdraw(Money(100000));
        }
        catch (const std::invalid_argument& error) {
            std::cout << "\nОтказ при снятии 1000 рублей: " << error.what() << '\n';
        }
        std::cout << "Счёт после отклонённой операции:\n";
        account.print();

        BankAccount recipient("Анна");
        account.transfer(recipient, Money(25000));
        std::cout << "\nПосле перевода 250 рублей от Ивана Анне:\n";
        account.print();
        recipient.print();

        try {
            account.transfer(recipient, Money(100000));
        }
        catch (const std::invalid_argument& error) {
            std::cout << "\nОтказ при переводе 1000 рублей: " << error.what() << '\n';
        }
        std::cout << "Счета после отклонённого перевода:\n";
        account.print();
        recipient.print();

        std::cout << '\n';
        account.printHistory();
        std::cout << '\n';
        recipient.printHistory();
    }

    assert(Money::getObjectCount() == 0);
    std::cout << "\nДемонстрация завершена. Все встроенные проверки пройдены.\n";
    return 0;
}
