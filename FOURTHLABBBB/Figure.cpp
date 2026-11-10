#include "Figure.h"

Figure::Figure(const std::string& initialColor)
    : color(initialColor)
{
}

Figure::~Figure() = default;

void Figure::setColor(const std::string& newColor)
{
    color = newColor;
}

std::string Figure::getColor() const
{
    return color;
}