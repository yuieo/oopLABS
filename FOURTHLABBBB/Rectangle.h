#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polygon.h"

class Rectangle : public Polygon
{
public:
    Rectangle(double width, double height, const std::string& initialColor);

    double area() const override;
    void draw() const override;
};

#endif