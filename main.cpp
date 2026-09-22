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
 * @brief Выводит элементы массива на экран.
 * @param arr Константная ссылка на массив из 10 целых чисел.
 */
void printArray(const int (&arr)[10])
{
    for (auto x : arr) {
        std::cout << x << ' ';
    }

    std::cout << '\n';
}

/**
 * @brief Точка входа в программу.
 * @return Код завершения: 0 — успешное выполнение.
 */
int main()
{
    int numbers[10]{};

    fillArray(numbers);
    printArray(numbers);

    return 0;
}