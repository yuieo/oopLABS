/**
 * @file GameCharacter.cpp
 * @brief Реализация класса игрового персонажа.
 */

#include "GameCharacter.h"

#include <cmath>
#include <iostream>
#include <stdexcept>

GameCharacter::GameCharacter()
    : name("Герой"), health(100.0), level(1), experience(0)
{
}

GameCharacter::GameCharacter(const std::string& newName, double newHealth,
                             int newLevel, int newExperience)
    : name(newName), health(newHealth), level(newLevel), experience(newExperience)
{
    if (!std::isfinite(health) || health < 0 || health > 100) {
        throw std::invalid_argument("Здоровье должно быть конечным числом от 0 до 100.");
    }

    if (level < 1) {
        throw std::invalid_argument("Уровень должен быть не ниже 1.");
    }

    if (experience < 0) {
        throw std::invalid_argument("Опыт не может быть отрицательным.");
    }
}

void GameCharacter::print() const
{
    std::cout << "Имя: " << name << '\n';
    std::cout << "Здоровье: " << health << '\n';
    std::cout << "Уровень: " << level << '\n';
    std::cout << "Опыт: " << experience << '\n';
}
