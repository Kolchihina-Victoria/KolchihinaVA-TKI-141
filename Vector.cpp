#include "IntVector.h"
#include <sstream>
#include <stdexcept>
#include <algorithm>

IntVector::IntVector() : data(nullptr), count(0), capacity(0) {}

IntVector::IntVector(std::initializer_list<int> list)
    : count(list.size()), capacity(list.size()) {
    data = new int[capacity];
    std::copy(list.begin(), list.end(), data);
}

IntVector::IntVector(const IntVector& other)
    : count(other.count), capacity(other.capacity) {
    data = new int[capacity];
    std::copy(other.data, other.data + count, data);
}

IntVector::IntVector(IntVector&& other) noexcept
    : data(other.data), count(other.count), capacity(other.capacity) {
    other.data = nullptr;
    other.count = 0;
    other.capacity = 0;
}

IntVector::~IntVector() {
    delete[] data;
}

IntVector& IntVector::operator=(const IntVector& other) {
    if (this != &other) {
        delete[] data;
        count = other.count;
        capacity = other.capacity;
        data = new int[capacity];
        std::copy(other.data, other.data + count, data);
    }
    return *this;
}

IntVector& IntVector::operator=(IntVector&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        count = other.count;
        capacity = other.capacity;
        other.data = nullptr;
        other.count = 0;
        other.capacity = 0;
    }
    return *this;
}

void IntVector::resize(size_t new_capacity) {
    int* new_data = new int[new_capacity];
    std::copy(data, data + count, new_data);
    delete[] data;
    data = new_data;
    capacity = new_capacity;
}

IntVector& IntVector::operator<<(int value) {
    if (count >= capacity) resize(capacity == 0 ? 1 : capacity * 2);
    data[count++] = value;
    return *this;
}

IntVector& IntVector::operator>>(int& value) {
    if (count == 0) throw std::out_of_range("Vector is empty");
    value = data[--count];
    return *this;
}

bool IntVector::empty() const {
    return count == 0;
}

size_t IntVector::size() const {
    return count;
}

std::string IntVector::to_string() const {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < count; ++i) {
        if (i > 0) oss << ", ";
        oss << data[i];
    }
    oss << "]";
    return oss.str();
}

int IntVector::find(int value) const {
    for (size_t i = 0; i < count; ++i) {
        if (data[i] == value) return static_cast<int>(i);
    }
    return -1;
}

int& IntVector::operator[](size_t index) {
    if (index >= count) throw std::out_of_range("Index out of range");
    return data[index];
}

const int& IntVector::operator[](size_t index) const {
    if (index >= count) throw std::out_of_range("Index out of range");
    return data[index];
}
