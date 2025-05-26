#include <iostream>
#include <limits>
#include "point.h"
#include "cylinder.h"

/**
 * @brief Запросить у пользователя координату с обработкой ошибок.
 * @param message Сообщение, которое будет выведено пользователю.
 * @return Введенная координата.
 * @throws std::invalid_argument Если введены некорректные данные.
 */
double getCoordinate(const std::string& message) {
    std::cout << message;
    double coordinate;
    std::cin >> coordinate;

    if (std::cin.fail()) {
        std::cin.clear(); // Очистить флаг ошибки
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очистить поток
        throw std::invalid_argument("Некорректный ввод");
    }
    return coordinate;
}

/**
 * @brief Запросить у пользователя координаты точки.
 * @return Объект Point с введенными координатами.
 */
Point getPoint() {
    double x = getCoordinate("Введите координату x: ");
    double y = getCoordinate("Введите координату y: ");
    double z = getCoordinate("Введите координату z: ");
    return Point(x, y, z);
}

/**
 * @brief Основная функция программы.
 * @return Код завершения.
 */
int main() {
    try {
        // Ввод центра цилиндра
        Point center = getPoint();

        // Ввод радиуса
        double radius = getCoordinate("Введите радиус: ");
       

        // Ввод высоты
        double height = getCoordinate("Введите высоту: ");
        

        // Создание цилиндра
        Cylinder cylinder(center, radius, height);

        // Вывод объема
        std::cout << "Объем цилиндра: " << cylinder.getVolume() << std::endl;

        // Проверка точки
        std::cout << "Введите координаты точки для проверки:" << std::endl;
        Point checkPoint = getPoint();

        if (cylinder.isPointInside(checkPoint)) {
            std::cout << "Точка внутри цилиндра." << std::endl;
        } else {
            std::cout << "Точка снаружи цилиндра." << std::endl;
        }

        return 0;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
}
