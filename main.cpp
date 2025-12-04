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

// Перечисление для способов заполнения матрицы
enum class FillMethod {
    KEYBOARD = 1,
    RANDOM = 2,
    CONSTANT = 3,
    ZEROS = 4
};

// Перечисление для меню выбора задач
enum class MenuChoice {
    TASK1 = 1,
    TASK2 = 2,
    TASK3 = 3,
    EXIT = 0
};

std::unique_ptr<Generator> choose_fill_method()
{
    std::cout << "\nВыберите способ заполнения матрицы:\n";
    std::cout << static_cast<int>(FillMethod::KEYBOARD) << ". С клавиатуры\n";
    std::cout << static_cast<int>(FillMethod::RANDOM) << ". Рандомно\n";
    std::cout << static_cast<int>(FillMethod::CONSTANT) << ". Константой\n";
    std::cout << static_cast<int>(FillMethod::ZEROS) << ". Нулями\n";
    std::cout << "Ваш выбор: ";

    int choice;
    std::cin >> choice;

    switch (static_cast<FillMethod>(choice))
    {
        case FillMethod::KEYBOARD:
            return std::make_unique<IStreamGenerator>(std::cin);
        case FillMethod::RANDOM:
        {
            int min, max;
            std::cout << "Введите минимальное значение: ";
            std::cin >> min;
            std::cout << "Введите максимальное значение: ";
            std::cin >> max;
            return std::make_unique<RandomGenerator>(min, max);
        }
        case FillMethod::CONSTANT:
        {
            int value;
            std::cout << "Введите константное значение: ";
            std::cin >> value;
            return std::make_unique<ConstantGenerator>(value);
        }
        case FillMethod::ZEROS:
            return std::make_unique<ZeroGenerator>();
        default:
            std::cout << "Неверный выбор. Используется заполнение с клавиатуры.\n";
            return std::make_unique<IStreamGenerator>(std::cin);
    }
}

void demonstrate_task1() {
    std::cout << "\n Задание 1 " << std::endl;
    std::cout << "Замена последнего отрицательного элемента матрицы на модуль первого элемента" << std::endl;

    // Создаем матрицу
    std::cout << "\nВведите размер матрицы: ";
    size_t size;
    std::cin >> size;

    auto matrix = std::make_unique<Matrix<int>>(size);

    // Выбор способа заполнения
    std::cout << "\nВыбор способа заполнения матрицы:" << std::endl;
    auto generator = choose_fill_method();

    // Заполняем матрицу через метод fill() с использованием генератора
    std::cout << "\nЗаполнение матрицы:\n";
    matrix->fill(*generator);

    // Если был выбран ввод с клавиатуры, дополнительно показываем заполненные значения
    if (dynamic_cast<IStreamGenerator*>(generator.get()))
    {
        std::cout << "Матрица заполнена следующими значениями:\n";
        std::cout << matrix->to_string() << std::endl;
    }

    Task1Exercise exercise(std::move(matrix), std::move(generator));

    std::cout << "\nИсходная матрица: " << exercise.get_matrix().to_string() << std::endl;

    exercise.task(); // Выполняем задание

    std::cout << "Результат: " << exercise.get_matrix().to_string() << std::endl;
}

void demonstrate_task2() {
    std::cout << "\nЗадание 2 " << std::endl;
    std::cout << "Удаление элементов, у которых первые две цифры одинаковые" << std::endl;

    // Создаем матрицу
    std::cout << "\nВведите размер матрицы: ";
    size_t size;
    std::cin >> size;

    auto matrix = std::make_unique<Matrix<int>>(size);

    // Выбор способа заполнения
    std::cout << "\nВыбор способа заполнения матрицы:" << std::endl;
    auto generator = choose_fill_method();

    // Заполняем матрицу через метод fill() с использованием генератора
    std::cout << "\nЗаполнение матрицы:\n";
    matrix->fill(*generator);

    // Если был выбран ввод с клавиатуры, дополнительно показываем заполненные значения
    if (dynamic_cast<IStreamGenerator*>(generator.get()))
    {
        std::cout << "Матрица заполнена следующими значениями:\n";
        std::cout << matrix->to_string() << std::endl;
    }

    Task2Exercise exercise(std::move(matrix), std::move(generator));

    std::cout << "\nИсходная матрица: " << exercise.get_matrix().to_string() << std::endl;

    exercise.task(); // Выполняем задание

    std::cout << "Результат: " << exercise.get_matrix().to_string() << std::endl;
}

void demonstrate_task3() {
    std::cout << "\nЗадание 3 << std::endl;
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

    // Заполняем матрицу через метод fill() с использованием генератора
    std::cout << "\nЗаполнение матрицы:\n";
    matrix->fill(*generator);

    // Если был выбран ввод с клавиатуры, дополнительно показываем заполненные значения
    if (dynamic_cast<IStreamGenerator*>(generator.get()))
    {
        std::cout << "Матрица заполнена следующими значениями:\n";
        std::cout << matrix->to_string() << std::endl;
    }

    Task3Exercise exercise(std::move(matrix), std::move(generator));

    std::cout << "\nМатрица P: " << exercise.get_matrix().to_string() << std::endl;

    exercise.task(); // Выполняем задание

    std::cout << "Матрица M (результат): " << exercise.get_result().to_string() << std::endl;
}

int main() {
    try {
        std::cout << "Программа для работы с матрицами" << std::endl;
        std::cout << "" << std::endl;

        MenuChoice choice;
        do {
            std::cout << "\nМеню:\n";
            std::cout << static_cast<int>(MenuChoice::TASK1) << ". Задание 1 (замена последнего отрицательного элемента)\n";
            std::cout << static_cast<int>(MenuChoice::TASK2) << ". Задание 2 (удаление элементов с одинаковыми первыми цифрами)\n";
            std::cout << static_cast<int>(MenuChoice::TASK3) << ". Задание 3 (создание матрицы M из P)\n";
            std::cout << static_cast<int>(MenuChoice::EXIT) << ". Выход\n";
            std::cout << "Ваш выбор: ";
            
            int input;
            std::cin >> input;
            choice = static_cast<MenuChoice>(input);

            switch (choice) {
                case MenuChoice::TASK1:
                    demonstrate_task1();
                    break;
                case MenuChoice::TASK2:
                    demonstrate_task2();
                    break;
                case MenuChoice::TASK3:
                    demonstrate_task3();
                    break;
                case MenuChoice::EXIT:
                    std::cout << "Выход из программы." << std::endl;
                    break;
                default:
                    std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
            }
        } while (choice != MenuChoice::EXIT);

        std::cout << "\nПрограмма завершена!" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
