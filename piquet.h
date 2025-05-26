#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

/**
 * @brief Класс для работы с пикетами (точками трассы)
 * 
 * Пикет представляет собой точку на трассе с номером и смещением.
 * Формат: ПК X+YY.YY, где X - номер, YY.YY - смещение в метрах.
 */
class Piquet {
public:
    int number;     ///< Номер пикета (целое число)
    double shift;   ///< Смещение от пикета в метрах
    double length;  ///< Длина пикета (по умолчанию 100 м)
    bool isStandard; ///< Флаг стандартного пикета (100 м)

    /**
     * @brief Конструктор пикета
     * @param num Номер пикета (по умолчанию 0)
     * @param sh Смещение от пикета в метрах (по умолчанию 0.0)
     * @param len Длина пикета в метрах (по умолчанию 100.0)
     * @param standard Флаг стандартного пикета (по умолчанию true)
     */
    explicit Piquet(int num = 0, double sh = 0.0, double len = 100.0, bool standard = true);

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
