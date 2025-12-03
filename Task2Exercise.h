#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    class Task2Exercise : public Exercise
    {
    public:
        using Exercise::Exercise;
        void task() override;

    private:
        bool has_same_first_two_digits(int number) const;
        void remove_elements(const std::unique_ptr<bool[]>& mask); // Добавлен метод
    };
}
