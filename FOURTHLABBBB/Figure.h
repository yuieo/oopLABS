#ifndef FIGURE_H
#define FIGURE_H

#include <string>

#include "Drawable.h"
#include "Colorable.h"

class Figure : public Drawable, public Colorable
{
private:
    std::string color;

protected:
    explicit Figure(const std::string& initialColor);

public:
    ~Figure() override;

    virtual double area() const = 0;
    void draw() const override = 0;

    void setColor(const std::string& newColor) override;
    std::string getColor() const;
};

#endif