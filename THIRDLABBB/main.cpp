#include <iostream>
#include <stdexcept>

/** @brief Денежная сумма, хранящаяся в копейках. */
class Money
{
private:
    long long totalKopecks; ///< Общее количество копеек.

public:
    /** @brief Создаёт нулевую сумму. */
    Money() : totalKopecks(0)
    {
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
    }

    /** @brief Копирует сумму. @param other Копируемый объект. */
    Money(const Money& other) : totalKopecks(other.totalKopecks)
    {
    }

    /** @brief Выводит сумму в рублях и копейках. */
    void print() const
    {
        std::cout << totalKopecks / 100 << " руб. "
                  << totalKopecks % 100 << " коп.\n";
    }
};

/** @brief Демонстрирует три конструктора. @return Код завершения программы. */
int main()
{
    Money amount;
    Money payment(12550);
    Money copy(payment);

    // Money wrong = 12550; // explicit запрещает неявное преобразование.

    amount.print();
    payment.print();
    copy.print();
    return 0;
}
