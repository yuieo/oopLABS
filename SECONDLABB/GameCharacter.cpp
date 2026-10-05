/**
 * @file GameCharacter.cpp
 * @brief Реализация класса игрового персонажа.
 */

#include "GameCharacter.h"

#include <iostream>

GameCharacter::GameCharacter()
    : name("Герой"), health(100.0), level(1), experience(0)
{
}

void GameCharacter::print() const
{
    std::cout << "Имя: " << name << '\n';
    std::cout << "Здоровье: " << health << '\n';
    std::cout << "Уровень: " << level << '\n';
    std::cout << "Опыт: " << experience << '\n';
}
