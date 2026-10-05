/**
 * @file main.cpp
 * @brief Демонстрация работы класса GameCharacter.
 */

#include "GameCharacter.h"

#include <iostream>
#include <stdexcept>

/**
 * @brief Демонстрирует создание персонажей и проверку характеристик.
 * @return Код завершения: 0 — успешное выполнение.
 */
int main()
{
    GameCharacter hero;
    hero.print();

    std::cout << '\n';
    GameCharacter warrior("Воин", 80.0, 2, 50);
    warrior.print();

    std::cout << '\n';
    try {
        GameCharacter invalidHero("Ошибка", -10.0, 1, 0);
    }
    catch (const std::invalid_argument& error) {
        std::cout << "Ошибка создания: " << error.what() << '\n';
    }

    return 0;
}
