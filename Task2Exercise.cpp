#include "Task2Exercise.h"
#include <cmath>
#include <memory>

namespace miit::algebra
{
    void Task2Exercise::task()
    {
        auto& mat = *matrix;
        auto mask = std::make_unique<bool[]>(mat.get_size());

        // Помечаем элементы для удаления
        for (size_t i = 0; i < mat.get_size(); ++i)
        {
            mask[i] = has_same_first_two_digits(mat[i]);
        }

        // Удаляем помеченные элементы
        remove_elements(mask);
    }

    bool Task2Exercise::has_same_first_two_digits(int number) const
    {
        number = std::abs(number);
        if (number < 10) return false; // Однозначное число

        // Получаем первую цифру
        int first_digit = number;
        while (first_digit >= 10)
        {
            first_digit /= 10;
        }

        // Получаем вторую цифру
        int second_digit = (number / 10) % 10;

        return first_digit == second_digit;
    }

    void Task2Exercise::remove_elements(const std::unique_ptr<bool[]>& mask)
    {
        auto& mat = *matrix;
        size_t new_size = 0;
        
        // Считаем количество элементов, которые останутся
        for (size_t i = 0; i < mat.get_size(); ++i)
        {
            if (!mask[i])
            {
                new_size++;
            }
        }

        // Создаем новый массив
        auto new_data = std::make_unique<int[]>(new_size);
        size_t new_index = 0;
        
        // Копируем элементы, которые не помечены для удаления
        for (size_t i = 0; i < mat.get_size(); ++i)
        {
            if (!mask[i])
            {
                new_data[new_index++] = mat[i];
            }
        }

        // Заменяем данные в матрице
        auto old_size = mat.get_size();
        mat = std::move(std::make_unique<Matrix<int>>(new_size));
        for (size_t i = 0; i < new_size; ++i)
        {
            (*matrix)[i] = new_data[i];
        }
    }
}
