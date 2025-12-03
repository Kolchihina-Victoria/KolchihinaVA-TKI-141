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
        // Конструкторы
        Matrix();
        explicit Matrix(size_t size);
        // Убран: Matrix(size_t size, const T& value);
        // Убран: Matrix(const Matrix& other);
        // Убран: Matrix(Matrix&& other) noexcept;

        // Деструктор
        ~Matrix() = default;

        // Операторы присваивания
        // Убраны: операторы присваивания

        // Операторы сдвига
        Matrix operator<<(int shift) const;
        Matrix operator>>(int shift) const;
        Matrix& operator<<=(int shift);
        Matrix& operator>>=(int shift);

        // Оператор разыменования
        T& operator[](size_t index);
        const T& operator[](size_t index) const;

        // Методы доступа
        size_t get_size() const;
        std::string to_string() const;

        // Методы заполнения
        void fill(Generator& generator);
    };
}
