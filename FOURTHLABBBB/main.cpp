/**
 * @file
 * @brief Загрузка фигур из файла и проверки программы.
 */
#include "Rectangle.h"
#include "Square.h"

#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

/// @brief Список фигур, которыми владеют умные указатели.
using Figures = std::vector<std::unique_ptr<Figure>>;

/**
 * @brief Проверяет условие теста.
 * @param condition Условие успешной проверки.
 * @param message Сообщение об ошибке.
 * @throws std::runtime_error Если условие ложно.
 */
void check(bool condition, const char* message)
{
    if (!condition)
    {
        throw std::runtime_error(message);
    }
}

/**
 * @brief Загружает десять фигур из figures.txt.
 * @return Список прямоугольников и квадратов.
 * @throws std::runtime_error Если файл недоступен или имеет неверный формат.
 * @throws std::invalid_argument Если у фигуры недопустимые размеры.
 */
Figures loadFigures()
{
    std::ifstream file("figures.txt");
    check(file.is_open(), "Не удалось открыть figures.txt");

    Figures figures;
    std::size_t rectangleCount = 0;
    std::string line;

    while (std::getline(file, line))
    {
        std::istringstream row(line);
        std::string type;
        std::string color;
        std::string extra;
        double width = 0.0;
        double height = 0.0;

        row >> type >> width;
        if (type == "rectangle")
        {
            row >> height;
        }

        if (!(row >> color) || (row >> extra) ||
            (type != "rectangle" && type != "square"))
        {
            throw std::runtime_error(
                "Неверная запись в строке " + std::to_string(figures.size() + 1));
        }

        if (type == "rectangle")
        {
            figures.push_back(std::make_unique<Rectangle>(width, height, color));
            ++rectangleCount;
        }
        else
        {
            figures.push_back(std::make_unique<Square>(width, color));
        }
    }

    check(!file.bad(), "Ошибка чтения figures.txt");
    check(figures.size() == 10, "В файле должно быть ровно 10 фигур");
    check(rectangleCount >= 3 && figures.size() - rectangleCount >= 3,
          "Нужно минимум три прямоугольника и три квадрата");
    return figures;
}

/**
 * @brief Проверяет статистику, виртуальный вывод и смену цвета через интерфейсы.
 * @param figures Фигуры, считанные из файла.
 */
void testLoadedFigures(const Figures& figures)
{
    std::cout << "Фигуры из файла\n";
    double expectedAverage = 0.0;

    for (const auto& figure : figures)
    {
        figure->draw();
        expectedAverage += figure->area() / figures.size();
    }

    check(Figure::getCreatedCount() == figures.size(), "Неверный счётчик фигур");
    const double average = Figure::getAverageArea();
    const double tolerance = 1e-9 * std::max(1.0, expectedAverage);
    check(std::abs(average - expectedAverage) <= tolerance, "Неверная средняя площадь");
    std::cout << "Создано фигур: " << Figure::getCreatedCount()
              << ", средняя площадь: " << average << '\n';

    Figure& figure = *figures.front();
    Colorable& colorable = figure;
    const Drawable& drawable = figure;
    colorable.setColor("фиолетовый");
    check(figure.getColor() == "фиолетовый", "Цвет не изменился через Colorable");
    std::cout << "\nВывод через Drawable после смены цвета\n";
    drawable.draw();
}

/// @brief Проверяет независимость координат и цвета после копирования.
void testCopying()
{
    const Square original(3.0, "красный");
    const auto countBeforeCopy = Figure::getCreatedCount();
    Square copy(original);
    check(Figure::getCreatedCount() == countBeforeCopy + 1,
          "Копия не учтена счётчиком");

    Square assigned(2.0, "зелёный");
    const auto countBeforeAssignment = Figure::getCreatedCount();
    const double averageBeforeAssignment = Figure::getAverageArea();
    assigned = original;

    check(copy.getVertices() == original.getVertices() &&
              assigned.getVertices() == original.getVertices(),
          "Координаты скопированы неверно");
    check(copy.getVertices().data() != original.getVertices().data() &&
              assigned.getVertices().data() != original.getVertices().data(),
          "Копии используют координаты исходной фигуры");
    check(haveSameColor(original, copy) && haveSameColor(original, assigned),
          "Цвет скопирован неверно");

    copy.setColor("синий");
    check(!haveSameColor(original, copy) && original.getColor() == "красный",
          "Изменение копии затронуло оригинал");
    check(Figure::getCreatedCount() == countBeforeAssignment &&
              Figure::getAverageArea() == averageBeforeAssignment,
          "Присваивание изменило статистику создания");
    std::cout << "\nКопирование и присваивание проверены\n";
}

/// @brief Проверяет обработку исключения при нулевой ширине.
void testInvalidDimensions()
{
    const auto countBefore = Figure::getCreatedCount();

    try
    {
        const Rectangle invalid(0.0, 2.0, "белый");
    }
    catch (const std::invalid_argument& error)
    {
        check(Figure::getCreatedCount() == countBefore,
              "Неудачное создание изменило счётчик");
        std::cout << "Поймано ожидаемое исключение: " << error.what() << '\n';
        return;
    }

    throw std::runtime_error("Конструктор принял нулевую ширину");
}

/**
 * @brief Загружает данные и запускает проверки.
 * @return 0 при успехе или 1 при ошибке.
 */
int main()
{
    try
    {
        const Figures figures = loadFigures();
        testLoadedFigures(figures);
        testCopying();
        testInvalidDimensions();
        std::cout << "\nВсе проверки пройдены\n";
    }
    catch (const std::exception& error)
    {
        std::cerr << "Ошибка: " << error.what() << '\n';
        return 1;
    }

    return 0;
}