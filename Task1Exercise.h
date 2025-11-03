#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    class Task1Exercise : public Exercise
    {
    public:
        using Exercise::Exercise;
        void task1() override;
        void task2() override { /* Not implemented for this task */ }
        Matrix<int> task3() const override { return Matrix<int>(0); /* Not implemented */ }
        
    private:
        int find_last_negative_index() const;
    };
}
