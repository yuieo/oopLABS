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
 * @brief Заполняет таблицу оценками с клавиатуры.
 * @param matrix Указатель на массив указателей на строки.
 * @param rows Количество студентов.
 * @param cols Количество предметов.
 * @note При ошибке ввода функция завершает работу.
 */
void fillMatrix(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i) {
        std::cout << "Студент " << i + 1 << ":\n";

        for (int j = 0; j < cols; ++j) {
            std::cout << "Оценка по предмету " << j + 1 << ": ";

            if (!(std::cin >> matrix[i][j])) {
                return;
            }
        }
    }
}

/**
 * @brief Создаёт и заполняет таблицу оценок.
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

    fillMatrix(matrix, rows, cols);

    int exitCode = 0;

    if (!std::cin) {
        std::cout << "Ошибка: оценка должна быть целым числом.\n";
        exitCode = 1;
    } else {
        std::cout << "Таблица заполнена.\n";
        std::cout << "Первая оценка: " << matrix[0][0] << '\n';
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;
    matrix = nullptr;

    return exitCode;
}