#pragma once
#include "restriction.h"
#include "piquet.h"

/**
 * @brief Класс ограничения скорости на участке трассы
 */
class SpeedRestriction : public Restriction {
public:
    Piquet start;      ///< Начальная точка ограничения
    Piquet end;        ///< Конечная точка ограничения
    double speedLimit; ///< Ограничение скорости (км/ч)

    /**
     * @brief Конструктор ограничения скорости
     */
    SpeedRestriction(const Piquet& st, const Piquet& en, double speed = 0.0);

    /**
     * @brief Преобразует ограничение в строку
     */
    std::string ToString() const override;

    /**
     * @brief Создает ограничение скорости из потока ввода
     */
    static Restriction* ReadFromStream(std::istream& is);
};
