/**
 * @file GameCharacter.cpp
 * @brief Реализация класса игрового персонажа.
 */

#include "GameCharacter.h"

#include <climits>
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

GameCharacter::GameCharacter(const GameCharacter& other)
    : name(other.name), health(other.health),
      level(other.level), experience(other.experience)
{
}

std::string GameCharacter::getName() const
{
    return name;
}

double GameCharacter::getHealth() const
{
    return health;
}

int GameCharacter::getLevel() const
{
    return level;
}

int GameCharacter::getExperience() const
{
    return experience;
}

bool GameCharacter::takeDamage(double damage)
{
    if (!std::isfinite(damage) || damage <= 0) {
        return false;
    }

    if (damage >= health) {
        health = 0;
    } else {
        health -= damage;
    }

    return true;
}

bool GameCharacter::heal(double amount)
{
    if (!std::isfinite(amount) || amount <= 0) {
        return false;
    }

    if (amount >= 100 - health) {
        health = 100;
    } else {
        health += amount;
    }

    return true;
}

bool GameCharacter::addExperience(int amount)
{
    if (amount <= 0 || amount > INT_MAX - experience) {
        return false;
    }

    experience += amount;
    return true;
}

bool GameCharacter::levelUp()
{
    if (experience < 100 || level == INT_MAX) {
        return false;
    }

    experience -= 100;
    ++level;
    return true;
}

void GameCharacter::print() const
{
    std::cout << "Имя: " << name << '\n';
    std::cout << "Здоровье: " << health << '\n';
    std::cout << "Уровень: " << level << '\n';
    std::cout << "Опыт: " << experience << '\n';
}
