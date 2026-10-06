/**
 * @file main.cpp
 * @brief Демонстрация работы класса GameCharacter.
 */

#include "GameCharacter.h"

#include <cassert>
#include <iostream>
#include <stdexcept>

/**
 * @brief Демонстрирует создание персонажей и проверяет результаты их методов.
 * @note Проверки assert действуют при сборке без определения NDEBUG.
 * @return Код завершения: 0 — успешное выполнение.
 */
int main()
{
    std::cout << "Объектов до создания: " << GameCharacter::getObjectCount() << '\n';
    assert(GameCharacter::getObjectCount() == 0);

    GameCharacter hero;
    hero.print();

    std::cout << '\n';
    GameCharacter warrior("Воин", 80.0, 2, 50);
    warrior.print();

    std::cout << "\nКопия воина:\n";
    GameCharacter warriorCopy(warrior);
    warriorCopy.print();

    std::cout << "Объектов после создания: " << GameCharacter::getObjectCount() << '\n';
    assert(GameCharacter::getObjectCount() == 3);

    std::cout << "\nЧтение характеристик воина через методы:\n";
    std::cout << "Имя: " << warrior.getName() << '\n';
    std::cout << "Здоровье: " << warrior.getHealth() << '\n';
    std::cout << "Уровень: " << warrior.getLevel() << '\n';
    std::cout << "Опыт: " << warrior.getExperience() << '\n';

    std::cout << '\n';
    try {
        GameCharacter invalidHero("Ошибка", -10.0, 1, 0);
        assert(false && "Отрицательное здоровье должно быть отклонено");
    }
    catch (const std::invalid_argument& error) {
        std::cout << "Ошибка создания: " << error.what() << '\n';
    }
    try {
        GameCharacter invalidHero("Ошибка", 150.0, 1, 0);
        assert(false && "Здоровье выше максимума должно быть отклонено");
    }
    catch (const std::invalid_argument& error) {
        std::cout << "Ошибка создания: " << error.what() << '\n';
    }
    try {
        GameCharacter invalidHero("Ошибка", 100.0, 0, 0);
        assert(false && "Нулевой уровень должен быть отклонён");
    }
    catch (const std::invalid_argument& error) {
        std::cout << "Ошибка создания: " << error.what() << '\n';
    }
    try {
        GameCharacter invalidHero("Ошибка", 100.0, 1, -10);
        assert(false && "Отрицательный опыт должен быть отклонён");
    }
    catch (const std::invalid_argument& error) {
        std::cout << "Ошибка создания: " << error.what() << '\n';
    }
    std::cout << "Объектов после ошибки создания: " << GameCharacter::getObjectCount() << '\n';
    assert(GameCharacter::getObjectCount() == 3);

    std::cout << "\nУрон и лечение воина:\n";
    warrior.takeDamage(30);
    assert(warrior.getHealth() == 50);
    std::cout << "После урона 30: " << warrior.getHealth() << '\n';
    warrior.heal(10);
    assert(warrior.getHealth() == 60);
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
    assert(warrior.getHealth() == 60);
    assert(warrior.getLevel() == 2 && warrior.getExperience() == 50);

    std::cout << "\nПроверка границ здоровья:\n";
    warrior.takeDamage(1000);
    assert(warrior.getHealth() == 0);
    std::cout << "После урона 1000: " << warrior.getHealth() << '\n';
    warrior.heal(1000);
    assert(warrior.getHealth() == 100);
    std::cout << "После лечения 1000: " << warrior.getHealth() << '\n';

    std::cout << "\nОпыт и повышение уровня:\n";
    if (!warrior.levelUp()) {
        std::cout << "Повышение отклонено: 50 единиц опыта недостаточно.\n";
    }
    assert(warrior.getLevel() == 2 && warrior.getExperience() == 50);
    warrior.print();

    warrior.addExperience(75);
    assert(warrior.getExperience() == 125 && warrior.getLevel() == 2);
    std::cout << "После получения 75 опыта: " << warrior.getExperience() << '\n';
    if (warrior.levelUp()) {
        std::cout << "Уровень повышен до " << warrior.getLevel()
                  << ", осталось опыта: " << warrior.getExperience() << '\n';
    }
    assert(warrior.getLevel() == 3 && warrior.getExperience() == 25);

    std::cout << "\nНекорректное добавление опыта:\n";
    if (!warrior.addExperience(-10)) {
        std::cout << "Отрицательное количество опыта отклонено.\n";
    }
    if (!warrior.addExperience(0)) {
        std::cout << "Добавление 0 опыта отклонено.\n";
    }

    std::cout << "\nВоин после изменений и отклонённых операций:\n";
    warrior.print();
    assert(warrior.getName() == "Воин" && warrior.getHealth() == 100);
    assert(warrior.getLevel() == 3 && warrior.getExperience() == 25);
    std::cout << "\nПервый персонаж остался без изменений:\n";
    hero.print();
    assert(hero.getName() == "Герой" && hero.getHealth() == 100);
    assert(hero.getLevel() == 1 && hero.getExperience() == 0);
    std::cout << "\nКопия воина осталась без изменений:\n";
    warriorCopy.print();
    assert(warriorCopy.getName() == "Воин" && warriorCopy.getHealth() == 80);
    assert(warriorCopy.getLevel() == 2 && warriorCopy.getExperience() == 50);

    std::cout << "\nПовышение при ровно 100 единицах опыта:\n";
    {
        GameCharacter boundary("Проверка", 0, 1, 100);
        boundary.levelUp();
        assert(boundary.getLevel() == 2 && boundary.getExperience() == 0);
        assert(boundary.getHealth() == 0);
        boundary.print();
    }

    std::cout << "\nПроверка времени жизни объекта:\n";
    std::cout << "До блока: " << GameCharacter::getObjectCount() << '\n';
    assert(GameCharacter::getObjectCount() == 3);
    {
        GameCharacter temporary;
        std::cout << "Внутри блока: " << GameCharacter::getObjectCount() << '\n';
        assert(GameCharacter::getObjectCount() == 4);
    }
    std::cout << "После блока: " << GameCharacter::getObjectCount() << '\n';
    assert(GameCharacter::getObjectCount() == 3);

    std::cout << "\nВсе проверки пройдены.\n";

    return 0;
}
