#include "Figure.h"

std::size_t Figure::createdCount = 0;
double Figure::averageArea = 0.0;

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

void Figure::recordCreation(double initialArea)
{
    ++createdCount;
    averageArea += (initialArea - averageArea) / static_cast<double>(createdCount);
}

std::size_t Figure::getCreatedCount()
{
    return createdCount;
}

double Figure::getAverageArea()
{
    return averageArea;
}

bool haveSameColor(const Figure& first, const Figure& second)
{
    return first.color == second.color;
}