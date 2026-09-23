/**
 * @file main2.cpp
 * @brief Работа с одномерным динамическим массивом.
 */

#include <iostream>

/**
 * @brief Оставляет элементы до первого отрицательного числа.
 * @param arr Ссылка на указатель на динамический массив.
 * @param size Ссылка на размер массива, обновляемый после обработки.
 * @pre arr указывает на массив из size элементов, созданный через new[].
 * @note Если отрицательных чисел нет, массив не изменяется.
 */
void process(int*& arr, int& size)
{
    int newSize = size;

    for (int i = 0; i < size; ++i) {
        if (arr[i] < 0) {
            newSize = i;
            break;
        }
    }

    if (newSize == size) {
        return;
    }

    int* newArr = nullptr;

    if (newSize > 0) {
        newArr = new int[newSize]{};

        for (int i = 0; i < newSize; ++i) {
            newArr[i] = arr[i];
        }
    }

    delete[] arr;

    arr = newArr;
    size = newSize;
}

/**
 * @brief Создаёт, заполняет, обрабатывает и выводит массив.
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

    std::cout << "Введите " << size << " целых чисел:\n";

    for (int i = 0; i < size; ++i) {
        if (!(std::cin >> arr[i])) {
            std::cout << "Ошибка: необходимо ввести целое число.\n";
            delete[] arr;
            arr = nullptr;
            return 1;
        }
    }

    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    process(arr, size);

    std::cout << "Массив после обработки: ";

    if (size == 0) {
        std::cout << "пуст";
    } else {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << ' ';
        }
    }
    std::cout << '\n';

    delete[] arr;
    arr = nullptr;

    return 0;
}