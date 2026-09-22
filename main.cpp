/**
* @file main.cpp
 * @brief Работа с массивом из 10 целых чисел.
 */

#include <iostream>

/**
 * @brief Заполняет массив числами с клавиатуры.
 * @param arr Ссылка на массив из 10 целых чисел.
 */

void fillArray(int (&arr)[10])
{
    std::cout << "Введите 10 целых чисел:\n";

    for (int i = 0; i < 10; ++i) {
        std::cin >> arr[i];
    }
}

/**
 * @brief Точка входа в программу.
 * @return Код завершения: 0 — успешное выполнение.
 */
int main()
{
    int numbers[10]{};

    fillArray(numbers);

    std::cout << "Первый элемент: " << numbers[0] << '\n';

    return 0;
}