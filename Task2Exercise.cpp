#include "Task2Exercise.h"
#include <cmath>
#include <memory>

namespace miit::algebra
{
    void Task2Exercise::task2()
    {
        auto& mat = *matrix;
        auto mask = std::make_unique<bool[]>(mat.get_size());
        
        // Помечаем элементы для удаления
        for (size_t i = 0; i < mat.get_size(); ++i)
        {
            mask[i] = has_same_first_two_digits(mat[i]);
        }
        
        // Удаляем помеченные элементы
        mat.remove_elements(mask);
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
}
