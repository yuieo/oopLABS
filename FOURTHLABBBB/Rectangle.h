/**
* @file
 * @brief Класс прямоугольника.
 */
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polygon.h"

/// @brief Прямоугольник с нижним левым углом в начале координат.
class Rectangle : public Polygon
{
public:
    /**
     * @brief Создаёт прямоугольник и учитывает его в статистике.
     * @param width Ширина.
     * @param height Высота.
     * @param initialColor Начальный цвет.
     * @throws std::invalid_argument Если размеры или площадь неконечны либо неположительны.
     */
    Rectangle(double width, double height, const std::string& initialColor);

    /**
     * @brief Создаёт и регистрирует независимую копию.
     * @param other Прямоугольник для копирования.
     */
    Rectangle(const Rectangle& other);

    /**
     * @brief Копирует вершины и цвет в существующий объект.
     * @param other Исходный прямоугольник.
     * @return Ссылка на текущий объект.
     * @throws std::invalid_argument При присваивании квадрату фигуры с неравными сторонами.
     */
    Rectangle& operator=(const Rectangle& other);

    /// @brief Возвращает произведение ширины и высоты.
    double area() const override;

    /// @brief Выводит название фигуры и общие сведения о многоугольнике.
    void draw() const override;

protected:
    /// @brief Возвращает false, так как ширина и высота могут различаться.
    virtual bool requiresEqualSides() const;
};

#endif