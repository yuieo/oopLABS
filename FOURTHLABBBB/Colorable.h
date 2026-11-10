/**
* @file
 * @brief Интерфейс смены цвета.
 */
#ifndef COLORABLE_H
#define COLORABLE_H

#include <string>

/// @brief Интерфейс для изменения цвета фигуры.
class Colorable
{
public:
    /// @brief Позволяет уничтожать фигуру через указатель Colorable*.
    virtual ~Colorable();

    /**
     * @brief Задаёт цвет фигуры.
     * @param newColor Новый цвет.
     */
    virtual void setColor(const std::string& newColor) = 0;
};

#endif