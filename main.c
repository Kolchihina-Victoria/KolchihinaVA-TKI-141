#include <iostream>
#include <string>
#include <cmath>

// Определение класса Point
class Point {
private:
    double x;
    double y;
    double z;

public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0);
    double getX() const;
    double getY() const;
    double getZ() const;
};

// Реализация методов класса Point
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

// Определение класса Cylindr
class Cylindr {
private:
    Point center;
    double radius;
    double height;

public:
    Cylindr(const Point& center, double radius, double height);
    double getRadius() const;
    double getHeight() const;
    double getVolume() const;
    bool isPointInside(const Point& point) const;
};

// Реализация методов класса Cylindr
const double PI = 3.14159;

Cylindr::Cylindr(const Point& center, double radius, double height) :
    center(center), radius(radius), height(height) {}

double Cylindr::getRadius() const {
    return radius;
}

double Cylindr::getHeight() const {
    return height;
}

double Cylindr::getVolume() const {
    return PI * radius * radius * height;
}

bool Cylindr::isPointInside(const Point& point) const {
    double dx = point.getX() - center.getX();
    double dy = point.getY() - center.getY();
    double dz = point.getZ() - center.getZ();

    if (dx * dx + dy * dy > radius * radius) {
        return false;
    }

    if (dz < 0 || dz > height) {
        return false;
    }

    return true;
}

// Прототипы функций
double getCoordinate(std::string message);
Point getPoint();

int main() {
    Point cylindrCenter = getPoint();
    double cylindrRadius = getCoordinate("enter the radius: ");
    double cylindrHeight = getCoordinate("enter the height: ");

    Cylindr cylindr(cylindrCenter, cylindrRadius, cylindrHeight);
    std::cout << "volume: " << cylindr.getVolume() << std::endl;
    std::cout << "enter coordinates for check:" << std::endl;
    Point checkPoint = getPoint();
    if (cylindr.isPointInside(checkPoint)) {
        std::cout << "point inside." << std::endl;
    } else {
        std::cout << "point outside." << std::endl;
    }

    return 0;
}

double getCoordinate(std::string message) {
    std::cout << message << std::endl;
    double coordinate = 0.0;
    std::cin >> coordinate;
    if (std::cin.fail()) {
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
