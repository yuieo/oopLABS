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
    std::string name = "Герой"; ///< Имя персонажа.
    double health = 100.0;     ///< Текущее здоровье.
    int level = 1;            ///< Уровень персонажа.
    int experience = 0;       ///< Накопленный опыт.
};

#endif
