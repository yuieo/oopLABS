/**
 * @file GameCharacter.h
 * @brief Объявления классов имени и игрового персонажа.
 */

/**
 * @mainpage Лабораторная работа №2
 *
 * Вариант 12 — «Компьютерная игра». Стандарт языка: C++14.
 *
 * @section domain Описание предметной области
 * Объект GameCharacter представляет одного игрового персонажа.
 * Его характеризуют имя с прилагательным, здоровье, уровень и накопленный опыт.
 * Пользовательский тип CharacterName хранит само имя и прилагательное.
 * Персонаж может получать урон, лечиться, получать опыт и повышать уровень.
 * Недопустимы здоровье вне диапазона от 0 до 100 или неконечное здоровье,
 * уровень ниже 1 и отрицательный опыт.
 *
 * @section design Таблица проектирования
 * Элемент | Описание
 * --- | ---
 * Имя класса | GameCharacter
 * Поля | name: CharacterName; health: double; level: int; experience: int
 * Конструкторы | Без аргументов, параметризованный, копирующий
 * Методы чтения | getName(), getHealth(), getLevel(), getExperience(), print()
 * Методы изменения | takeDamage(), heal(), addExperience(), levelUp()
 * Инварианты | Конечное здоровье от 0 до 100; уровень не ниже 1; опыт неотрицательный
 * Учёт объектов | Статическое поле objectCount, метод getObjectCount() и деструктор
 *
 * Максимум здоровья 100 и стоимость повышения уровня 100 единиц опыта
 * выбраны для этой модели. Получение опыта автоматически не повышает уровень.
 *
 * @section diagram UML-диаграмма
 * Исходное описание диаграммы хранится в GameCharacter.puml.
 * @image html GameCharacter.png "Класс GameCharacter"
 */

#ifndef GAME_CHARACTER_H
#define GAME_CHARACTER_H

#include <string>

/**
 * @brief Имя персонажа и описывающее его прилагательное.
 */
class CharacterName
{
private:
    std::string name;      ///< Само имя персонажа.
    std::string adjective; ///< Прилагательное перед именем.

public:
    /** @brief Создаёт имя «Великий Герой». */
    CharacterName();

    /**
     * @brief Создаёт имя с заданным прилагательным.
     * @param newName Само имя персонажа.
     * @param newAdjective Прилагательное перед именем.
     */
    CharacterName(const std::string& newName, const std::string& newAdjective);

    /** @brief Возвращает само имя. @return Копия имени. */
    std::string getName() const;

    /** @brief Возвращает прилагательное. @return Копия прилагательного. */
    std::string getAdjective() const;

    /** @brief Соединяет прилагательное и имя. @return Полное имя персонажа. */
    std::string getFullName() const;
};


/**
 * @brief Игровой персонаж с именем, здоровьем, уровнем и опытом.
 * @invariant Здоровье находится в диапазоне от 0 до 100.
 * @invariant Уровень не ниже 1.
 * @invariant Опыт неотрицательный.
 */
class GameCharacter
{
private:
    CharacterName name; ///< Имя персонажа с прилагательным.
    double health;    ///< Текущее здоровье.
    int level;        ///< Уровень персонажа.
    int experience;   ///< Накопленный опыт.
    static int objectCount; ///< Количество существующих объектов класса.

public:
    /**
     * @brief Создаёт персонажа с именем «Великий Герой», здоровьем 100,
     * уровнем 1 и опытом 0.
     */
    GameCharacter();

    /**
     * @brief Создаёт персонажа с заданными характеристиками.
     * @param newName Имя персонажа с прилагательным.
     * @param newHealth Конечное значение здоровья от 0 до 100.
     * @param newLevel Уровень, не ниже 1.
     * @param newExperience Неотрицательный опыт.
     * @throws std::invalid_argument Если характеристики недопустимы.
     */
    GameCharacter(const CharacterName& newName, double newHealth,
                  int newLevel, int newExperience);

    /**
     * @brief Создаёт независимую копию персонажа.
     * @param other Персонаж, характеристики которого копируются.
     */
    GameCharacter(const GameCharacter& other);

    /**
     * @brief Уменьшает счётчик при уничтожении персонажа.
     */
    ~GameCharacter();

    /**
     * @brief Возвращает количество существующих персонажей.
     * @return Общее количество объектов класса.
     */
    static int getObjectCount();

    /**
     * @brief Возвращает имя персонажа.
     * @return Копия объекта имени с прилагательным.
     */
    CharacterName getName() const;

    /**
     * @brief Возвращает здоровье персонажа.
     * @return Текущее здоровье.
     */
    double getHealth() const;

    /**
     * @brief Возвращает уровень персонажа.
     * @return Текущий уровень.
     */
    int getLevel() const;

    /**
     * @brief Возвращает опыт персонажа.
     * @return Накопленный опыт.
     */
    int getExperience() const;

    /**
     * @brief Уменьшает здоровье, но не ниже нуля.
     * @param damage Конечное положительное значение урона.
     * @return true, если операция принята; false при неверном аргументе.
     * @note При неверном аргументе состояние не изменяется.
     */
    bool takeDamage(double damage);

    /**
     * @brief Восстанавливает здоровье, но не выше 100.
     * @param amount Конечное положительное значение лечения.
     * @return true, если операция принята; false при неверном аргументе.
     * @note При неверном аргументе состояние не изменяется.
     */
    bool heal(double amount);

    /**
     * @brief Добавляет опыт без автоматического повышения уровня.
     * @param amount Положительное количество опыта.
     * @return true при успехе; false при неверном аргументе или переполнении.
     * @note При отказе состояние не изменяется.
     */
    bool addExperience(int amount);

    /**
     * @brief Повышает уровень на 1, расходуя 100 единиц опыта.
     * @return true при успехе; false при недостатке опыта или максимальном int-уровне.
     * @note При отказе состояние не изменяется.
     */
    bool levelUp();

    /**
     * @brief Выводит имя, здоровье, уровень и опыт персонажа.
     */
    void print() const;
};

#endif
