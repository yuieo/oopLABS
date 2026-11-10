#ifndef FIGURE_H
#define FIGURE_H

#include <cstddef>
#include <string>

#include "Drawable.h"
#include "Colorable.h"

class Figure : public Drawable, public Colorable
{
private:
    std::string color;
    static std::size_t createdCount;
    static double averageArea;

protected:
    explicit Figure(const std::string& initialColor);
    static void recordCreation(double initialArea);

public:
    ~Figure() override;

    virtual double area() const = 0;
    void draw() const override = 0;

    void setColor(const std::string& newColor) override;
    std::string getColor() const;

    static std::size_t getCreatedCount();
    static double getAverageArea();

    friend bool haveSameColor(const Figure& first, const Figure& second);
};

#endif