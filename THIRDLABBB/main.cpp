#include <iostream>
#include <stdexcept>
#include <climits>

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

    /**
     * @brief Прибавляет другую денежную сумму.
     * @param other Прибавляемая сумма.
     * @return Ссылка на изменённый объект.
     * @throws std::overflow_error Если результат не помещается в long long.
     */
    Money& operator+=(const Money& other)
    {
        if (other.totalKopecks > LLONG_MAX - totalKopecks) {
            throw std::overflow_error("Сумма слишком большая.");
        }
        totalKopecks += other.totalKopecks;
        return *this;
    }

    /**
     * @brief Вычитает другую денежную сумму.
     * @param other Вычитаемая сумма.
     * @return Ссылка на изменённый объект.
     * @throws std::invalid_argument Если результат был бы отрицательным.
     */
    Money& operator-=(const Money& other)
    {
        if (other.totalKopecks > totalKopecks) {
            throw std::invalid_argument("Нельзя вычесть больше имеющейся суммы.");
        }
        totalKopecks -= other.totalKopecks;
        return *this;
    }

    /**
     * @brief Умножает сумму на целое число.
     * @param factor Неотрицательный множитель.
     * @return Ссылка на изменённый объект.
     * @throws std::invalid_argument Если множитель отрицательный.
     * @throws std::overflow_error Если результат не помещается в long long.
     */
    Money& operator*=(long long factor)
    {
        if (factor < 0) {
            throw std::invalid_argument("Множитель не может быть отрицательным.");
        }
        if (factor != 0 && totalKopecks > LLONG_MAX / factor) {
            throw std::overflow_error("Сумма слишком большая.");
        }
        totalKopecks *= factor;
        return *this;
    }

    /**
     * @brief Делит сумму на целое число, отбрасывая доли копейки.
     * @param divisor Положительный делитель.
     * @return Ссылка на изменённый объект.
     * @throws std::invalid_argument Если делитель равен нулю или отрицательный.
     */
    Money& operator/=(long long divisor)
    {
        if (divisor <= 0) {
            throw std::invalid_argument("Делитель должен быть положительным.");
        }
        totalKopecks /= divisor;
        return *this;
    }

    /**
     * @brief Складывает суммы, не изменяя исходные объекты.
     * @param other Второе слагаемое.
     * @return Новая сумма. Ошибки сложения передаются из operator+=.
     */
    Money operator+(const Money& other) const
    {
        Money result(*this);
        result += other;
        return result;
    }

    /**
     * @brief Вычитает сумму, не изменяя исходные объекты.
     * @param other Вычитаемая сумма.
     * @return Новая сумма. Ошибки вычитания передаются из operator-=.
     */
    Money operator-(const Money& other) const
    {
        Money result(*this);
        result -= other;
        return result;
    }

    /**
     * @brief Умножает сумму на число, не изменяя исходный объект.
     * @param factor Неотрицательный целый множитель.
     * @return Новая сумма. Ошибки умножения передаются из operator*=.
     */
    Money operator*(long long factor) const
    {
        Money result(*this);
        result *= factor;
        return result;
    }

    /**
     * @brief Делит сумму на число, не изменяя исходный объект.
     * @param divisor Положительный целый делитель.
     * @return Новая сумма без долей копейки. Ошибки передаются из operator/=.
     */
    Money operator/(long long divisor) const
    {
        Money result(*this);
        result /= divisor;
        return result;
    }

    /**
     * @brief Префиксно прибавляет одну копейку.
     * @return Ссылка на увеличенный объект.
     * @throws std::overflow_error Если сумма уже максимальная.
     */
    Money& operator++()
    {
        *this += Money(1);
        return *this;
    }

    /**
     * @brief Постфиксно прибавляет одну копейку.
     * @return Копия суммы до увеличения.
     * @throws std::overflow_error Если сумма уже максимальная.
     * @note Неименованный параметр int отличает постфиксную форму от префиксной.
     */
    Money operator++(int)
    {
        Money old(*this);
        ++(*this);
        return old;
    }

    /**
     * @brief Префиксно вычитает одну копейку.
     * @return Ссылка на уменьшенный объект.
     * @throws std::invalid_argument Если сумма равна нулю.
     */
    Money& operator--()
    {
        *this -= Money(1);
        return *this;
    }

    /**
     * @brief Постфиксно вычитает одну копейку.
     * @return Копия суммы до уменьшения.
     * @throws std::invalid_argument Если сумма равна нулю.
     * @note Неименованный параметр int отличает постфиксную форму от префиксной.
     */
    Money operator--(int)
    {
        Money old(*this);
        --(*this);
        return old;
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

/** @brief Демонстрирует объекты Money и арифметические операторы. @return Код завершения программы. */
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

        std::cout << "Объектов после создания: " << Money::getObjectCount() << '\n';
    }

    std::cout << "Объектов после уничтожения: " << Money::getObjectCount() << '\n';
    return 0;
}
