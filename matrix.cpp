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
    Matrix<T>::Matrix(size_t size, const T& value) : size(size), data(std::make_unique<T[]>(size))
    {
for (size_t i = 0; i < size; ++i)
        {
            data[i] = value;
        }
    }

    template<typename T>
    Matrix<T>::Matrix(const Matrix& other) : size(other.size), data(std::make_unique<T[]>(other.size))
    {
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    }

    template<typename T>
    Matrix<T>::Matrix(Matrix&& other) noexcept : size(other.size), data(std::move(other.data))
    {
        other.size = 0;
    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator=(const Matrix& other)
    {
        if (this != &other)
        {
            size = other.size;
            data = std::make_unique<T[]>(size);
            for (size_t i = 0; i < size; ++i)
            {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator=(Matrix&& other) noexcept
    {
        if (this != &other)
        {
            size = other.size;
            data = std::move(other.data);
            other.size = 0;
        }
        return *this;
    }

    template<typename T>
    Matrix<T> Matrix<T>::operator<<(int shift) const
    {
        Matrix result(*this);
        result <<= shift;
        return result;
    }

    template<typename T>
    Matrix<T> Matrix<T>::operator>>(int shift) const
    {
        Matrix result(*this);
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

    template<typename T>
    void Matrix<T>::remove_elements(const std::unique_ptr<bool[]>& mask)
    {
        size_t new_size = 0;
        for (size_t i = 0; i < size; ++i)
        {
            if (!mask[i])
            {
                new_size++;
            }
        }

        auto new_data = std::make_unique<T[]>(new_size);
        size_t new_index = 0;
        for (size_t i = 0; i < size; ++i)
        {
            if (!mask[i])
            {
                new_data[new_index++] = data[i];
            }
        }

        data = std::move(new_data);
        size = new_size;
    }

    // Явная инстанциация для int
    template class Matrix<int>;
}
