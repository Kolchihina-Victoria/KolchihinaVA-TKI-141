#include <iostream>
#include "point.h"
#include "cylinder.h"

/**
 * @brief Функция для запроса и получения координаты от пользователя.
 * @param message Сообщение для пользователя.
 * @return Введенная координата.
 * @throws std::invalid_argument Если введенные данные некорректны.
 */
double getCoordinate(std::string message);

/**
 * @brief Функция для запроса и получения координат точки от пользователя.
 * @return Объект Point, представляющий введенные координаты.
 */
Point getPoint();

int main() {
    try {
        Point cylinderCenter = getPoint();
        double cylinderRadius = getCoordinate("enter the radius: ");
        if (cylinderRadius <= 0) {
            throw std::invalid_argument("Radius must be positive.");
        }
        double cylinderHeight = getCoordinate("enter the height: ");
        if (cylinderHeight <= 0) {
            throw std::invalid_argument("Height must be positive.");
        }

        Cylinder cylinder(cylinderCenter, cylinderRadius, cylinderHeight);
        std::cout << "Volume: " << cylinder.getVolume() << std::endl;

        std::cout << "Enter coordinates for check:" << std::endl;
        Point checkPoint = getPoint();

        if (cylinder.isPointInside(checkPoint)) {
            std::cout << "Point inside." << std::endl;
        } else {
            std::cout << "Point outside." << std::endl;
        }

        return 0;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}

double getCoordinate(std::string message) {
    std::cout << message << std::endl;
    double coordinate = 0.0;
    std::cin >> coordinate;

    if (std::cin.fail()) {
        std::cin.clear();  // Очистить флаг ошибки
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Убрать "плохие" символы из потока
        throw std::invalid_argument("Your input is uncorrected");
    }
    return coordinate;
}

Point getPoint() {
    double x = getCoordinate("enter coordinate x: ");
    double y = getCoordinate("enter coordinate y: ");
    double z = getCoordinate("enter coordinate z: ");
    return Point(x, y, z);
}
#ifndef POINT_H
#define POINT_H

#include <iostream>

/**
 * @brief Класс, представляющий точку в трехмерном пространстве.
 */
class Point {
private:
    double x;
    double y;
    double z;

public:
    /**
     * @brief Конструктор класса Point.
     * @param x Координата x.
     * @param y Координата y.
     * @param z Координата z.
     */
    Point(double x = 0.0, double y = 0.0, double z = 0.0);

    /**
     * @brief Получить координату x.
     * @return Координата x.
     */
    double getX() const;

    /**
     * @brief Получить координату y.
     * @return Координата y.
     */
    double getY() const;

    /**
     * @brief Получить координату z.
     * @return Координата z.
     */
    double getZ() const;
};
#endif

#include "point.h"

Point::Point(double x, double y, double z) : x(x), y(y), z(z) {}

double Point::getX() const {
    return x;
}

double Point::getY() const {
    return y;
}

double Point::getZ() const {
    return z;
}


#ifndef CYLINDER_H
#define CYLINDER_H

#include "point.h"

/**
 * @brief Класс, представляющий цилиндр в трехмерном пространстве.
 */
class Cylinder {
private:
    Point center;   /**< Центр основания цилиндра. */
    double radius;  /**< Радиус основания цилиндра. */
    double height;  /**< Высота цилиндра. */

public:
    /**
     * @brief Конструктор класса Cylinder.
     * @param center Центр основания цилиндра.
     * @param radius Радиус основания цилиндра.
     * @param height Высота цилиндра.
     */
    Cylinder(const Point& center, double radius, double height);

    /**
     * @brief Получить радиус цилиндра.
     * @return Радиус цилиндра.
     */
    double getRadius() const;

    /**
     * @brief Получить высоту цилиндра.
     * @return Высота цилиндра.
     */
    double getHeight() const;

    /**
     * @brief Вычислить объем цилиндра.
     * @return Объем цилиндра.
     */
    double getVolume() const;

    /**
     * @brief Проверить, находится ли точка внутри цилиндра.
     * @param point Точка для проверки.
     * @return true, если точка внутри цилиндра, false в противном случае.
     */
    bool isPointInside(const Point& point) const;
};
#endif

#include "cylinder.h"
#include <cmath>
#include <stdexcept>

#define _USE_MATH_DEFINES // for C++
#include <cmath>

Cylinder::Cylinder(const Point& center, double radius, double height) :
    center(center), radius(radius), height(height) {
    if (radius <= 0 || height <= 0) {
        throw std::invalid_argument("Radius and height must be positive values.");
    }
}

double Cylinder::getRadius() const {
    return radius;
}

double Cylinder::getHeight() const {
    return height;
}

double Cylinder::getVolume() const {
    return M_PI * radius * radius * height;
}

bool Cylinder::isPointInside(const Point& point) const {
    double dx = point.getX() - center.getX();
    double dy = point.getY() - center.getY();
    double dz = point.getZ() - center.getZ();

    if (dx * dx + dy * dy > radius * radius) {
        return false;
    }

    if (dz < center.getZ() || dz > center.getZ() + height) { // Используем координаты центра
        return false;
    }

    return true;
}
