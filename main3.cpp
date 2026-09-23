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
 * @brief Возвращает ссылку на элемент с проверкой индекса.
 * @param arr Ссылка на структуру массива.
 * @param index Индекс запрашиваемого элемента.
 * @return Ссылка на элемент или на статическую заглушку при ошибке.
 */
int& getElement(SafeArray& arr, int index)
{
    static int dummy = 0;

    if (index < 0 || index >= arr.size) {
        std::cout << "Ошибка: индекс выходит за границы массива.\n";
        return dummy;
    }

    return arr.data[index];
}

/**
 * @brief Создаёт массив и проверяет доступ к элементу по индексу.
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

    int index{};

    std::cout << "Введите индекс элемента: ";

    if (!(std::cin >> index)) {
        std::cout << "Ошибка: индекс должен быть целым числом.\n";
        delete[] myArr.data;
        myArr.data = nullptr;
        myArr.size = 0;
        return 1;
    }

    int& element = getElement(myArr, index);
    std::cout << "Полученное значение: " << element << '\n';

    delete[] myArr.data;
    myArr.data = nullptr;
    myArr.size = 0;

    return 0;
}