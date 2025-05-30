#include "piquet.h"
#include <cmath>
#include <iomanip>
#include <limits>

/**
 * @brief Конструктор пикета
 * @param num Номер пикета
 * @param sh Смещение от пикета
 * @param len Длина пикета
 * @param standard Флаг стандартного пикета
 */
Piquet::Piquet(int num, double sh, double len, bool standard)
    : number(num), shift(sh), length(len), isStandard(len == 100.0) {} // 1. Исправлено

/**
 * @brief Преобразует пикет в строку формата "ПК X+YY.YY"
 * @return Строковое представление пикета
 */
std::string Piquet::ToString() const {
    std::stringstream ss;
    ss << "ПК ";
    if (number >= 0) {
        ss << number;
    } else {
        ss << "0" << -number; // Для отрицательных точек
    }
    ss << "+" << std::fixed << std::setprecision(2) << shift;
    return ss.str();
}

/**
 * @brief Оператор сравнения на равенство
 * @param other Другой пикет для сравнения
 * @return true если пикеты равны, false в противном случае
 */
bool Piquet::operator==(const Piquet& other) const {
    //const double epsilon = 1e-9; //2.  исправлено
    return (number == other.number) && (std::abs(shift - other.shift) < std::numeric_limits<double>::epsilon()); //2. Исправлено
}
