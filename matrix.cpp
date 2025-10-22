#pragma once

#include "matrix.h"
#include <stdexcept>

// Реализация методов шаблонного класса

// Конструктор для матрицы
template<typename T>
Matrix<T>::Matrix(size_t r, size_t c) : rows(r), columns(c) {
    array = std::make_unique<std::unique_ptr<T[]>[]>(rows);
    for (size_t i = 0; i < rows; ++i) {
        array[i] = std::make_unique<T[]>(columns);
    }
}

// Конструктор для вектора
template<typename T>
Matrix<T>::Matrix(size_t n) : rows(1), columns(n) {
    array = std::make_unique<std::unique_ptr<T[]>[]>(rows);
    array[0] = std::make_unique<T[]>(columns);
}

// Конструктор копирования
template<typename T>
Matrix<T>::Matrix(const Matrix& other) : rows(other.rows), columns(other.columns) {
    array = std::make_unique<std::unique_ptr<T[]>[]>(rows);
    for (size_t i = 0; i < rows; ++i) {
        array[i] = std::make_unique<T[]>(columns);
        for (size_t j = 0; j < columns; ++j) {
            array[i][j] = other.array[i][j];
        }
    }
}

// Геттеры
template<typename T>
size_t Matrix<T>::getRows() const { return rows; }

template<typename T>
size_t Matrix<T>::getColumns() const { return columns; }

template<typename T>
size_t Matrix<T>::size() const { return columns; }

// Операторы доступа к элементам матрицы
template<typename T>
T& Matrix<T>::operator()(size_t row, size_t col) {
    if (row >= rows || col >= columns) {
        throw std::out_of_range("Matrix indices out of range");
    }
    return array[row][col];
}

template<typename T>
const T& Matrix<T>::operator()(size_t row, size_t col) const {
    if (row >= rows || col >= columns) {
        throw std::out_of_range("Matrix indices out of range");
    }
    return array[row][col];
}

// Операторы доступа для вектора
template<typename T>
T& Matrix<T>::operator[](size_t index) {
    if (index >= columns) {
        throw std::out_of_range("Vector index out of range");
    }
    return array[0][index];
}

template<typename T>
const T& Matrix<T>::operator[](size_t index) const {
    if (index >= columns) {
        throw std::out_of_range("Vector index out of range");
    }
    return array[0][index];
}

// Метод заполнения случайными числами
template<typename T>
void Matrix<T>::fillRandom(T minVal, T maxVal) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<T> distrib(minVal, maxVal);

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            array[i][j] = distrib(gen);
        }
    }
}

// Метод заполнения с клавиатуры
template<typename T>
void Matrix<T>::fillFromKeyboard(T minVal, T maxVal) {
    std::cout << "Введите " << columns << " целых чисел в диапазоне [" 
              << minVal << "; " << maxVal << "]:" << std::endl;
    
    for (size_t i = 0; i < columns; ++i) {
        T input;
        std::cout << "Элемент " << i + 1 << ": ";
        
        while (!(std::cin >> input) || input < minVal || input > maxVal) {
            std::cout << "Ошибка: Введенное число не входит в диапазон [" 
                     << minVal << "; " << maxVal << "] или не является числом. Повторите ввод: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
        
        array[0][i] = input;
    }
}

// Вспомогательный метод: проверка одинаковых первых двух цифр
template<typename T>
bool Matrix<T>::hasEqualFirstTwoDigits(T num) const {
    if (num < 0) {
        num = -num;
    }

    if (num < 10) {
        return false;
    }

    if (num < 100) {
        return (num / 10) == (num % 10);
    } else {
        std::string numStr = std::to_string(num);
        return numStr.length() >= 2 && numStr[0] == numStr[1];
    }
}

// Метод 1: Замена последнего отрицательного элемента
template<typename T>
void Matrix<T>::replaceLastNegative() {
    int lastNegativeIndex = -1;

    for (size_t i = 0; i < columns; ++i) {
        if (array[0][i] < 0) {
            lastNegativeIndex = i;
        }
    }

    if (lastNegativeIndex != -1) {
        array[0][lastNegativeIndex] = std::abs(array[0][0]);
    }
}

// Метод 2: Удаление элементов с одинаковыми цифрами
template<typename T>
void Matrix<T>::removeElementsWithEqualDigits() {
    std::vector<T> tempArray;

    for (size_t i = 0; i < columns; ++i) {
        if (!hasEqualFirstTwoDigits(array[0][i])) {
            tempArray.push_back(array[0][i]);
        }
    }

    Matrix newMatrix(tempArray.size());
    for (size_t i = 0; i < tempArray.size(); ++i) {
        newMatrix[i] = tempArray[i];
    }

    *this = std::move(newMatrix);
}

// Метод 3: Преобразование массива по правилу
template<typename T>
Matrix<T> Matrix<T>::transformArray() const {
    Matrix result(columns);

    for (size_t i = 0; i < columns; ++i) {
        if (array[0][i] % 2 == 0) {
            result[i] = i * array[0][i];
        } else {
            result[i] = -array[0][i];
        }
    }

    return result;
}

// Метод вывода массива
template<typename T>
void Matrix<T>::print() const {
    std::cout << "Массив [" << columns << "]: ";
    for (size_t i = 0; i < columns; ++i) {
        std::cout << array[0][i] << " ";
    }
    std::cout << std::endl;
}

// Оператор присваивания
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other) {
    if (this != &other) {
        rows = other.rows;
        columns = other.columns;
        
        array = std::make_unique<std::unique_ptr<T[]>[]>(rows);
        for (size_t i = 0; i < rows; ++i) {
            array[i] = std::make_unique<T[]>(columns);
            for (size_t j = 0; j < columns; ++j) {
                array[i][j] = other.array[i][j];
            }
        }
    }
    return *this;
}

// Move assignment
template<typename T>
Matrix<T>& Matrix<T>::operator=(Matrix&& other) noexcept {
    if (this != &other) {
        rows = other.rows;
        columns = other.columns;
        array = std::move(other.array);
        
        other.rows = 0;
        other.columns = 0;
    }
    return *this;
}
