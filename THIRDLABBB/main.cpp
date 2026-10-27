#include <iostream>
#include <stdexcept>

/** @brief Денежная сумма, хранящаяся в копейках. */
class Money
{
private:
    long long totalKopecks; ///< Общее количество копеек.
    mutable unsigned int printCount; ///< Счётчик вызовов print().
    static int objectCount; ///< Количество существующих объектов Money.

public:
    /** @brief Создаёт нулевую сумму. */
    Money() : totalKopecks(0), printCount(0)
    {
        ++objectCount;
    }

    /**
     * @brief Создаёт сумму из количества копеек.
     * @param kopecks Неотрицательное количество копеек.
     * @throws std::invalid_argument Если сумма отрицательная.
     */
    explicit Money(long long kopecks) : totalKopecks(kopecks), printCount(0)
    {
        if (kopecks < 0) {
            throw std::invalid_argument("Сумма не может быть отрицательной.");
        }
        ++objectCount;
    }

    /** @brief Копирует сумму, обнуляя счётчик выводов. @param other Копируемый объект. */
    Money(const Money& other) : totalKopecks(other.totalKopecks), printCount(0)
    {
        ++objectCount;
    }

    /** @brief Уменьшает счётчик при уничтожении объекта. */
    ~Money()
    {
        --objectCount;
    }

    /** @brief Возвращает количество существующих объектов. @return Число объектов. */
    static int getObjectCount()
    {
        return objectCount;
    }

    /** @brief Возвращает счётчик выводов. @return Значение счётчика. */
    unsigned int getPrintCount() const
    {
        return printCount;
    }

    /** @brief Выводит сумму и увеличивает счётчик выводов. */
    void print() const
    {
        ++printCount;
        std::cout << totalKopecks / 100 << " руб. "
                  << totalKopecks % 100 << " коп.\n";
    }
};

int Money::objectCount = 0;

/** @brief Демонстрирует время жизни объектов и mutable. @return Код завершения программы. */
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

        std::cout << "Объектов после создания: " << Money::getObjectCount() << '\n';
    }

    std::cout << "Объектов после уничтожения: " << Money::getObjectCount() << '\n';
    return 0;
}
