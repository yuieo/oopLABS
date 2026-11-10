#include "Polygon.h"

#include <iostream>

Polygon::Polygon(const std::vector<Point>& initialVertices,
                 const std::string& initialColor)
    : Figure(initialColor), vertices(initialVertices)
{
}

std::size_t Polygon::getSideCount() const
{
    return vertices.size();
}

const std::vector<Polygon::Point>& Polygon::getVertices() const
{
    return vertices;
}

void Polygon::draw() const
{
    std::cout << "color=" << getColor() << ", sides=" << getSideCount()
              << ", area=" << area() << ", vertices:";

    for (const Point& point : vertices)
    {
        std::cout << " (" << point.first << ", " << point.second << ")";
    }

    std::cout << '\n';
}