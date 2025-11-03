#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    class Task2Exercise : public Exercise
    {
    public:
        using Exercise::Exercise;
        void task1() override { /* Not implemented for this task */ }
        void task2() override;
        Matrix<int> task3() const override { return Matrix<int>(0); /* Not implemented */ }
        
    private:
        bool has_same_first_two_digits(int number) const;
    };
}
