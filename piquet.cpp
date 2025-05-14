#include "piquet.h"

Piquet::Piquet(int num, double sh, double len, bool standard) 
    : number(num), shift(sh), length(len), isStandard(standard) {}

std::string Piquet::ToString() const {
    std::stringstream ss;
    ss << "ПК " << std::setfill('0');
    if (number >= 0) {
        ss << number;
    } else {
        ss << "0" << -number;
    }
    ss << "+" << std::fixed << std::setprecision(2) << shift;
    return ss.str();
}

bool Piquet::operator==(const Piquet& other) const {
    return (number == other.number && shift == other.shift);
}

bool Piquet::operator!=(const Piquet& other) const {
    return !(*this == other);
}

bool Piquet::operator<(const Piquet& other) const {
    if (number < other.number) return true;
    if (number == other.number && shift < other.shift) return true;
    return false;
}

// Остальные операторы сравнения...

std::ostream& operator<<(std::ostream& os, const Piquet& p) {
    os << p.ToString();
    return os;
}

std::istream& operator>>(std::istream& is, Piquet& p) {
    char pk, plus;
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
    is >> p.number >> plus >> p.shift; // Читаем номер и смещение
    if (plus != '+') {
        is.setstate(std::ios::failbit);
    }
    return is; // Обязательный возврат потока!
}