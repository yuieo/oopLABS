/**
 * @file main.cpp
 * @brief Демонстрация и проверка класса GameCharacter.
 */

#include "GameCharacter.h"

#include <cassert>
#include <iostream>
#include <stdexcept>

/**
 * @brief Проверяет отказ конструктора при неверных характеристиках.
 * @param health Проверяемое здоровье.
 * @param level Проверяемый уровень.
 * @param experience Проверяемый опыт.
 */
void testInvalidConstructor(double health, int level, int experience)
{
    std::cout << "Попытка создать персонажа: здоровье " << health
              << ", уровень " << level << ", опыт " << experience << '\n';
    try {
        GameCharacter invalid(CharacterName("Ошибка", "Неверная"), health, level, experience);
        assert(false && "Конструктор должен отклонить неверные характеристики");
    }
    catch (const std::invalid_argument& error) {
        std::cout << "Отказ: " << error.what() << '\n';
    }
}

/**
 * @brief Проверяет создание, методы, независимость и уничтожение персонажей.
 * @note Проверки assert действуют при сборке без определения NDEBUG.
 * @return 0 при успешном завершении.
 */
int main()
{
    std::cout << "Объектов до создания: " << GameCharacter::getObjectCount() << '\n';
    assert(GameCharacter::getObjectCount() == 0);
    {
        // Три объекта создаются разными конструкторами.
        GameCharacter hero;
        CharacterName warriorName("Воин", "Смелый");
        GameCharacter warrior(warriorName, 80, 2, 50);
        GameCharacter warriorCopy(warrior);
        assert(warriorName.getName() == "Воин" && warriorName.getAdjective() == "Смелый");

        std::cout << "\nНачальные состояния: герой, воин, копия.\n";
        hero.print();
        warrior.print();
        warriorCopy.print();
        std::cout << "Объектов: " << GameCharacter::getObjectCount() << '\n';
        assert(GameCharacter::getObjectCount() == 3);

        std::cout << "\nНекорректные параметры конструктора:\n";
        testInvalidConstructor(-10, 1, 0);
        testInvalidConstructor(150, 1, 0);
        testInvalidConstructor(100, 0, 0);
        testInvalidConstructor(100, 1, -10);
        assert(GameCharacter::getObjectCount() == 3);

        // Правильные операции: здоровье 80 -> 50 -> 60, опыт 50 -> 100 -> 0.
        warrior.takeDamage(30);
        assert(warrior.getHealth() == 50);
        warrior.heal(10);
        warrior.addExperience(50);
        assert(warrior.getExperience() == 100 && warrior.getLevel() == 2);
        warrior.levelUp();
        assert(warrior.getHealth() == 60 && warrior.getLevel() == 3 && warrior.getExperience() == 0);
        std::cout << "\nВоин после правильных операций:\n";
        warrior.print();

        // Неверные операции должны вернуть false и сохранить характеристики.
        std::cout << "\nПроверка ошибочных операций:\n";
        bool damageRejected = !warrior.takeDamage(-20);
        std::cout << "Попытка нанести урон -20: "
                  << (damageRejected ? "отказ — урон должен быть положительным." : "ошибочно выполнено.") << '\n';
        bool healRejected = !warrior.heal(0);
        std::cout << "Попытка восстановить 0 здоровья: "
                  << (healRejected ? "отказ — лечение должно быть положительным." : "ошибочно выполнено.") << '\n';
        bool experienceRejected = !warrior.addExperience(-10);
        std::cout << "Попытка добавить -10 опыта: "
                  << (experienceRejected ? "отказ — количество опыта должно быть положительным." : "ошибочно выполнено.") << '\n';
        bool levelRejected = !warrior.levelUp();
        std::cout << "Попытка повысить уровень при " << warrior.getExperience() << " опыта: "
                  << (levelRejected ? "отказ — требуется минимум 100 опыта." : "ошибочно выполнено.") << '\n';
        bool rejected = damageRejected && healRejected && experienceRejected && levelRejected;
        assert(rejected);
        assert(warrior.getHealth() == 60 && warrior.getLevel() == 3 && warrior.getExperience() == 0);
        std::cout << "Состояние после отклонённых операций:\n";
        warrior.print();

        // Даже большой урон или лечение сохраняют здоровье в пределах 0..100.
        warrior.takeDamage(1000);
        assert(warrior.getHealth() == 0);
        std::cout << "\nПосле урона 1000: " << warrior.getHealth() << '\n';
        warrior.heal(1000);
        assert(warrior.getHealth() == 100);
        std::cout << "После лечения 1000: " << warrior.getHealth() << '\n';

        std::cout << "\nОстальные персонажи после изменения воина:\n";
        hero.print();
        warriorCopy.print();
        assert(hero.getName().getFullName() == "Великий Герой" && hero.getHealth() == 100);
        assert(hero.getLevel() == 1 && hero.getExperience() == 0);
        assert(warriorCopy.getName().getFullName() == "Смелый Воин" && warriorCopy.getHealth() == 80);
        assert(warriorCopy.getLevel() == 2 && warriorCopy.getExperience() == 50);
        assert(warrior.getName().getFullName() == "Смелый Воин");
    } // Все три персонажа уничтожаются, вызываются их деструкторы.
    std::cout << "\nОбъектов после уничтожения: " << GameCharacter::getObjectCount() << '\n';
    assert(GameCharacter::getObjectCount() == 0);
    std::cout << "Все проверки пройдены.\n";
    return 0;
}
