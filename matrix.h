#pragma once

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <memory>
#include <cmath>
#include <string>

template<typename T>
class Matrix {
private:
    size_t columns;
    size_t rows;
    std::unique_ptr<std::unique_ptr<T[]>[]> array;

    // Вспомогательный метод: проверка одинаковых первых двух цифр
    bool hasEqualFirstTwoDigits(T num) const;

public:
    // Конструкторы
    Matrix(size_t r, size_t c);                    // Для матрицы
    Matrix(size_t n);                              // Для вектора
    Matrix(const Matrix& other);                   // Конструктор копирования
    
    // Операторы присваивания
    Matrix& operator=(const Matrix& other);        // Копирующее присваивание
    Matrix& operator=(Matrix&& other) noexcept;    // Перемещающее присваивание

    // Геттеры
    size_t getRows() const;
    size_t getColumns() const;
    size_t size() const;

    // Операторы доступа
    T& operator()(size_t row, size_t col);
    const T& operator()(size_t row, size_t col) const;
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    // Методы заполнения
    void fillRandom(T minVal = -10, T maxVal = 20);
    void fillFromKeyboard(T minVal = -10, T maxVal = 20);

    // Основные методы по заданию
    void replaceLastNegative();
    void removeElementsWithEqualDigits();
    Matrix transformArray() const;

    // Метод вывода
    void print() const;
};
