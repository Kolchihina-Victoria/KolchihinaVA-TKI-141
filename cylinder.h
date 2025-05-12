#pragma once

#include "point.h"

/**
 * @brief Класс, представляющий цилиндр в трехмерном пространстве.
 */
class Cylinder {
private:
    Point center;   /**< Центр основания цилиндра */
    double radius;  /**< Радиус основания цилиндра */
    double height;  /**< Высота цилиндра */

public:
    /**
     * @brief Конструктор класса Cylinder.
     * @param center Центр основания цилиндра.
     * @param radius Радиус основания.
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