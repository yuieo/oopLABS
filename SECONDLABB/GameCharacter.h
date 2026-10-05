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
};

#endif
