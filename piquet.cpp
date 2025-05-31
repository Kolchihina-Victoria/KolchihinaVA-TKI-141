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
    : number(num), shift(sh), length(len), isStandard(len >= 100.0) {} // 1) исправлено: учтено смещение, пикет стандартный если длина >= 100.0

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
    return (number == other.number) && (std::abs(shift - other.shift) < std::numeric_limits<double>::epsilon()) && (std::abs(length - other.length) < std::numeric_limits<double>::epsilon()); //2) исправлено, сравниваем по длине, номеру и смещению
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
 * @brief Оператор "меньше"
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
 * @brief Оператор "больше"
 * @param other Другой пикет для сравнения
 * @return true если текущий пикет больше другого, false в противном случае
 */
bool Piquet::operator>(const Piquet& other) const {
    return other < *this;
}

/**
 * @brief Оператор "меньше или равно"
 * @param other Другой пикет для сравнения
 * @return true если текущий пикет меньше или равен другому, false в противном случае
 */
bool Piquet::operator<=(const Piquet& other) const {
    return !(other < *this);
}

/**
 * @brief Оператор "больше или равно"
 * @param other Другой пикет для сравнения
 * @return true если текущий пикет больше или равен другому, false в противном случае
 */
bool Piquet::operator>=(const Piquet& other) const {
    return !(*this < other);
}

/**
 * @brief Перегрузка оператора вывода в поток
 * @param os Ссылка на выходной поток
 * @param p Ссылка на объект Piquet
 * @return Ссылка на выходной поток
 */
std::ostream& operator<<(std::ostream& os, const Piquet& p) { //4
    os << p.ToString();
    return os;
}

/**
 * @brief Перегрузка оператора ввода из потока
 * @param is Ссылка на входной поток
 * @param p Ссылка на объект Piquet
 * @return Ссылка на входной поток
 */
std::istream& operator>>(std::istream& is, Piquet& p) {  //4
    char pk[3];
    int num;
    char plus;
    double shift;

    is >> std::setw(2) >> pk >> num >> plus >> shift;

    if (pk[0] == 'П' && pk[1] == 'К' && plus == '+') {
        p.number = num;
        p.shift = shift;
    } else {
        is.setstate(std::ios::failbit); // Устанавливаем флаг ошибки, если формат неверный
    }

    return is;
}
