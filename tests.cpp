#include <gtest/gtest.h>
#include <memory>
#include <sstream>

#include "Matrix.h"
#include "ConstantGenerator.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "ZeroGenerator.h"
#include "Task1Exercise.h"
#include "Task2Exercise.h"
#include "Task3Exercise.h"

using namespace miit::algebra;

// Тесты для ConstantGenerator
TEST(ConstantGeneratorTest, GenerateReturnsConstantValue) {
    ConstantGenerator generator(42);
    EXPECT_EQ(generator.generate(), 42);
    EXPECT_EQ(generator.generate(), 42); // Всегда одно значение
}

// Тесты для ZeroGenerator
TEST(ZeroGeneratorTest, GenerateReturnsZero) {
    ZeroGenerator generator;
    EXPECT_EQ(generator.generate(), 0);
}

// Тесты для IStreamGenerator
TEST(IStreamGeneratorTest, GenerateReadsFromStream) {
    std::stringstream stream;
    stream << "123 456";
    
    IStreamGenerator generator(stream);
    EXPECT_EQ(generator.generate(), 123);
    EXPECT_EQ(generator.generate(), 456);
}

// Тесты для Matrix
TEST(MatrixTest, ConstructorAndAccess) {
    Matrix<int> matrix(3);
    EXPECT_EQ(matrix.get_size(), 3);
    
    matrix[0] = 1;
    matrix[1] = 2;
    matrix[2] = 3;
    
    EXPECT_EQ(matrix[0], 1);
    EXPECT_EQ(matrix[1], 2);
    EXPECT_EQ(matrix[2], 3);
}

TEST(MatrixTest, OutOfRangeAccessThrows) {
    Matrix<int> matrix(2);
    EXPECT_THROW(matrix[2], std::out_of_range);
    EXPECT_THROW(matrix[100], std::out_of_range);
}

TEST(MatrixTest, ShiftLeftOperation) {
    Matrix<int> matrix(4);
    for (size_t i = 0; i < 4; ++i) {
        matrix[i] = static_cast<int>(i + 1);
    }
    
    matrix <<= 1;
    EXPECT_EQ(matrix[0], 2);
    EXPECT_EQ(matrix[1], 3);
    EXPECT_EQ(matrix[2], 4);
    EXPECT_EQ(matrix[3], 1);
}

TEST(MatrixTest, ShiftRightOperation) {
    Matrix<int> matrix(4);
    for (size_t i = 0; i < 4; ++i) {
        matrix[i] = static_cast<int>(i + 1);
    }
    
    matrix >>= 1;
    EXPECT_EQ(matrix[0], 4);
    EXPECT_EQ(matrix[1], 1);
    EXPECT_EQ(matrix[2], 2);
    EXPECT_EQ(matrix[3], 3);
}

TEST(MatrixTest, FillWithGenerator) {
    Matrix<int> matrix(3);
    ConstantGenerator generator(5);
    
    matrix.fill(generator);
    
    EXPECT_EQ(matrix[0], 5);
    EXPECT_EQ(matrix[1], 5);
    EXPECT_EQ(matrix[2], 5);
}

// Тесты для Task1Exercise
TEST(Task1ExerciseTest, ReplaceLastNegativeElement) {
    auto matrix = std::make_unique<Matrix<int>>(4);
    (*matrix)[0] = 1;
    (*matrix)[1] = -2;
    (*matrix)[2] = 3;
    (*matrix)[3] = -4;
    
    auto generator = std::make_unique<ConstantGenerator>(0);
    Task1Exercise exercise(std::move(matrix), std::move(generator));
    
    exercise.task1();
    
    const auto& result = exercise.get_matrix();
    EXPECT_EQ(result[0], 1);
    EXPECT_EQ(result[1], -2);
    EXPECT_EQ(result[2], 3);
    EXPECT_EQ(result[3], 1); // Заменен на модуль первого элемента
}

TEST(Task1ExerciseTest, NoNegativeElementsNoChange) {
    auto matrix = std::make_unique<Matrix<int>>(3);
    (*matrix)[0] = 1;
    (*matrix)[1] = 2;
    (*matrix)[2] = 3;
    
    auto generator = std::make_unique<ConstantGenerator>(0);
    Task1Exercise exercise(std::move(matrix), std::move(generator));
    
    const auto original = exercise.get_matrix().to_string();
    exercise.task1();
    const auto after = exercise.get_matrix().to_string();
    
    EXPECT_EQ(original, after); // Матрица не изменилась
}

