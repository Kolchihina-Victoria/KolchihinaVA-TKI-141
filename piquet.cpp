#include "piquet.h"

/**
 * @brief Конструктор пикета
 */
Piquet::Piquet(int num, double sh, double len, bool standard)
    : number(num), shift(sh), length(len), isStandard(standard) {}

/**
 * @brief Преобразует пикет в строку
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

// Реализации операторов сравнения
bool Piquet::operator==(const Piquet& other) const {
    const double epsilon = 1e-9;
    return (number == other.number) && (std::abs(shift - other.shift) < epsilon);
}

bool Piquet::operator!=(const Piquet& other) const {
    return !(*this == other);
}

bool Piquet::operator<(const Piquet& other) const {
    const double epsilon = 1e-9;

    if (number < other.number - epsilon) return true;
    if (number > other.number + epsilon) return false;

    // Числа считаем равными, сравниваем shift
    return shift < other.shift;
}

bool Piquet::operator>(const Piquet& other) const {
    return other < *this;
}

bool Piquet::operator<=(const Piquet& other) const {
    return !(other < *this);
}

bool Piquet::operator>=(const Piquet& other) const {
    return !(*this < other);
}

/**
 * @brief Оператор вывода пикета в поток
 */
std::ostream& operator<<(std::ostream& os, const Piquet& p) {
    os << p.ToString();
    return os;
}

/**
 * @brief Оператор ввода пикета из потока
 */
std::istream& operator>>(std::istream& is, Piquet& p) {
    char pk;
    is >> pk; // Читаем 'П'
    if (pk != 'П') {
        is.setstate(std::ios::failbit);
        return is;
    }
    is >> pk; // Читаем 'К'
    if (pk != 'К') {
        is.setstate(std::ios::failbit);
        return is;
    }
    is >> p.number;

    char plus;
    is >> plus; // Читаем '+'
    if (plus != '+') {
        is.setstate(std::ios::failbit);
        return is;
    }

    is >> p.shift;
    return is;
}
