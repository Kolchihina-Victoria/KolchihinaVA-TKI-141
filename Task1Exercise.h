
#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    class Task1Exercise : public Exercise
    {
    public:
        using Exercise::Exercise;
        void task() override;  // Замена task1(), task2(), task3()

    private:
        int find_last_negative_index() const;
    };
}
