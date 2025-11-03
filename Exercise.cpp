#include "Exercise.h"

namespace miit::algebra
{
    Exercise::Exercise(std::unique_ptr<Matrix<int>> matrix, std::unique_ptr<Generator> generator)
        : matrix(std::move(matrix)), generator(std::move(generator)) {}

    Matrix<int>& Exercise::get_matrix()
    {
        return *matrix;
    }

    const Matrix<int>& Exercise::get_matrix() const
    {
        return *matrix;
    }
}
