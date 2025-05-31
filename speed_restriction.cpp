#include "speed_restriction.h"
#include <iomanip>
#include <memory>

// ... остальные методы остаются без изменений ...

std::unique_ptr<Restriction> SpeedRestriction::ReadFromStream(std::istream& is) {
    Piquet start, end;
    double speed;

    std::cout << "Введите начало ограничения (формат: ПК X+YY.YY): ";
    if (!(is >> start)) {
        std::cerr << "Ошибка: Некорректный формат начальной точки." << std::endl;
        return nullptr;
    }

    std::cout << "Введите конец ограничения (формат: ПК X+YY.YY): ";
    if (!(is >> end)) {
        std::cerr << "Ошибка: Некорректный формат конечной точки." << std::endl;
        return nullptr;
    }

    if (end < start) {
        std::cerr << "Ошибка: Конечная точка должна быть после начальной." << std::endl;
        return nullptr;
    }

    std::cout << "Введите ограничение скорости (0-80 км/ч): ";
    if (!(is >> speed) || speed < 0 || speed > 80) {
        std::cerr << "Ошибка: Скорость должна быть числом от 0 до 80 км/ч." << std::endl;
        return nullptr;
    }

    return std::make_unique<SpeedRestriction>(start, end, speed);
}
