#pragma once
#include <memory>
#include <string>
#include <sstream>
#include <stdexcept>

namespace miit::algebra
{
    class Generator;  // Forward declaration

    template<typename T>
    class Matrix
    {
    private:
        std::unique_ptr<T[]> data;
        size_t size;

    public:
        // Конструкторы (правило пяти)
        Matrix();
        explicit Matrix(const size_t size);
        Matrix(const size_t size, const T& value);
        
        // Копирующий конструктор
        Matrix(const Matrix& other);
        
        // Перемещающий конструктор
        Matrix(Matrix&& other) noexcept;
        
        // Копирующий оператор присваивания
        Matrix& operator=(const Matrix& other);
        
        // Перемещающий оператор присваивания
        Matrix& operator=(Matrix&& other) noexcept;
        
        // Деструктор
        ~Matrix() = default;

        // Операторы сдвига
        Matrix operator<<(int shift) const;
        Matrix operator>>(int shift) const;
        Matrix& operator<<=(int shift);
        Matrix& operator>>=(int shift);

        // Оператор доступа к элементам
        T& operator[](const size_t index);
        const T& operator[](const size_t index) const;

        // Методы доступа
        size_t get_size() const;
        std::string to_string() const;

        // Методы заполнения
        void fill(Generator& generator);
    };
}
