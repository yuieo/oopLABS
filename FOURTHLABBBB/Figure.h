/**
 * @mainpage Геометрические фигуры
 *
 * Лабораторная работа №4. Вариант 1.
 *
 * @section hierarchy Иерархия фигур
 * Figure реализует смену цвета через интерфейс Colorable и наследует
 * контракт вывода от Drawable. Polygon хранит вершины в std::vector
 * и использует виртуальный вызов area() при выводе. Rectangle
 * вычисляет площадь, а Square задаёт равные ширину и высоту.
 * При копировании вектора каждая фигура получает собственные вершины.
 *
 * @section data Исходные данные и статистика
 * Файл figures.txt содержит пять прямоугольников и пять квадратов.
 * Drawable, Colorable, Figure и Polygon абстрактны, поэтому из файла
 * создаются объекты только конкретных классов. Счётчик включает
 * все успешно созданные фигуры и их копии. Средняя площадь учитывает
 * площадь в момент создания, включая уже уничтоженные объекты.
 *
 * @section verification Проверки
 * Один файл main.cpp используется в двух программах. Первая связывается
 * со статической библиотекой, вторая с динамической. Сборка выполняется
 * прямыми вызовами clang++ с ключом -std=c++14 и командой ar.
 *
 * @section uml Диаграмма классов
 * Исходник диаграммы PlantUML находится в файле classes.puml.
 */

/**
 * @file
 * @brief Базовый класс геометрических фигур.
 */
#ifndef FIGURE_H
#define FIGURE_H

#include <cstddef>
#include <string>

#include "Drawable.h"
#include "Colorable.h"

/// @brief Абстрактная фигура с цветом и общей статистикой создания.
class Figure : public Drawable, public Colorable
{
private:
    /// @brief Текущий цвет фигуры.
    std::string color;

    /// @brief Число успешно созданных фигур, включая копии.
    static std::size_t createdCount;

    /// @brief Среднее по площадям фигур на момент создания.
    static double averageArea;

protected:
    /**
     * @brief Задаёт начальный цвет.
     * @param initialColor Начальный цвет фигуры.
     */
    explicit Figure(const std::string& initialColor);

    /**
     * @brief Учитывает ещё одну фигуру после создания её вершин.
     * @param initialArea Площадь фигуры на момент создания.
     */
    static void recordCreation(double initialArea);

public:
    /// @brief Виртуальный деструктор для удаления через Figure*.
    ~Figure() override;

    /// @brief Возвращает площадь фигуры.
    virtual double area() const = 0;

    /// @brief Выводит фигуру в консоль.
    void draw() const override = 0;

    /// @copydoc Colorable::setColor
    void setColor(const std::string& newColor) override;

    /// @brief Возвращает копию текущего цвета.
    std::string getColor() const;

    /// @brief Возвращает число фигур, созданных за время работы программы.
    static std::size_t getCreatedCount();

    /// @brief Возвращает среднюю начальную площадь или 0, если фигур ещё не было.
    static double getAverageArea();

    /**
     * @brief Сравнивает закрытые поля цвета двух фигур.
     * @param first Первая фигура.
     * @param second Вторая фигура.
     * @return true, если цвета совпадают.
     */
    friend bool haveSameColor(const Figure& first, const Figure& second);
};

#endif