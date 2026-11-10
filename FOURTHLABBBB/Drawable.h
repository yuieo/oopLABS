/**
* @file
 * @brief Интерфейс вывода фигур.
 */
#ifndef DRAWABLE_H
#define DRAWABLE_H

/// @brief Интерфейс фигуры, которую можно вывести.
class Drawable
{
public:
    /// @brief Позволяет уничтожать фигуру через указатель Drawable*.
    virtual ~Drawable();

    /// @brief Выводит представление фигуры в консоль.
    virtual void draw() const = 0;
};

#endif