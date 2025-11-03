#include "Task3Exercise.h"

namespace miit::algebra
{
    Matrix<int> Task3Exercise::task3() const
    {
        const auto& P = *matrix;
        Matrix<int> M(P.get_size());
        
        for (size_t i = 0; i < P.get_size(); ++i)
        {
            if (P[i] % 2 == 0)
            {
                // Если элемент четный: Mi = i * Pi
                M[i] = static_cast<int>(i) * P[i];
            }
else
            {
                // Если элемент нечетный: Mi = -Pi
                M[i] = -P[i];
            }
        }
        
        return M;
    }
}
