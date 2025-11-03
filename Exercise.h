#pragma once
#include "Matrix.h"
#include "Generator.h"
#include <memory>

namespace miit::algebra
{
    class Exercise
    {
    protected:
        std::unique_ptr<Matrix<int>> matrix;
        std::unique_ptr<Generator> generator;

    public:
        Exercise(std::unique_ptr<Matrix<int>> matrix, std::unique_ptr<Generator> generator);
        virtual ~Exercise() = default;
virtual void task1() = 0;  // Замена последнего отрицательного
        virtual void task2() = 0;  // Удаление элементов с одинаковыми цифрами
        virtual Matrix<int> task3() const = 0;  // Создание массива M из P
        
        Matrix<int>& get_matrix();
        const Matrix<int>& get_matrix() const;
    };
}
