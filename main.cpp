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
 * @brief Меняет местами два элемента массива.
 * @param arr Ссылка на массив из 10 целых чисел.
 * @param first Индекс первого элемента, переданный по ссылке.
 * @param second Индекс второго элемента, переданный по ссылке.
 */
void swapElements(int (&arr)[10], const int& first, const int& second)
{
    if (first < 0 || first >= 10 || second < 0 || second >= 10) {
        std::cout << "Ошибка: индексы должны быть от 0 до 9.\n";
        return;
    }

    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

/**
 * @brief Точка входа в программу.
 * @return Код завершения: 0 — успешное выполнение.
 */
int main()
{
    int numbers[10]{};

    fillArray(numbers);

    std::cout << "Исходный массив: ";
    printArray(numbers);

    int first{};
    int second{};

    std::cout << "Введите два индекса от 0 до 9: ";
    std::cin >> first >> second;

    swapElements(numbers, first, second);

    std::cout << "Массив после вызова swapElements: ";
    printArray(numbers);

    return 0;
}