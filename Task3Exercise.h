#pragma once
#include "Exercise.h"

namespace miit::algebra
{
    class Task3Exercise : public Exercise
    {
    private:
        Matrix<int> result;  //  ДОБАВЛЕНО: хранение результата
    public:
        using Exercise::Exercise;
        void task() override;  // Замена task3()
        const Matrix<int>& get_result() const { return result; }  //  ДОБАВЛЕНО
    };
}
