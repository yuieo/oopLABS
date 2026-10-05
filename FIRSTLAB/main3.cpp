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
 * @brief Выводит элементы массива без их изменения.
 * @param arr Константная ссылка на структуру массива.
 */
void printSafe(const SafeArray& arr)
{
    if (arr.size == 0) {
        std::cout << "Массив пуст";
    }

    for (int i = 0; i < arr.size; ++i) {
        std::cout << arr.data[i] << ' ';
    }
    std::cout << '\n';
}

/**
 * @brief Изменяет размер массива, сохраняя оставшиеся элементы.
 * @param arr Ссылка на изменяемую структуру массива.
 * @param newSize Новый размер, не должен быть отрицательным.
 * @note При уменьшении выводятся удаляемые элементы.
 * @note При увеличении новые элементы заполняются нулями.
 */
void reSizeArray(SafeArray& arr, int newSize)
{
    if (newSize < 0) {
        std::cout << "Ошибка: размер не может быть отрицательным.\n";
        return;
    }

    if (newSize == arr.size) {
        return;
    }

    int* newData = nullptr;

    if (newSize > 0) {
        newData = new int[newSize]{};
    }

    int copySize = arr.size;
    if (newSize < copySize) {
        copySize = newSize;
    }

    for (int i = 0; i < copySize; ++i) {
        newData[i] = arr.data[i];
    }

    if (newSize < arr.size) {
        std::cout << "Удаляемые элементы: ";
        for (int i = newSize; i < arr.size; ++i) {
            std::cout << arr.data[i] << ' ';
        }
        std::cout << '\n';
    }

    delete[] arr.data;

    arr.data = newData;
    arr.size = newSize;
}

/**
 * @brief Демонстрирует доступ, вывод и изменение размера массива.
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

    getElement(myArr, 2) = 999;

    std::cout << "Массив после присваивания: ";
    printSafe(myArr);

    int newSize{};

    std::cout << "Введите новый размер массива: ";

    if (!(std::cin >> newSize)) {
        std::cout << "Ошибка: необходимо ввести целое число.\n";
        delete[] myArr.data;
        myArr.data = nullptr;
        myArr.size = 0;
        return 1;
    }

    reSizeArray(myArr, newSize);

    std::cout << "Массив после вызова reSizeArray: ";
    printSafe(myArr);

    delete[] myArr.data;
    myArr.data = nullptr;
    myArr.size = 0;

    return 0;
}