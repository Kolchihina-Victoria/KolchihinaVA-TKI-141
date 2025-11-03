#include <iostream>
#include <memory>
#include <limits>
#include "Matrix.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include "ConstantGenerator.h"
#include "ZeroGenerator.h"
#include "Task1Exercise.h"
#include "Task2Exercise.h"
#include "Task3Exercise.h"

void clear_input_buffer()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void demonstrate_task1()
{
    std::cout << "\n=== ВЫПОЛНЕНИЕ ЗАДАНИЯ 1 ===" << std::endl;
    std::cout << "Замена последнего отрицательного элемента на модуль первого элемента" << std::endl;
    
    // Создаем тестовый массив
    auto matrix = std::make_unique<miit::algebra::Matrix<int>>(8);
    miit::algebra::RandomGenerator random_gen(-10, 20);
    matrix->fill(random_gen);
    
    std::cout << "Исходный массив: " << matrix->to_string() << std::endl;
    
    // Выполняем задание 1
    miit::algebra::Task1Exercise task1(std::make_unique<miit::algebra::Matrix<int>>(*matrix), 
                                      std::make_unique<miit::algebra::RandomGenerator>(-10, 20));
    
    task1.task1();
    std::cout << "После задания 1: " << task1.get_matrix().to_string() << std::endl;
}

void demonstrate_task2()
{
    std::cout << "\n=== ВЫПОЛНЕНИЕ ЗАДАНИЯ 2 ===" << std::endl;
std::cout << "Удаление элементов, у которых первая и вторая цифры одинаковые" << std::endl;
    
    // Создаем тестовый массив с числами, у которых есть одинаковые цифры
    auto matrix = std::make_unique<miit::algebra::Matrix<int>>(8);
    (*matrix)[0] = 11;
    (*matrix)[1] = 23;
    (*matrix)[2] = 33;
    (*matrix)[3] = 47;
    (*matrix)[4] = 55;
    (*matrix)[5] = 69;
    (*matrix)[6] = 77;
    (*matrix)[7] = 88;
    
    std::cout << "Исходный массив: " << matrix->to_string() << std::endl;
    
    // Выполняем задание 2
    miit::algebra::Task2Exercise task2(std::move(matrix), 
                                      std::make_unique<miit::algebra::RandomGenerator>(-10, 20));
    
    task2.task2();
    std::cout << "После задания 2: " << task2.get_matrix().to_string() << std::endl;
    std::cout << "Удалены числа: 11, 33, 55, 77, 88 (имеют одинаковые цифры)" << std::endl;
}

void demonstrate_task3()
{
    std::cout << "\n=== ВЫПОЛНЕНИЕ ЗАДАНИЯ 3 ===" << std::endl;
    std::cout << "Создание массива M из массива P по правилу:" << std::endl;
    std::cout << "Если элемент четный: Mi = i * Pi" << std::endl;
    std::cout << "Если элемент нечетный: Mi = -Pi" << std::endl;
    
    // Создаем тестовый массив P
    auto matrix_P = std::make_unique<miit::algebra::Matrix<int>>(6);
    (*matrix_P)[0] = 2;
    (*matrix_P)[1] = 3;
    (*matrix_P)[2] = 4;
    (*matrix_P)[3] = 5;
    (*matrix_P)[4] = 6;
    (*matrix_P)[5] = 7;
    
    std::cout << "Массив P: " << matrix_P->to_string() << std::endl;
    
    // Выполняем задание 3
    miit::algebra::Task3Exercise task3(std::move(matrix_P), 
                                      std::make_unique<miit::algebra::RandomGenerator>(1, 10));
    
    auto matrix_M = task3.task3();
    std::cout << "Массив M: " << matrix_M.to_string() << std::endl;
    
    // Пояснение расчета
    std::cout << "Расчет:" << std::endl;
    std::cout << "M[0] = 0 * 2 = 0" << std::endl;
    std::cout << "M[1] = -3 = -3" << std::endl;
    std::cout << "M[2] = 2 * 4 = 8" << std::endl;
    std::cout << "M[3] = -5 = -5" << std::endl;
    std::cout << "M[4] = 4 * 6 = 24" << std::endl;
    std::cout << "M[5] = -7 = -7" << std::endl;
}

