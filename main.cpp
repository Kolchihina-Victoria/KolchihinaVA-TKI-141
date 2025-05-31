#include <iostream>
#include <memory>
#include "piquet.h"
#include "speed_restriction.h"

/**
 * @brief Основная функция программы
 * @return Код завершения программы
 */
int main() {
    // Пример использования класса Piquet
    Piquet p1(12, 28.37);
    Piquet p2(-5, 50.0);
    std::cout << "Пикет 1: " << p1 << std::endl;
    std::cout << "Пикет 2: " << p2 << std::endl;

    if (p1 > p2) {
        std::cout << "Пикет 1 больше пикета 2" << std::endl;
    } else {
        std::cout << "Пикет 1 не больше пикета 2" << std::endl;
    }

    // Пример использования класса SpeedRestriction без сырого указателя
    std::cout << "\nВведите данные ограничения скорости:" << std::endl;
    auto restriction = SpeedRestriction::ReadFromStream(std::cin);

    if (restriction) {
        std::cout << "Введенное ограничение: " << *restriction << std::endl;
        // Не нужно вызывать delete - unique_ptr автоматически освободит память
    }

    return 0;
}
