#include "Task3Exercise.h"

namespace miit::algebra
{
   void Task3Exercise::task()  //БЫЛО: Matrix<int> task() — ИЗМЕНЕНО НА void
    {
        auto& P = *matrix;
         result = Matrix<int>(P.get_size());  // результат сохраняется в член класса
        
        for (size_t i = 0; i < P.get_size(); ++i)
        {
            if (P[i] % 2 == 0)
            {
                // Если элемент четный: Mi = i * Pi
                result[i] = static_cast<int>(i) * P[i]; // исправлено: result вместо M
            }
else
            {
                // Если элемент нечетный: Mi = -Pi
                result[i] = -P[i];// исправлено: result вместо M
            }
        }
        
     //нет возрата значения
    }
}
