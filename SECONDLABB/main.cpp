/**
 * @file main.cpp
 * @brief Демонстрация работы класса GameCharacter.
 */

#include "GameCharacter.h"

#include <iostream>
#include <stdexcept>

/**
 * @brief Демонстрирует создание персонажей, урон, лечение и проверки.
 * @return Код завершения: 0 — успешное выполнение.
 */
int main()
{
    GameCharacter hero;
    hero.print();

    std::cout << '\n';
    GameCharacter warrior("Воин", 80.0, 2, 50);
    warrior.print();

    std::cout << "\nКопия воина:\n";
    GameCharacter warriorCopy(warrior);
    warriorCopy.print();

    std::cout << "\nЧтение характеристик воина через методы:\n";
    std::cout << "Имя: " << warrior.getName() << '\n';
    std::cout << "Здоровье: " << warrior.getHealth() << '\n';
    std::cout << "Уровень: " << warrior.getLevel() << '\n';
    std::cout << "Опыт: " << warrior.getExperience() << '\n';

    std::cout << '\n';
    try {
        GameCharacter invalidHero("Ошибка", -10.0, 1, 0);
    }
    catch (const std::invalid_argument& error) {
        std::cout << "Ошибка создания: " << error.what() << '\n';
    }

    std::cout << "\nУрон и лечение воина:\n";
    warrior.takeDamage(30);
    std::cout << "После урона 30: " << warrior.getHealth() << '\n';
    warrior.heal(10);
    std::cout << "После лечения 10: " << warrior.getHealth() << '\n';

    std::cout << "\nНекорректные операции:\n";
    if (!warrior.takeDamage(-20)) {
        std::cout << "Отрицательный урон отклонён.\n";
    }
    if (!warrior.heal(0)) {
        std::cout << "Лечение на 0 отклонено.\n";
    }
    std::cout << "Состояние после отклонённых операций:\n";
    warrior.print();

    std::cout << "\nПроверка границ здоровья:\n";
    warrior.takeDamage(1000);
    std::cout << "После урона 1000: " << warrior.getHealth() << '\n';
    warrior.heal(1000);
    std::cout << "После лечения 1000: " << warrior.getHealth() << '\n';

    std::cout << "\nВоин после изменений:\n";
    warrior.print();
    std::cout << "\nПервый персонаж остался без изменений:\n";
    hero.print();
    std::cout << "\nКопия воина осталась без изменений:\n";
    warriorCopy.print();

    return 0;
}
