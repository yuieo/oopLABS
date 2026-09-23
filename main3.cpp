/**
* @file main3.cpp
 * @brief Работа со структурой безопасного массива.
 */

#include <iostream>

/**
 * @brief Хранит указатель на элементы массива и его размер.
 */
struct SafeArray {
    int* data; ///< Указатель на элементы массива.
    int size;  ///< Количество элементов.
};

/**
 * @brief Создаёт пустую структуру SafeArray.
 * @return Код завершения: 0 — успешное выполнение.
 */
int main()
{
    SafeArray myArr{nullptr, 0};

    std::cout << "Размер массива: " << myArr.size << '\n';

    return 0;
}