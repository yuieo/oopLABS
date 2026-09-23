/**
 * @file main4.cpp
 * @brief Работа с двумерным массивом оценок студентов.
 */

#include <iostream>
#include <string>

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
 * @brief Выводит таблицу с заголовком и необязательной рамкой.
 * @param matrix Указатель на массив указателей на строки.
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 * @param showBorders Нужно ли выводить рамку; по умолчанию true.
 * @param title Заголовок таблицы; по умолчанию "Matrix".
 */
void printMatrix(int** matrix, int rows, int cols,
                 bool showBorders = true,
                 std::string title = "Matrix")
{
    std::cout << title << '\n';

    int cellWidth = 1;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            int length = static_cast<int>(
                std::to_string(matrix[i][j]).length()
            );

            if (length > cellWidth) {
                cellWidth = length;
            }
        }
    }

    int borderWidth = cols * (cellWidth + 1) + 3;

    if (showBorders) {
        for (int i = 0; i < borderWidth; ++i) {
            std::cout << '*';
        }
        std::cout << '\n';
    }

    for (int i = 0; i < rows; ++i) {
        if (showBorders) {
            std::cout << "* ";
        }

        for (int j = 0; j < cols; ++j) {
            std::cout.width(cellWidth);
            std::cout << matrix[i][j] << ' ';
        }

        if (showBorders) {
            std::cout << '*';
        }

        std::cout << '\n';
    }

    if (showBorders) {
        for (int i = 0; i < borderWidth; ++i) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}

/**
 * @brief Выводит таблицу с указанным заголовком и рамкой.
 * @param matrix Указатель на массив указателей на строки.
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 * @param title Заголовок таблицы в виде строки символов.
 */
void printMatrix(int** matrix, int rows, int cols,
                 const char* title)
{
    printMatrix(matrix, rows, cols, true, std::string(title));
}

/**
 * @brief Демонстрирует три варианта вызова функции вывода.
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
        // Без дополнительных аргументов.
        printMatrix(matrix, rows, cols);
        std::cout << '\n';

        // Только с заголовком.
        printMatrix(matrix, rows, cols, "Оценки студентов");
        std::cout << '\n';

        // Со всеми аргументами.
        printMatrix(matrix, rows, cols, false, "Оценки без рамки");
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }

    delete[] matrix;
    matrix = nullptr;

    return exitCode;
}