// Exercise.h
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
        
       //замена 3 методов на 1
        virtual void task() = 0;
        
        Matrix<int>& get_matrix();
        const Matrix<int>& get_matrix() const;
    };
}
