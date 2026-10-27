/** @file Money.h @brief Объявление класса Money. */

#ifndef MONEY_H
#define MONEY_H

/** @brief Денежная сумма, хранящаяся в копейках. */
class Money
{
private:
    long long totalKopecks; ///< Общее количество копеек.
    mutable unsigned int printCount; ///< Счётчик вызовов print().
    static int objectCount; ///< Количество существующих объектов Money.

public:
    /** @brief Создаёт нулевую сумму. */
    Money();

    /**
     * @brief Создаёт сумму из количества копеек.
     * @param kopecks Неотрицательное количество копеек.
     * @throws std::invalid_argument Если сумма отрицательная.
     */
    explicit Money(long long kopecks);

    /** @brief Копирует сумму, обнуляя счётчик выводов. @param other Копируемый объект. */
    Money(const Money& other);

    /** @brief Уменьшает счётчик при уничтожении объекта. */
    ~Money();

    /** @brief Возвращает количество существующих объектов. @return Число объектов. */
    static int getObjectCount();

    /** @brief Возвращает счётчик выводов. @return Значение счётчика. */
    unsigned int getPrintCount() const;

    /**
     * @brief Прибавляет другую денежную сумму.
     * @param other Прибавляемая сумма.
     * @return Ссылка на изменённый объект.
     * @throws std::overflow_error Если результат не помещается в long long.
     */
    Money& operator+=(const Money& other);

    /**
     * @brief Вычитает другую денежную сумму.
     * @param other Вычитаемая сумма.
     * @return Ссылка на изменённый объект.
     * @throws std::invalid_argument Если результат был бы отрицательным.
     */
    Money& operator-=(const Money& other);

    /**
     * @brief Умножает сумму на целое число.
     * @param factor Неотрицательный множитель.
     * @return Ссылка на изменённый объект.
     * @throws std::invalid_argument Если множитель отрицательный.
     * @throws std::overflow_error Если результат не помещается в long long.
     */
    Money& operator*=(long long factor);

    /**
     * @brief Делит сумму на целое число, отбрасывая доли копейки.
     * @param divisor Положительный делитель.
     * @return Ссылка на изменённый объект.
     * @throws std::invalid_argument Если делитель равен нулю или отрицательный.
     */
    Money& operator/=(long long divisor);

    /**
     * @brief Складывает суммы, не изменяя исходные объекты.
     * @param other Второе слагаемое.
     * @return Новая сумма. Ошибки сложения передаются из operator+=.
     */
    Money operator+(const Money& other) const;

    /**
     * @brief Вычитает сумму, не изменяя исходные объекты.
     * @param other Вычитаемая сумма.
     * @return Новая сумма. Ошибки вычитания передаются из operator-=.
     */
    Money operator-(const Money& other) const;

    /**
     * @brief Умножает сумму на число, не изменяя исходный объект.
     * @param factor Неотрицательный целый множитель.
     * @return Новая сумма. Ошибки умножения передаются из operator*=.
     */
    Money operator*(long long factor) const;

    /**
     * @brief Делит сумму на число, не изменяя исходный объект.
     * @param divisor Положительный целый делитель.
     * @return Новая сумма без долей копейки. Ошибки передаются из operator/=.
     */
    Money operator/(long long divisor) const;

    /**
     * @brief Префиксно прибавляет одну копейку.
     * @return Ссылка на увеличенный объект.
     * @throws std::overflow_error Если сумма уже максимальная.
     */
    Money& operator++();

    /**
     * @brief Постфиксно прибавляет одну копейку.
     * @return Копия суммы до увеличения.
     * @throws std::overflow_error Если сумма уже максимальная.
     * @note Неименованный параметр int отличает постфиксную форму от префиксной.
     */
    Money operator++(int);

    /**
     * @brief Префиксно вычитает одну копейку.
     * @return Ссылка на уменьшенный объект.
     * @throws std::invalid_argument Если сумма равна нулю.
     */
    Money& operator--();

    /**
     * @brief Постфиксно вычитает одну копейку.
     * @return Копия суммы до уменьшения.
     * @throws std::invalid_argument Если сумма равна нулю.
     * @note Неименованный параметр int отличает постфиксную форму от префиксной.
     */
    Money operator--(int);

    /**
     * @brief Проверяет равенство сумм.
     * @param other Сравниваемая сумма.
     * @return true, если суммы равны.
     */
    bool operator==(const Money& other) const;

    /**
     * @brief Проверяет неравенство сумм.
     * @param other Сравниваемая сумма.
     * @return true, если суммы различаются.
     */
    bool operator!=(const Money& other) const;

    /**
     * @brief Проверяет, меньше ли текущая сумма.
     * @param other Сравниваемая сумма.
     * @return true, если текущая сумма меньше другой.
     */
    bool operator<(const Money& other) const;

    /**
     * @brief Проверяет, больше ли текущая сумма.
     * @param other Сравниваемая сумма.
     * @return true, если текущая сумма больше другой.
     */
    bool operator>(const Money& other) const;

    /**
     * @brief Проверяет, меньше ли текущая сумма или равна другой.
     * @param other Сравниваемая сумма.
     * @return true, если текущая сумма не больше другой.
     */
    bool operator<=(const Money& other) const;

    /**
     * @brief Проверяет, больше ли текущая сумма или равна другой.
     * @param other Сравниваемая сумма.
     * @return true, если текущая сумма не меньше другой.
     */
    bool operator>=(const Money& other) const;

    /** @brief Выводит сумму и увеличивает счётчик выводов. */
    void print() const;
};

#endif
