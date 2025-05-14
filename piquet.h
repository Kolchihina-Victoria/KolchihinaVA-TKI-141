#pragma once
#include <iostream>
#include <sstream>
#include <iomanip>

/**
 * @brief Класс для работы с пикетами (точками трассы)
 * 
 * Пикет - это точка на трассе, обозначаемая как ПК X+YY.YY,
 * где X - номер пикета, YY.YY - смещение в метрах
 */
class Piquet {
public:
    int number;     ///< Номер пикета (целая часть)
    double shift;   ///< Смещение от пикета (дробная часть в метрах)
    double length;  ///< Длина пикета (по умолчанию 100 м)
    bool isStandard; ///< Флаг стандартного пикета (100 м)

    /**
     * @brief Конструктор пикета
     * @param num Номер пикета
     * @param sh Смещение от пикета
     * @param len Длина пикета
     * @param standard Флаг стандартного пикета
     */
    Piquet(int num = 0, double sh = 0.0, double len = 100.0, bool standard = true);

    /**
     * @brief Преобразует пикет в строку формата "ПК X+YY.YY"
     * @return Строковое представление пикета
     */
    std::string ToString() const;

    // Операторы сравнения
    bool operator==(const Piquet& other) const;
    bool operator!=(const Piquet& other) const;
    bool operator<(const Piquet& other) const;
    bool operator>(const Piquet& other) const;
    bool operator<=(const Piquet& other) const;
    bool operator>=(const Piquet& other) const;

    // Дружественные операторы ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const Piquet& p);
    friend std::istream& operator>>(std::istream& is, Piquet& p);
};
