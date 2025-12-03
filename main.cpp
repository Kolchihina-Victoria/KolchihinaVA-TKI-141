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

std::unique_ptr<Generator> choose_fill_method()
{
    std::cout << "\nВыберите способ заполнения матрицы:\n";
    std::cout << "1. С клавиатуры\n";
    std::cout << "2. Рандомно\n";
    std::cout << "3. Константой\n";
    std::cout << "4. Нулями\n";
    std::cout << "Ваш выбор: ";

    int choice;
    std::cin >> choice;

    switch (choice)
    {
        case 1:
            return std::make_unique<IStreamGenerator>(std::cin);
        case 2:
        {
            int min, max;
            std::cout << "Введите минимальное значение: ";
            std::cin >> min;
            std::cout << "Введите максимальное значение: ";
            std::cin >> max;
            return std::make_unique<RandomGenerator>(min, max);
        }
        case 3:
        {
            int value;
            std::cout << "Введите константное значение: ";
            std::cin >> value;
            return std::make_unique<ConstantGenerator>(value);
        }
        case 4:
            return std::make_unique<ZeroGenerator>();
        default:
            std::cout << "Неверный выбор. Используется заполнение с клавиатуры.\n";
            return std::make_unique<IStreamGenerator>(std::cin);
    }
}

void fill_matrix_interactively(Matrix<int>& matrix)
{
    std::cout << "\nЗаполнение матрицы:\n";
    for (size_t i = 0; i < matrix.get_size(); ++i)
    {
        std::cout << "Элемент [" << i << "]: ";
        std::cin >> matrix[i];
    }
}

void demonstrate_task1() {
    std::cout << "\n=== Задание 1 ===" << std::endl;
    std::cout << "Замена последнего отрицательного элемента матрицы на модуль первого элемента" << std::endl;

    // Создаем матрицу
    std::cout << "\nВведите размер матрицы: ";
    size_t size;
    std::cin >> size;
    
    auto matrix = std::make_unique<Matrix<int>>(size);
    
    // Выбор способа заполнения
    std::cout << "\nВыбор способа заполнения матрицы:" << std::endl;
    auto generator = choose_fill_method();
    
    if (dynamic_cast<IStreamGenerator*>(generator.get()))
    {
        // Если выбран ввод с клавиатуры, заполняем интерактивно
        fill_matrix_interactively(*matrix);
    }
    else
    {
        // Иначе используем генератор
        matrix->fill(*generator);
    }

    Task1Exercise exercise(std::move(matrix), std::move(generator));

    std::cout << "\nИсходная матрица: " << exercise.get_matrix().to_string() << std::endl;

    exercise.task(); // Выполняем задание

    std::cout << "Результат: " << exercise.get_matrix().to_string() << std::endl;
}

void demonstrate_task2() {
    std::cout << "\n=== Задание 2 ===" << std::endl;
    std::cout << "Удаление элементов, у которых первые две цифры одинаковые" << std::endl;

    // Создаем матрицу
    std::cout << "\nВведите размер матрицы: ";
    size_t size;
    std::cin >> size;
    
    auto matrix = std::make_unique<Matrix<int>>(size);
    
    // Выбор способа заполнения
    std::cout << "\nВыбор способа заполнения матрицы:" << std::endl;
    auto generator = choose_fill_method();
    
    if (dynamic_cast<IStreamGenerator*>(generator.get()))
    {
        // Если выбран ввод с клавиатуры, заполняем интерактивно
        fill_matrix_interactively(*matrix);
    }
    else
    {
        // Иначе используем генератор
        matrix->fill(*generator);
    }

    Task2Exercise exercise(std::move(matrix), std::move(generator));

    std::cout << "\nИсходная матрица: " << exercise.get_matrix().to_string() << std::endl;

    exercise.task(); // Выполняем задание

    std::cout << "Результат: " << exercise.get_matrix().to_string() << std::endl;
}

void demonstrate_task3() {
    std::cout << "\n=== Задание 3 ===" << std::endl;
    std::cout << "Создание матрицы M из матрицы P по правилу:" << std::endl;
    std::cout << "M[i] = i * P[i], если P[i] четное" << std::endl;
    std::cout << "M[i] = -P[i], если P[i] нечетное" << std::endl;

    // Создаем матрицу
    std::cout << "\nВведите размер матрицы: ";
    size_t size;
    std::cin >> size;
    
    auto matrix = std::make_unique<Matrix<int>>(size);
    
    // Выбор способа заполнения
    std::cout << "\nВыбор способа заполнения матрицы:" << std::endl;
    auto generator = choose_fill_method();
    
    if (dynamic_cast<IStreamGenerator*>(generator.get()))
    {
        // Если выбран ввод с клавиатуры, заполняем интерактивно
        fill_matrix_interactively(*matrix);
    }
    else
    {
        // Иначе используем генератор
        matrix->fill(*generator);
    }

    Task3Exercise exercise(std::move(matrix), std::move(generator));

    std::cout << "\nМатрица P: " << exercise.get_matrix().to_string() << std::endl;

    exercise.task(); // Выполняем задание

    std::cout << "Матрица M (результат): " << exercise.get_result().to_string() << std::endl;
}

int main() {
    try {
        std::cout << "Программа для работы с матрицами" << std::endl;
        std::cout << "=================================" << std::endl;

        int choice;
        do {
            std::cout << "\nМеню:\n";
            std::cout << "1. Задание 1 (замена последнего отрицательного элемента)\n";
            std::cout << "2. Задание 2 (удаление элементов с одинаковыми первыми цифрами)\n";
            std::cout << "3. Задание 3 (создание матрицы M из P)\n";
            std::cout << "0. Выход\n";
            std::cout << "Ваш выбор: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    demonstrate_task1();
                    break;
                case 2:
                    demonstrate_task2();
                    break;
                case 3:
                    demonstrate_task3();
                    break;
                case 0:
                    std::cout << "Выход из программы." << std::endl;
                    break;
                default:
                    std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
            }
        } while (choice != 0);

        std::cout << "\nПрограмма завершена!" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
