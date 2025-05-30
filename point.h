#pragma once

#include <iostream>

/**
 * @brief Класс, представляющий точку в трехмерном пространстве.
 */
class Point {
private:
    double x; /**< Координата по оси X */
    double y; /**< Координата по оси Y */
    double z; /**< Координата по оси Z */

public:
    /**
     * @brief Конструктор класса Point.
     * @param x Координата X.
     * @param y Координата Y.
     * @param z Координата Z.
     */
    Point(double x = 0.0, double y = 0.0, double z = 0.0);

    /**
     * @brief Получить координату X.
     * @return Координата X.
     */
    double getX() const;

    /**
     * @brief Получить координату Y.
     * @return Координата Y.
     */
    double getY() const;

    /**
     * @brief Получить координату Z.
     * @return Координата Z.
     */
    double getZ() const;
};