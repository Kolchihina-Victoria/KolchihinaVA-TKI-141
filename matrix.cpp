#include "Matrix.h"
#include "Generator.h"
#include <algorithm>
#include <stdexcept>

namespace miit::algebra
{
    template<typename T>
    Matrix<T>::Matrix() : size(0), data(nullptr) {}

    template<typename T>
    Matrix<T>::Matrix(size_t size) : size(size), data(std::make_unique<T[]>(size)) {}

    template<typename T>
    Matrix<T> Matrix<T>::operator<<(int shift) const
    {
        Matrix result(size);
        for (size_t i = 0; i < size; ++i)
        {
            result.data[i] = data[i];
        }
        result <<= shift;
        return result;
    }

    template<typename T>
    Matrix<T> Matrix<T>::operator>>(int shift) const
    {
        Matrix result(size);
        for (size_t i = 0; i < size; ++i)
        {
            result.data[i] = data[i];
        }
        result >>= shift;
        return result;
    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator<<=(int shift)
    {
        if (size == 0) return *this;

        shift = shift % static_cast<int>(size);
        if (shift < 0) shift += size;

        auto temp = std::make_unique<T[]>(size);
        for (size_t i = 0; i < size; ++i)
        {
            temp[(i + shift) % size] = data[i];
        }
        data = std::move(temp);
        return *this;
    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator>>=(int shift)
    {
        return *this <<= -shift;
    }

    template<typename T>
    T& Matrix<T>::operator[](size_t index)
    {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    template<typename T>
    const T& Matrix<T>::operator[](size_t index) const
    {
        if (index >= size) throw std::out_of_range("Index out of range");
        return data[index];
    }

    template<typename T>
    size_t Matrix<T>::get_size() const
    {
        return size;
    }

    template<typename T>
    std::string Matrix<T>::to_string() const
    {
        std::ostringstream oss;
        oss << "[";
        for (size_t i = 0; i < size; ++i)
        {
            oss << data[i];
            if (i < size - 1) oss << ", ";
        }
        oss << "]";
        return oss.str();
    }

    template<typename T>
    void Matrix<T>::fill(Generator& generator)
    {
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = static_cast<T>(generator.generate());
        }
    }

    // Явная  для int
    template class Matrix<int>;
}
