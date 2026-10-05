/**
 * @file GameCharacter.h
 * @brief Объявление класса игрового персонажа.
 */

#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

#include <string>

/**
 * @brief Игровой персонаж с именем, здоровьем, уровнем и опытом.
 * @invariant Здоровье находится в диапазоне от 0 до 100.
 * @invariant Уровень не ниже 1.
 * @invariant Опыт неотрицательный.
 */
class GameCharacter
{
private:
    std::string name; ///< Имя персонажа.
    double health;    ///< Текущее здоровье.
    int level;        ///< Уровень персонажа.
    int experience;   ///< Накопленный опыт.

public:
    /**
     * @brief Создаёт персонажа с именем «Герой», здоровьем 100,
     * уровнем 1 и опытом 0.
     */
    GameCharacter();

    /**
     * @brief Создаёт персонажа с заданными характеристиками.
     * @param newName Имя персонажа.
     * @param newHealth Конечное значение здоровья от 0 до 100.
     * @param newLevel Уровень, не ниже 1.
     * @param newExperience Неотрицательный опыт.
     * @throws std::invalid_argument Если характеристики недопустимы.
     */
    GameCharacter(const std::string& newName, double newHealth,
                  int newLevel, int newExperience);

    /**
     * @brief Создаёт независимую копию персонажа.
     * @param other Персонаж, характеристики которого копируются.
     */
    GameCharacter(const GameCharacter& other);

    /**
     * @brief Выводит имя, здоровье, уровень и опыт персонажа.
     */
    void print() const;
};

#endif
