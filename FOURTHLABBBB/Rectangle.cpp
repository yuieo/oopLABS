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
            throw std::invalid_argument("Rectangle dimensions must be finite and positive");
        }

        const double area = width * height;
        if (!std::isfinite(area) || area == 0.0)
        {
            throw std::invalid_argument("Rectangle area must be finite and positive");
        }

        return {{0.0, 0.0}, {width, 0.0}, {width, height}, {0.0, height}};
    }
}

Rectangle::Rectangle(double width, double height, const std::string& initialColor)
    : Polygon(makeRectangleVertices(width, height), initialColor)
{
}

double Rectangle::area() const
{
    const Point& oppositeCorner = getVertices()[2];
    return oppositeCorner.first * oppositeCorner.second;
}

void Rectangle::draw() const
{
    std::cout << "Rectangle: ";
    Polygon::draw();
}