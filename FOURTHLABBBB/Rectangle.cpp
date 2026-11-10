#include "Rectangle.h"

#include <cmath>
#include <iostream>
#include <stdexcept>

namespace
{
    std::vector<Polygon::Point> makeRectangleVertices(double width, double height)
    {
        if (!std::isfinite(width) || !std::isfinite(height) ||
            width <= 0.0 || height <= 0.0)
        {
            throw std::invalid_argument(
                "Размеры прямоугольника должны быть конечными и положительными");
        }

        const double area = width * height;
        if (!std::isfinite(area) || area == 0.0)
        {
            throw std::invalid_argument(
                "Площадь прямоугольника должна быть конечной и положительной");
        }

        return {{0.0, 0.0}, {width, 0.0}, {width, height}, {0.0, height}};
    }
}

Rectangle::Rectangle(double width, double height, const std::string& initialColor)
    : Polygon(makeRectangleVertices(width, height), initialColor)
{
}

Rectangle::Rectangle(const Rectangle& other) = default;

Rectangle& Rectangle::operator=(const Rectangle& other)
{
    if (this != &other)
    {
        const Point& corner = other.getVertices()[2];
        if (requiresEqualSides() && corner.first != corner.second)
        {
            throw std::invalid_argument("Стороны квадрата должны быть равны");
        }

        Polygon::operator=(other);
    }

    return *this;
}

bool Rectangle::requiresEqualSides() const
{
    return false;
}

double Rectangle::area() const
{
    const Point& oppositeCorner = getVertices()[2];
    return oppositeCorner.first * oppositeCorner.second;
}

void Rectangle::draw() const
{
    std::cout << "Прямоугольник: ";
    Polygon::draw();
}
