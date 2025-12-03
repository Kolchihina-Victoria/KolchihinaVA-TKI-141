#include "Task1Exercise.h"
#include <cmath>

namespace miit::algebra
{
    void Task1Exercise::task()   //было task1
{
        int last_negative_index = find_last_negative_index();
        if (last_negative_index != -1)
        {
            int first_element_abs = std::abs((*matrix)[0]);
            (*matrix)[last_negative_index] = first_element_abs;
        }
    }

    int Task1Exercise::find_last_negative_index() const
    {
        const auto& mat = *matrix;
        for (int i = static_cast<int>(mat.get_size()) - 1; i >= 0; --i)
        {
            if (mat[i] < 0)
            {
                return i;
            }
        }
        return -1;
    }
}
