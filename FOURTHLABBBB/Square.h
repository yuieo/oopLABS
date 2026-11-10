#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

class Square final : public Rectangle
{
public:
    Square(double side, const std::string& initialColor);
    Square(const Square& other);
    Square& operator=(const Square& other);

    void draw() const override;

protected:
    bool requiresEqualSides() const override;
};

#endif
