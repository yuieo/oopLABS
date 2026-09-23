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
 * @brief Создаёт динамический массив заданного размера.
 * @param size Количество элементов, должно быть положительным.
 * @return Структура с указателем на созданный массив и его размером.
 * @pre size > 0.
 */
SafeArray createArray(int size)
{
    SafeArray arr{nullptr, 0};

    arr.data = new int[size]{};
    arr.size = size;

    return arr;
}

/**
 * @brief Создаёт массив заданного размера и освобождает его память.
 * @return 0 при успешном выполнении, 1 при ошибке ввода.
 */
int main()
{
    int size{};

    std::cout << "Введите размер массива: ";

    if (!(std::cin >> size) || size <= 0) {
        std::cout << "Ошибка: размер должен быть положительным целым числом.\n";
        return 1;
    }

    SafeArray myArr = createArray(size);

    std::cout << "Размер созданного массива: " << myArr.size << '\n';

    delete[] myArr.data;
    myArr.data = nullptr;
    myArr.size = 0;

    return 0;
}