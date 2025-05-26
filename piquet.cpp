#include "piquet.h"
#include <cmath>
#include <iomanip>

/**
 * @brief Конструктор пикета
 * @param num Номер пикета
 * @param sh Смещение от пикета
 * @param len Длина пикета
 * @param standard Флаг стандартного пикета
 */
Piquet::Piquet(int num, double sh, double len, bool standard)
    : number(num), shift(sh), length(len), isStandard(standard) {}

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
    const double epsilon = 1e-9;
    return (number == other.number) && (std::abs(shift - other.shift) < epsilon);
}

/**
 * @brief Оператор сравнения на неравенство
 * @param other Другой пикет для сравнения
 * @return true если пикеты не равны, false в противном случае
 */
bool Piquet::operator!=(const Piquet& other) const {
    return !(*this == other);
}

/**
 * @brief Оператор сравнения "меньше"
 * @param other Другой пикет для сравнения
 * @return true если текущий пикет меньше другого, false в противном случае
 */
bool Piquet::operator<(const Piquet& other) const {
    if (number != other.number) {
        return number < other.number;
    }
    return shift < other.shift;
}

/**
 * @brief Оператор сравнения "больше"
 * @param other Другой пикет для сравнения
 * @return true если текущий пикет больше другого, false в противном случае
 */
bool Piquet::operator>(const Piquet& other) const {
    return other < *this;
}

/**
 * @brief Оператор сравнения "меньше или равно"
 * @param other Другой пикет для сравнения
 * @return true если текущий пикет меньше или равен другому, false в противном случае
 */
bool Piquet::operator<=(const Piquet& other) const {
    return !(other < *this);
}

/**
 * @brief Оператор сравнения "больше или равно"
 * @param other Другой пикет для сравнения
 * @return true если текущий пикет больше или равен другому, false в противном случае
 */
bool Piquet::operator>=(const Piquet& other) const {
    return !(*this < other);
}

/**
 * @brief Оператор вывода пикета в поток
 * @param os Выходной поток
 * @param p Пикет для вывода
 * @return Ссылку на выходной поток
 */
std::ostream& operator<<(std::ostream& os, const Piquet& p) {
    os << p.ToString();
    return os;
}

/**
 * @brief Оператор ввода пикета из потока
 * @param is Входной поток
 * @param p Пикет для ввода
 * @return Ссылку на входной поток
 */
std::istream& operator>>(std::istream& is, Piquet& p) {
    char pk, k, plus;
    is >> pk >> k;
    if (pk != 'П' || k != 'К') {
        is.setstate(std::ios::failbit);
        return is;
    }

    if (!(is >> p.number >> plus) || plus != '+') {
        is.setstate(std::ios::failbit);
        return is;
    }

    if (!(is >> p.shift)) {
        is.setstate(std::ios::failbit);
    }

    return is;
}
