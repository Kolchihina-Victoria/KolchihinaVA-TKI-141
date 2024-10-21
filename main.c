#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <stdbool.h>

/**
 * @brief считывает вещественное число
 * @return вещественное число
 */

double Input(void);

/**
 * @brief считывает вещественное число с проверкой знака
 * @return вещественное число в случае, если оно больше нуля
 */

double PInput(void);

/**
 * @brief определяет, пройдет ли кирпич в отверстие
 * @param x длина 1 стороны треугольника
 * @param y длина 2 стороны треугольника
 * @param z длина 3 стороны треугольника
 * @return true, если подходит и false, если не подходит
 */

bool iflengthenter(const double x, const double y, const double z);

/**
 * @brief точка входа в программу
 * @return 0 в случае успеха
 */
 
int main(void)
{
    puts("Введите длину 1 стороны x треугольника ");
    const double x = PInput();
    puts("Введите длину 2 стороны y треугольника ");
    const double y = PInput();
    puts("Введите длину 3 стороны z треугольника ");
    const double z = PInput();
    if (iflengthenter(x, y, z) == true)
    {
        puts("треугольник остроугольный");
        return 0;
    };
    puts("треугольник неостроугольный");
    return 0;
}
double Input(void)
{
    double value = 0.0;
    if (scanf_s("%lf", &value) != 1)
    {
        puts("Не является числом");
        exit(EXIT_FAILURE);
    }
    return value;
}
double PInput(void)
{
    double value = Input();
    if (value <= 0)
    {
        puts("Некорректное значение длины");
        exit(EXIT_FAILURE);
    }
    return value;
}
bool iflengthenter(const double x, const double y, const double z)
{
    if (pow(x,2)<(pow(y,2)+pow(z,2)))
    {
        return true;
    }
    return false;
}
