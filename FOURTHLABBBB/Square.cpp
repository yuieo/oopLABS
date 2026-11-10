#include "Square.h"

#include <iostream>

Square::Square(double side, const std::string& initialColor)
    : Rectangle(side, side, initialColor)
{
}

Square::Square(const Square& other) = default;

Square& Square::operator=(const Square& other) = default;

void Square::draw() const
{
    std::cout << "Квадрат: ";
    Polygon::draw();
}

bool Square::requiresEqualSides() const
{
    return true;
}
