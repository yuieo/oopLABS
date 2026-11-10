#ifndef COLORABLE_H
#define COLORABLE_H

#include <string>

class Colorable
{
public:
    virtual ~Colorable();
    virtual void setColor(const std::string& newColor) = 0;
};

#endif