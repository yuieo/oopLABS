#ifndef POLYGON_H
#define POLYGON_H

#include <cstddef>
#include <utility>
#include <vector>

#include "Figure.h"

class Polygon : public Figure
{
public:
    using Point = std::pair<double, double>;

    std::size_t getSideCount() const;
    const std::vector<Point>& getVertices() const;
    void draw() const override;

protected:
    Polygon(const std::vector<Point>& initialVertices,
            const std::string& initialColor);

private:
    std::vector<Point> vertices;
};

#endif