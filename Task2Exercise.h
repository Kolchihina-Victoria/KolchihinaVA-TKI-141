
#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    class Task2Exercise : public Exercise
    {
    public:
        using Exercise::Exercise;
        void task() override;  // Замена task2()

    private:
        bool has_same_first_two_digits(int number) const;
    };
}
