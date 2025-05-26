#include "restriction.h"
#include "speed_restriction.h"

/**
 * @brief Создает ограничение из потока ввода
 * @param is Входной поток
 * @return Указатель на созданное ограничение или nullptr при ошибке
 * 
 * @note В базовой реализации просто вызывает ReadFromStream для SpeedRestriction
 * В реальном проекте здесь может быть фабрика для разных типов ограничений
 */
Restriction* Restriction::ReadFromStream(std::istream& is) {
    return SpeedRestriction::ReadFromStream(is);
}

/**
 * @brief Оператор вывода ограничения в поток
 * @param os Выходной поток
 * @param r Ограничение для вывода
 * @return Ссылку на выходной поток
 */
std::ostream& operator<<(std::ostream& os, const Restriction& r) {
    os << r.ToString();
    return os;
}