// Тесты для Task2Exercise
TEST(Task2ExerciseTest, RemoveElementsWithSameFirstTwoDigits) {
    auto matrix = std::make_unique<Matrix<int>>(5);
    (*matrix)[0] = 11;   // одинаковые
    (*matrix)[1] = 123;  // разные
    (*matrix)[2] = 22;   // одинаковые
    (*matrix)[3] = 456;  // разные
    (*matrix)[4] = 33;   // одинаковые
    
    auto generator = std::make_unique<ZeroGenerator>();
    Task2Exercise exercise(std::move(matrix), std::move(generator));
    
    exercise.task2();
    
    const auto& result = exercise.get_matrix();
    EXPECT_EQ(result.get_size(), 2); // Осталось 2 элемента
    EXPECT_EQ(result[0], 123);
    EXPECT_EQ(result[1], 456);
}

TEST(Task2ExerciseTest, HasSameFirstTwoDigits) {
    Task2Exercise exercise(std::make_unique<Matrix<int>>(1), std::make_unique<ZeroGenerator>());
    
    // Тестируем приватный метод через публичный интерфейс
    auto matrix = std::make_unique<Matrix<int>>(6);
    (*matrix)[0] = 11;    // true
    (*matrix)[1] = 123;   // false
    (*matrix)[2] = -22;   // true (отрицательное)
    (*matrix)[3] = 1;     // false (однозначное)
    (*matrix)[4] = 99;    // true
    (*matrix)[5] = 100;   // false
    
    Task2Exercise test_exercise(std::move(matrix), std::make_unique<ZeroGenerator>());
    test_exercise.task2();
    
    const auto& result = test_exercise.get_matrix();
    // Должны остаться только элементы с разными первыми цифрами
    EXPECT_EQ(result.get_size(), 3);
}

// Тесты для Task3Exercise
TEST(Task3ExerciseTest, CreateMFromP) {
    auto matrix = std::make_unique<Matrix<int>>(4);
    (*matrix)[0] = 2;  // четное: M0 = 0 * 2 = 0
    (*matrix)[1] = 3;  // нечетное: M1 = -3
    (*matrix)[2] = 4;  // четное: M2 = 2 * 4 = 8
    (*matrix)[3] = 5;  // нечетное: M3 = -5
    
    auto generator = std::make_unique<ConstantGenerator>(0);
    Task3Exercise exercise(std::move(matrix), std::move(generator));
    
    Matrix<int> M = exercise.task3();
    
    EXPECT_EQ(M.get_size(), 4);
    EXPECT_EQ(M[0], 0);   // 0 * 2
    EXPECT_EQ(M[1], -3);  // -3
    EXPECT_EQ(M[2], 8);   // 2 * 4
    EXPECT_EQ(M[3], -5);  // -5
}

TEST(Task3ExerciseTest, EmptyMatrix) {
    auto matrix = std::make_unique<Matrix<int>>(0);
    auto generator = std::make_unique<ConstantGenerator>(0);
    Task3Exercise exercise(std::move(matrix), std::move(generator));
    
    Matrix<int> M = exercise.task3();
    
    EXPECT_EQ(M.get_size(), 0);
}

// Тест на граничные случаи
TEST(EdgeCasesTest, SingleElementMatrix) {
    // Task1 с одним элементом
    auto matrix1 = std::make_unique<Matrix<int>>(1);
    (*matrix1)[0] = -5;
    Task1Exercise ex1(std::move(matrix1), std::make_unique<ZeroGenerator>());
    ex1.task1();
    EXPECT_EQ(ex1.get_matrix()[0], 5); // Заменен на модуль первого элемента
    
    // Task2 с одним элементом
    auto matrix2 = std::make_unique<Matrix<int>>(1);
    (*matrix2)[0] = 11;
    Task2Exercise ex2(std::move(matrix2), std::make_unique<ZeroGenerator>());
    ex2.task2();
    EXPECT_EQ(ex2.get_matrix().get_size(), 0); // Удален
    
    // Task3 с одним элементом
    auto matrix3 = std::make_unique<Matrix<int>>(1);
    (*matrix3)[0] = 4;
    Task3Exercise ex3(std::move(matrix3), std::make_unique<ZeroGenerator>());
    Matrix<int> M = ex3.task3();
    EXPECT_EQ(M[0], 0); // 0 * 4
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
