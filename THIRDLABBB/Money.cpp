/** @file Money.cpp @brief Реализация класса Money. */

#include "Money.h"

#include <iostream>
#include <stdexcept>
#include <climits>

int Money::objectCount = 0;

Money::Money() : totalKopecks(0), printCount(0)
{
    ++objectCount;
}

Money::Money(long long kopecks) : totalKopecks(kopecks), printCount(0)
{
    if (kopecks < 0) {
        throw std::invalid_argument("Сумма не может быть отрицательной.");
    }
    ++objectCount;
}

Money::Money(const Money& other) : totalKopecks(other.totalKopecks), printCount(0)
{
    ++objectCount;
}

Money::~Money()
{
    --objectCount;
}

int Money::getObjectCount()
{
    return objectCount;
}

unsigned int Money::getPrintCount() const
{
    return printCount;
}

Money& Money::operator+=(const Money& other)
{
    if (other.totalKopecks > LLONG_MAX - totalKopecks) {
        throw std::overflow_error("Сумма слишком большая.");
    }
    totalKopecks += other.totalKopecks;
    return *this;
}

Money& Money::operator-=(const Money& other)
{
    if (other.totalKopecks > totalKopecks) {
        throw std::invalid_argument("Нельзя вычесть больше имеющейся суммы.");
    }
    totalKopecks -= other.totalKopecks;
    return *this;
}

Money& Money::operator*=(long long factor)
{
    if (factor < 0) {
        throw std::invalid_argument("Множитель не может быть отрицательным.");
    }
    if (factor != 0 && totalKopecks > LLONG_MAX / factor) {
        throw std::overflow_error("Сумма слишком большая.");
    }
    totalKopecks *= factor;
    return *this;
}

Money& Money::operator/=(long long divisor)
{
    if (divisor <= 0) {
        throw std::invalid_argument("Делитель должен быть положительным.");
    }
    totalKopecks /= divisor;
    return *this;
}

Money Money::operator+(const Money& other) const
{
    Money result(*this);
    result += other;
    return result;
}

Money Money::operator-(const Money& other) const
{
    Money result(*this);
    result -= other;
    return result;
}

Money Money::operator*(long long factor) const
{
    Money result(*this);
    result *= factor;
    return result;
}

Money Money::operator/(long long divisor) const
{
    Money result(*this);
    result /= divisor;
    return result;
}

Money& Money::operator++()
{
    *this += Money(1);
    return *this;
}

Money Money::operator++(int)
{
    Money old(*this);
    ++(*this);
    return old;
}

Money& Money::operator--()
{
    *this -= Money(1);
    return *this;
}

Money Money::operator--(int)
{
    Money old(*this);
    --(*this);
    return old;
}

bool Money::operator==(const Money& other) const
{
    return totalKopecks == other.totalKopecks;
}

bool Money::operator!=(const Money& other) const
{
    return totalKopecks != other.totalKopecks;
}

bool Money::operator<(const Money& other) const
{
    return totalKopecks < other.totalKopecks;
}

bool Money::operator>(const Money& other) const
{
    return totalKopecks > other.totalKopecks;
}

bool Money::operator<=(const Money& other) const
{
    return totalKopecks <= other.totalKopecks;
}

bool Money::operator>=(const Money& other) const
{
    return totalKopecks >= other.totalKopecks;
}

std::string Money::toString() const
{
    return std::to_string(totalKopecks / 100) + " руб. "
           + std::to_string(totalKopecks % 100) + " коп.";
}

void Money::print() const
{
    ++printCount;
    std::cout << toString() << '\n';
}
