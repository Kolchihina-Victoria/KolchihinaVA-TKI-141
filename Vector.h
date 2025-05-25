#pragma once // Используем #pragma once для защиты от многократного включения

#include <cstddef>  // Для size_t
#include <string>   // Для std::string
#include <initializer_list> // Для std::initializer_list
#include <sstream>  // Для std::ostringstream
#include <algorithm> // std::copy, std::remove

class Vector {
private:
    int* data;          // Указатель на массив элементов
    size_t size;        // Текущее количество элементов
    size_t capacity;    // Максимальное количество элементов, которое может вместить массив

    void resize(size_t newCapacity);  // Вспомогательная функция для изменения размера массива

public:
    // Конструкторы
    Vector();                                             // Конструктор по умолчанию
    Vector(size_t initialCapacity);                       // Конструктор с заданной начальной емкостью
    Vector(const std::initializer_list<int>& list);       // Конструктор со списком инициализации
    Vector(const Vector& other);                         // Конструктор копирования

    // Деструктор
    ~Vector();

    // Операторы
    Vector& operator=(const Vector& other);               // Оператор присваивания
    int& operator[](size_t index);                       // Оператор доступа по индексу
    Vector& operator<<(int element);                      // Оператор сдвига влево (добавление элемента в конец)
    Vector& operator>>(int element);                      // Оператор сдвига вправо (удаление последнего элемента)

    // Методы
    void insert(size_t index, int element);              // Вставка элемента по индексу
    void remove(size_t index);                            // Удаление элемента по индексу
    bool search(int element) const;                       // Поиск элемента
    bool isEmpty() const;                                 // Проверка, пуста ли коллекция
    std::string toString() const;                       // Преобразование в строку

    size_t getSize() const;                              // Возвращает размер вектора
};
