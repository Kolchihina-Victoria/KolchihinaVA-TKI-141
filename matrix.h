#pragma once
#include <memory>
#include <string>
#include <sstream>
#include <stdexcept>

namespace miit::algebra
{
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
        Matrix(size_t size, const T& value);
        Matrix(const Matrix& other);
        Matrix(Matrix&& other) noexcept;
        
        // Деструктор
        ~Matrix() = default;

        // Операторы присваивания
        Matrix& operator=(const Matrix& other);
        Matrix& operator=(Matrix&& other) noexcept;

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
        
        // Удаление элементов (для задания 2)
        void remove_elements(const std::unique_ptr<bool[]>& mask);
    };
}
