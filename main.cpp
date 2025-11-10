#include <iostream>
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

void demonstrate_task1() {
    std::cout << " задание 1 " << std::endl;
    
    // Создаем матрицу с отрицательными элементами
    auto matrix = std::make_unique<Matrix<int>>(5);
    matrix->operator[](0) = 1;
    matrix->operator[](1) = -2;
    matrix->operator[](2) = 3;
    matrix->operator[](3) = -4;
    matrix->operator[](4) = 5;
    
    auto generator = std::make_unique<ConstantGenerator>(10);
    Task1Exercise exercise(std::move(matrix), std::move(generator));
    
    std::cout << "Исходная матрица: " << exercise.get_matrix().to_string() << std::endl;
    
    exercise.task1(); // Заменяем последний отрицательный элемент
    
    std::cout << "После замены последнего отрицательного: " << exercise.get_matrix().to_string() << std::endl;
    std::cout << std::endl;
}

void demonstrate_task2() {
    std::cout << "задание 2 " << std::endl;
    
    // Создаем матрицу с элементами, у которых есть одинаковые первые цифры
    auto matrix = std::make_unique<Matrix<int>>(6);
    matrix->operator[](0) = 11;    // одинаковые цифры
    matrix->operator[](1) = 22;    // одинаковые цифры
    matrix->operator[](2) = 123;   // разные цифры
    matrix->operator[](3) = 33;    // одинаковые цифры
    matrix->operator[](4) = 456;   // разные цифры
    matrix->operator[](5) = -77;   // одинаковые цифры (отрицательное)
    
    auto generator = std::make_unique<ZeroGenerator>();
    Task2Exercise exercise(std::move(matrix), std::move(generator));
    
    std::cout << "Исходная матрица: " << exercise.get_matrix().to_string() << std::endl;
    
    exercise.task2(); // Удаляем элементы с одинаковыми первыми двумя цифрами
    
    std::cout << "После удаления элементов с одинаковыми первыми цифрами: " << exercise.get_matrix().to_string() << std::endl;
    std::cout << std::endl;
}

void demonstrate_task3() {
    std::cout << "задание 3" << std::endl;
    
    // Создаем матрицу P
    auto matrix = std::make_unique<Matrix<int>>(5);
    matrix->operator[](0) = 2;  // четное
    matrix->operator[](1) = 3;  // нечетное
    matrix->operator[](2) = 4;  // четное
    matrix->operator[](3) = 5;  // нечетное
    matrix->operator[](4) = 6;  // четное
    
    auto generator = std::make_unique<RandomGenerator>(1, 10);
    Task3Exercise exercise(std::move(matrix), std::move(generator));
    
    std::cout << "Матрица P: " << exercise.get_matrix().to_string() << std::endl;
    
    Matrix<int> M = exercise.task3(); // Создаем массив M
    
    std::cout << "Матрица M (результат): " << M.to_string() << std::endl;
    std::cout << std::endl;
}

void demonstrate_generators() {
    std::cout << "генераторы" << std::endl;
    
    // ConstantGenerator
    ConstantGenerator constGen(42);
    std::cout << "ConstantGenerator: " << constGen.generate() << std::endl;
    
    // RandomGenerator
    RandomGenerator randGen(1, 100);
    std::cout << "RandomGenerator: " << randGen.generate() << std::endl;
    
    // ZeroGenerator
    ZeroGenerator zeroGen;
    std::cout << "ZeroGenerator: " << zeroGen.generate() << std::endl;
    
    // IStreamGenerator
    std::stringstream test_stream;
    test_stream << "999";
    IStreamGenerator streamGen(test_stream);
    std::cout << "IStreamGenerator: " << streamGen.generate() << std::endl;
    
    std::cout << std::endl;
}

void demonstrate_matrix_operations() {
    std::cout << "операции с матрицей" << std::endl;
    
    Matrix<int> matrix(5);
    for (size_t i = 0; i < matrix.get_size(); ++i) {
        matrix[i] = static_cast<int>(i + 1);
    }
    
    std::cout << "Исходная матрица: " << matrix.to_string() << std::endl;
    
    // Сдвиг влево
    matrix <<= 2;
    std::cout << "После сдвига <<= 2: " << matrix.to_string() << std::endl;
    
    // Сдвиг вправо
    matrix >>= 1;
    std::cout << "После сдвига >>= 1: " << matrix.to_string() << std::endl;
    
    // Заполнение генератором
    ConstantGenerator gen(7);
    matrix.fill(gen);
    std::cout << "После заполнения ConstantGenerator(7): " << matrix.to_string() << std::endl;
    
    std::cout << std::endl;
}

int main() {
    try {
        std::cout << "Программа для демонстрации работы с матрицами и генераторами" << std::endl;
        std::cout << "=============================================================" << std::endl << std::endl;
        
        demonstrate_generators();
        demonstrate_matrix_operations();
        demonstrate_task1();
        demonstrate_task2();
        demonstrate_task3();
        
        std::cout << "Все завершено успешно!" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
