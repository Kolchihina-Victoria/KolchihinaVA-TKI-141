#include "speed_restriction.h"

SpeedRestriction::SpeedRestriction(const Piquet& st, const Piquet& en, double speed)
    : start(st), end(en), speedLimit(speed) {}

std::string SpeedRestriction::ToString() const {
    std::stringstream ss;
    ss << "Ограничение скорости: " << start << " - " << end
       << ", Скорость: " << speedLimit << " км/ч";
    return ss.str();
}

Restriction* SpeedRestriction::ReadFromStream(std::istream& is) {
    Piquet start, end;
    double speed;

    std::cout << "Введите начало ограничения (например, ПК 10+00.00): ";
    if (!(is >> start)) {
        std::cerr << "Ошибка при чтении начала ограничения." << std::endl;
        return nullptr;
    }

    std::cout << "Введите конец ограничения (например, ПК 12+50.00): ";
    if (!(is >> end)) {
        std::cerr << "Ошибка при чтении конца ограничения." << std::endl;
        return nullptr;
    }

    std::cout << "Введите ограничение скорости (км/ч): ";
    if (!(is >> speed)) {
        std::cerr << "Ошибка при чтении ограничения скорости." << std::endl;
        return nullptr;
    }

    if (speed < 0 || speed > 80) {
        std::cerr << "Ошибка: Ограничение скорости должно быть в диапазоне от 0 до 80 км/ч." << std::endl;
        return nullptr;
    }

    return new SpeedRestriction(start, end, speed);
}
