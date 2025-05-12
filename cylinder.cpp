#include "cylinder.h"
#include <cmath>
#include <stdexcept>

#define _USE_MATH_DEFINES // Для использования M_PI
#include <cmath>

Cylinder::Cylinder(const Point& center, double radius, double height) :
    center(center), radius(radius), height(height) {
    if (radius <= 0 || height <= 0) {
        throw std::invalid_argument("Радиус и высота должны быть положительными числами");
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
    // Расстояние по XY от центра основания
    double dx = point.getX() - center.getX();
    double dy = point.getY() - center.getY();
    // Расстояние по Z относительно базового уровня
    double dz = point.getZ() - center.getZ();

    // Проверка внутри круга основания
    if (dx * dx + dy * dy > radius * radius) {
        return false;
    }

    // Проверка по высоте
    if (dz < 0 || dz > height) {
        return false;
    }

    return true;
}