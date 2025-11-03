#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    class Task3Exercise : public Exercise
    {
    public:
        using Exercise::Exercise;
        void task1() override { /* Not implemented for this task */ }
        void task2() override { /* Not implemented for this task */ }
        Matrix<int> task3() const override;
    };
}
