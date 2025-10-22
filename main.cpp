#include "matrix.h"
#include "matrix.cpp"
#include <iostream>

int main() {
    size_t n;

    // Ввод размера массива с проверкой
    while (true) {
        std::cout << "Введите размер массива (положительное число): ";
        
        if (!(std::cin >> n) || n <= 0) {
            std::cout << "Ошибка: введите положительное число!" << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }
        break;
    }

    // Создаем вектор используя класс Matrix
    Matrix<int> P(n);

    // Выбор способа заполнения
    int choice;
    std::cout << "\nВыберите способ заполнения массива:\n";
    std::cout << "1. Случайными числами\n";
    std::cout << "2. С клавиатуры\n";
    std::cout << "Ваш выбор: ";
    
    std::cin >> choice;

    switch (choice) {
        case 1:
            P.fillRandom();
            break;
        case 2:
            P.fillFromKeyboard();
            break;
        default:
            std::cout << "Некорректный выбор. Используется заполнение случайными числами.\n";
            P.fillRandom();
            break;
    }

    // Вывод исходного массива
    std::cout << "\n--- ИСХОДНЫЙ МАССИВ ---\n";
    P.print();

    // 1. Замена последнего отрицательного элемента
    std::cout << "\n--- ЗАМЕНА ПОСЛЕДНЕГО ОТРИЦАТЕЛЬНОГО ЭЛЕМЕНТА ---\n";
    P.replaceLastNegative();
    P.print();

    // 2. Удаление элементов с одинаковыми цифрами
    std::cout << "\n--- УДАЛЕНИЕ ЭЛЕМЕНТОВ С ОДИНАКОВЫМИ ПЕРВЫМИ ДВУМЯ ЦИФРАМИ ---\n";
    P.removeElementsWithEqualDigits();
    P.print();

    // 3. Преобразование массива
    std::cout << "\n--- ПРЕОБРАЗОВАНИЕ МАССИВА ---\n";
    Matrix<int> M = P.transformArray();
    std::cout << "Массив P: ";
    P.print();
    std::cout << "Массив M: ";
    M.print();

    return 0;
}