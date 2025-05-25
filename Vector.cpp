#include "Vector.h"
#include <iostream> // для отладки (убрать)
#include <algorithm>

// Конструктор по умолчанию
Vector::Vector() : data(nullptr), size(0), capacity(0) {}

// Конструктор с заданной начальной емкостью
Vector::Vector(size_t initialCapacity) : data(new int[initialCapacity]), size(0), capacity(initialCapacity) {}

// Конструктор со списком инициализации
Vector::Vector(const std::initializer_list<int>& list) : size(list.size()), capacity(list.size()) {
    data = new int[capacity];
    std::copy(list.begin(), list.end(), data);
}

// Конструктор копирования
Vector::Vector(const Vector& other) : size(other.size), capacity(other.capacity) {
    data = new int[capacity];
    std::copy(other.data, other.data + size, data);
}

// Деструктор
Vector::~Vector() {
    delete[] data;
}

// Оператор присваивания
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new int[capacity];
        std::copy(other.data, other.data + size, data);
    }
    return *this;
}

// Оператор доступа по индексу
int& Vector::operator[](size_t index) {
    return data[index];
}

// Оператор сдвига влево (добавление элемента в конец)
Vector& Vector::operator<<(int element) {
    if (size == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }
    data[size++] = element;
    return *this;
}

// Оператор сдвига вправо (удаление последнего элемента)
Vector& Vector::operator>>(int element) {
    if (!isEmpty()) {
        size--; // Просто уменьшаем размер
    }
    return *this;
}

// Вставка элемента по индексу
void Vector::insert(size_t index, int element) {
    if (index > size) return; // Или выбросить исключение

    if (size == capacity) {
        resize(capacity == 0 ? 1 : capacity * 2);
    }

    for (size_t i = size; i > index; --i) {
        data[i] = data[i - 1];
    }
    data[index] = element;
    ++size;
}

// Удаление элемента по индексу
void Vector::remove(size_t index) {
    if (index >= size) return; // Или выбросить исключение

    for (size_t i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}

// Поиск элемента
bool Vector::search(int element) const {
    for (size_t i = 0; i < size; ++i) {
        if (data[i] == element) {
            return true;
        }
    }
    return false;
}

// Проверка, пуста ли коллекция
bool Vector::isEmpty() const {
    return size == 0;
}

// Преобразование в строку
std::string Vector::toString() const {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < size; ++i) {
        oss << data[i];
        if (i < size - 1) {
            oss << ", ";
        }
    }
    oss << "]";
    return oss.str();
}

size_t Vector::getSize() const {
    return size;
}
// Вспомогательная функция для изменения размера массива
void Vector::resize(size_t newCapacity) {
    if (newCapacity < size) return;

    int* newData = new int[newCapacity];
    std::copy(data, data + size, newData);
    delete[] data;
    data = newData;
    capacity = newCapacity;
}
