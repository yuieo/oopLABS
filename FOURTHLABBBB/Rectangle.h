#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Polygon.h"

class Rectangle : public Polygon
{
public:
    Rectangle(double width, double height, const std::string& initialColor);
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);

    double area() const override;
    void draw() const override;

protected:
    virtual bool requiresEqualSides() const;
};

#endif
