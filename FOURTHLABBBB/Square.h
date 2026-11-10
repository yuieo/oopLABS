/**
* @file
 * @brief Класс квадрата.
 */
#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

/// @brief Прямоугольник с равными сторонами.
class Square final : public Rectangle
{
public:
    /**
     * @brief Создаёт квадрат, передавая одну сторону как ширину и высоту.
     * @param side Длина стороны.
     * @param initialColor Начальный цвет.
     * @throws std::invalid_argument Если сторона или площадь неконечна либо неположительна.
     */
    Square(double side, const std::string& initialColor);

    /**
     * @brief Создаёт независимую копию квадрата.
     * @param other Квадрат для копирования.
     */
    Square(const Square& other);

    /**
     * @brief Копирует цвет и вершины другого квадрата.
     * @param other Исходный квадрат.
     * @return Ссылка на текущий объект.
     */
    Square& operator=(const Square& other);

    /// @brief Выводит название квадрата и общие сведения о многоугольнике.
    void draw() const override;

protected:
    /// @brief Возвращает true, так как стороны квадрата должны быть равны.
    bool requiresEqualSides() const override;
};

#endif