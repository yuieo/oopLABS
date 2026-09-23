/**
* @file main4.cpp
 * @brief Работа с двумерным массивом оценок студентов.
 */

#include <iostream>

/**
 * @brief Выделяет память под двумерный массив и обнуляет элементы.
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 * @return Указатель на массив указателей на строки.
 * @pre rows > 0 и cols > 0.
 */
int** allocateMatrix(int rows, int cols)
{
    int** matrix = new int*[rows]{};

    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols]{};
    }

    return matrix;
}

/**
 * @brief Создаёт таблицу оценок и освобождает её память.
 * @return 0 при успешном выполнении, 1 при ошибке ввода.
 */
int main()
{
    int rows{};
    int cols{};

    std::cout << "Введите количество студентов: ";
    if (!(std::cin >> rows) || rows <= 0) {
        std::cout << "Ошибка: количество должно быть положительным целым числом.\n";
        return 1;
    }

    std::cout << "Введите количество предметов: ";
    if (!(std::cin >> cols) || cols <= 0) {
        std::cout << "Ошибка: количество должно быть положительным целым числом.\n";
        return 1;
    }

    int** matrix = allocateMatrix(rows, cols);

    std::cout << "Создана таблица: "
              << rows << " строк, "
              << cols << " столбцов.\n";

    std::cout << "Первый элемент: " << matrix[0][0] << '\n';

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;
    matrix = nullptr;

    return 0;
}