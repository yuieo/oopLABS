#include "Money.h"
#include "BankAccount.h"

#include <iostream>
#include <stdexcept>

/** @brief Демонстрирует операторы Money и создание банковского счёта. @return Код завершения программы. */
int main()
{
    std::cout << "Объектов до создания: " << Money::getObjectCount() << '\n';

    {
        Money amount;
        const Money payment(12550);
        Money copy(payment);

        // Money wrong = 12550; // explicit запрещает неявное преобразование.

        amount.print();
        std::cout << "Выводов payment до обращения: " << payment.getPrintCount() << '\n';
        payment.print();
        std::cout << "Выводов payment после обращения: " << payment.getPrintCount() << '\n';
        copy.print();

        amount += payment;
        std::cout << "После прибавления: ";
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
        std::cout << "После умножения на 3: ";
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

        std::cout << "payment + 24 руб. 50 коп.: ";
        (payment + Money(2450)).print();

        std::cout << "payment - 25 руб. 50 коп.: ";
        (payment - Money(2550)).print();

        std::cout << "payment * 2: ";
        (payment * 2).print();

        std::cout << "payment / 2: ";
        (payment / 2).print();

        std::cout << "Исходная сумма payment: ";
        payment.print();

        std::cout << "Результат ++copy: ";
        (++copy).print();

        std::cout << "Результат copy++ (старая сумма): ";
        (copy++).print();
        std::cout << "copy после copy++: ";
        copy.print();

        std::cout << "Результат --copy: ";
        (--copy).print();

        std::cout << "Результат copy-- (старая сумма): ";
        (copy--).print();
        std::cout << "copy после copy--: ";
        copy.print();

        std::cout << std::boolalpha;
        std::cout << "copy == payment: " << (copy == payment) << '\n';
        std::cout << "copy != payment: " << (copy != payment) << '\n';
        std::cout << "amount < payment: " << (amount < payment) << '\n';
        std::cout << "amount > payment: " << (amount > payment) << '\n';
        std::cout << "copy <= payment: " << (copy <= payment) << '\n';
        std::cout << "copy >= payment: " << (copy >= payment) << '\n';

        std::cout << "Объектов после создания: " << Money::getObjectCount() << '\n';
    }

    std::cout << "Объектов после уничтожения: " << Money::getObjectCount() << '\n';

    {
        BankAccount account("Иван");
        account.print();
    }

    return 0;
}
