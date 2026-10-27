#include <iostream>

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

    /** @brief Выводит сумму в рублях и копейках. */
    void print() const
    {
        std::cout << totalKopecks / 100 << " руб. "
                  << totalKopecks % 100 << " коп.\n";
    }
};

/** @brief Создаёт и выводит нулевую сумму. @return Код завершения программы. */
int main()
{
    Money amount;
    amount.print();
    return 0;
}
