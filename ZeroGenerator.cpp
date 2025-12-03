
#include "ZeroGenerator.h"
#include "ConstantGenerator.h"
#include "RandomGenerator.h"
#include "IStreamGenerator.h"
#include <iostream>

int miit::algebra::ZeroGenerator::generate()
{
    return 0;
}

std::unique_ptr<miit::algebra::Generator> miit::algebra::ZeroGenerator::choose_fill_method()
{
    std::cout << "Выберите способ заполнения матрицы:\n";
    std::cout << "1. С клавиатуры\n";
    std::cout << "2. Рандомно\n";
    std::cout << "3. Константой\n";
    
    int choice;
    std::cin >> choice;
    
    switch (choice)
    {
        case 1:
            return std::make_unique<IStreamGenerator>(std::cin);
        case 2:
            std::cout << "Введите минимальное значение: ";
            int min, max;
            std::cin >> min;
            std::cout << "Введите максимальное значение: ";
            std::cin >> max;
            return std::make_unique<RandomGenerator>(min, max);
        case 3:
            std::cout << "Введите константное значение: ";
            int value;
            std::cin >> value;
            return std::make_unique<ConstantGenerator>(value);
        default:
            std::cout << "Неверный выбор. Используется заполнение нулями.\n";
            return std::make_unique<ZeroGenerator>();
    }
}
