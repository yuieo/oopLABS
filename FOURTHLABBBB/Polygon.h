/**
* @file
 * @brief Промежуточный класс многоугольников.
 */
#ifndef POLYGON_H
#define POLYGON_H

#include <cstddef>
#include <utility>
#include <vector>

#include "Figure.h"

/// @brief Абстрактный многоугольник с упорядоченным списком вершин.
class Polygon : public Figure
{
public:
    /// @brief Пара координат вершины (x, y).
    using Point = std::pair<double, double>;

    /// @brief Возвращает число сторон, равное числу вершин.
    std::size_t getSideCount() const;

    /// @brief Возвращает ссылку на вершины для чтения без копирования.
    const std::vector<Point>& getVertices() const;

    /// @brief Выводит цвет, число сторон, площадь и координаты вершин.
    void draw() const override;

protected:
    /**
     * @brief Копирует вершины и задаёт начальный цвет.
     * @param initialVertices Вершины в порядке обхода.
     * @param initialColor Начальный цвет.
     */
    Polygon(const std::vector<Point>& initialVertices,
            const std::string& initialColor);

    /**
     * @brief Создаёт многоугольник с собственным вектором вершин.
     * @param other Многоугольник для копирования.
     */
    Polygon(const Polygon& other);

    /**
     * @brief Копирует цвет и вершины в уже существующий объект.
     * @param other Исходный многоугольник.
     * @return Ссылка на текущий объект.
     */
    Polygon& operator=(const Polygon& other);

private:
    /// @brief Координаты вершин в порядке обхода контура.
    std::vector<Point> vertices;
};

#endif