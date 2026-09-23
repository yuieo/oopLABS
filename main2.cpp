/**
* @file main2.cpp
 * @brief Работа с одномерным динамическим массивом.
 */

#include <iostream>

/**
 * @brief Запрашивает размер, создаёт и удаляет динамический массив.
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

    int* arr = new int[size]{};

    std::cout << "Созданный массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    delete[] arr;
    arr = nullptr;

    return 0;
}