void demonstrate_generators()
{
    std::cout << "\n=== ДЕМОНСТРАЦИЯ ГЕНЕРАТОРОВ ===" << std::endl;
    
    // RandomGenerator
    std::cout << "RandomGenerator [-10, 20]:" << std::endl;
    miit::algebra::RandomGenerator random_gen(-10, 20);
    miit::algebra::Matrix<int> random_matrix(5);
    random_matrix.fill(random_gen);
    std::cout << "Случайные числа: " << random_matrix.to_string() << std::endl;
    
    // ConstantGenerator
    std::cout << "ConstantGenerator (42):" << std::endl;
    miit::algebra::ConstantGenerator const_gen(42);
    miit::algebra::Matrix<int> const_matrix(4);
    const_matrix.fill(const_gen);
    std::cout << "Константа 42: " << const_matrix.to_string() << std::endl;
    
    // ZeroGenerator
    std::cout << "ZeroGenerator:" << std::endl;
    miit::algebra::ZeroGenerator zero_gen;
    miit::algebra::Matrix<int> zero_matrix(3);
    zero_matrix.fill(zero_gen);
    std::cout << "Нули: " << zero_matrix.to_string() << std::endl;
}

void interactive_mode()
{
    std::cout << "\n=== ИНТЕРАКТИВНЫЙ РЕЖИМ ===" << std::endl;
    
    std::cout << "Выберите способ заполнения массива:" << std::endl;
    std::cout << "1 - Случайные числа [-10, 20]" << std::endl;
    std::cout << "2 - Ввод с клавиатуры" << std::endl;
    std::cout << "3 - Заполнение нулями" << std::endl;
    std::cout << "4 - Заполнение константой" << std::endl;
    
    int choice;
    std::cin >> choice;
    clear_input_buffer();
    
    std::unique_ptr<miit::algebra::Generator> generator;
    
    switch (choice)
    {
        case 1:
            generator = std::make_unique<miit::algebra::RandomGenerator>(-10, 20);
            std::cout << "Выбран генератор случайных чисел [-10, 20]" << std::endl;
            break;
        case 2:
            generator = std::make_unique<miit::algebra::IStreamGenerator>();
            std::cout << "Выбран ввод с клавиатуры" << std::endl;
break;
        case 3:
            generator = std::make_unique<miit::algebra::ZeroGenerator>();
            std::cout << "Выбран генератор нулей" << std::endl;
            break;
        case 4:
            std::cout << "Введите константу: ";
            int constant;
            std::cin >> constant;
            generator = std::make_unique<miit::algebra::ConstantGenerator>(constant);
            std::cout << "Выбран генератор константы " << constant << std::endl;
            break;
        default:
            std::cout << "Неверный выбор, используется генератор случайных чисел" << std::endl;
            generator = std::make_unique<miit::algebra::RandomGenerator>(-10, 20);
            break;
    }
    
    std::cout << "Введите размер массива: ";
    size_t size;
    std::cin >> size;
    clear_input_buffer();
    
    auto matrix = std::make_unique<miit::algebra::Matrix<int>>(size);
    
    if (choice == 2) // Ввод с клавиатуры
    {
        std::cout << "Введите " << size << " целых чисел:" << std::endl;
        for (size_t i = 0; i < size; ++i)
        {
            std::cout << "Элемент " << i << ": ";
            (*matrix)[i] = generator->generate();
        }
    }
    else
    {
        matrix->fill(*generator);
    }
    
    std::cout << "Ваш массив: " << matrix->to_string() << std::endl;
    
    // Выполняем все задания
    auto matrix_copy1 = std::make_unique<miit::algebra::Matrix<int>>(*matrix);
    miit::algebra::Task1Exercise task1(std::move(matrix_copy1), std::move(generator));
    task1.task1();
    std::cout
