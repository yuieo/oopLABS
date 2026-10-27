#include <iostream>
#include <stdexcept>

/** @brief Денежная сумма, хранящаяся в копейках. */
class Money
{
private:
    long long totalKopecks; ///< Общее количество копеек.
    static int objectCount; ///< Количество существующих объектов Money.

public:
    /** @brief Создаёт нулевую сумму. */
    Money() : totalKopecks(0)
    {
        ++objectCount;
    }

    /**
     * @brief Создаёт сумму из количества копеек.
     * @param kopecks Неотрицательное количество копеек.
     * @throws std::invalid_argument Если сумма отрицательная.
     */
    explicit Money(long long kopecks) : totalKopecks(kopecks)
    {
        if (kopecks < 0) {
            throw std::invalid_argument("Сумма не может быть отрицательной.");
        }
        ++objectCount;
    }

    /** @brief Копирует сумму. @param other Копируемый объект. */
    Money(const Money& other) : totalKopecks(other.totalKopecks)
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

    /** @brief Выводит сумму в рублях и копейках. */
    void print() const
    {
        std::cout << totalKopecks / 100 << " руб. "
                  << totalKopecks % 100 << " коп.\n";
    }
};

int Money::objectCount = 0;

/** @brief Демонстрирует создание и уничтожение объектов. @return Код завершения программы. */
int main()
{
    std::cout << "Объектов до создания: " << Money::getObjectCount() << '\n';

    {
        Money amount;
        Money payment(12550);
        Money copy(payment);

        // Money wrong = 12550; // explicit запрещает неявное преобразование.

        amount.print();
        payment.print();
        copy.print();

        std::cout << "Объектов после создания: " << Money::getObjectCount() << '\n';
    }

    std::cout << "Объектов после уничтожения: " << Money::getObjectCount() << '\n';
    return 0;
}
