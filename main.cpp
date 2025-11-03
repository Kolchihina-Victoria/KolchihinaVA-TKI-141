<<<<<<< HEAD
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
=======
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <memory>
#include <cmath>
#include <string>

// Прототипы функций - объявляем их существование компилятору
void fillArrayRandom(std::unique_ptr<int[]>& arr, int n);
void fillArrayKeyboard(std::unique_ptr<int[]>& arr, int n);
void replaceLastNegative(std::unique_ptr<int[]>& arr, int n);
bool hasEqualFirstTwoDigits(int num);
void removeElementsWithEqualDigits(std::unique_ptr<int[]>& arr, int& n);
std::unique_ptr<int[]> transformArray(const std::unique_ptr<int[]>& pArr, int n);
void printArray(const std::unique_ptr<int[]>& arr, int n);

int main() {
    int n;

    // Блок ввода и проверки размера массива
    while (true) {
        std::cout << "Введите размер МАССИВА (положительное число): ";
        
        // Проверяем, что введено число, а не текст
        if (!(std::cin >> n)) {
            std::cerr << "Ошибка: введите число!" << std::endl;
            std::cin.clear(); // Сбрасываем флаги ошибок
            std::cin.ignore(10000, '\n'); // Очищаем буфер ввода
            continue; // Возвращаемся к началу цикла
        }

        // Проверяю, что размер положительный
        if (n <= 0) {
            std::cerr << "Ошибка: размер должен быть положительным!" << std::endl;
            continue;
        }

        break; // Вывожу из цикла, если все проверки пройдены
    }

    // Создаем динамический массив с использованием умного указателя
    // unique_ptr автоматически освобождает память при выходе из области видимости
    std::unique_ptr<int[]> arr(new int[n]);

    // Выбор способа заполнения массива
    int choice;
    std::cout << "Выберите способ заполнения массива:" << std::endl;
    std::cout << "1. Случайными числами" << std::endl;
    std::cout << "2. С клавиатуры" << std::endl;
    std::cout << "Ваш выбор: ";
    std::cin >> choice;

    // Обработка выбора пользователя
    switch (choice) {
        case 1:
            fillArrayRandom(arr, n); // Заполнение случайными числами
            break;
        case 2:
            fillArrayKeyboard(arr, n); // Заполнение с клавиатуры
            break;
        default:
            std::cout << "Некорректный выбор." << std::endl;
            return 1; // Завершение программы с кодом ошибки
    }

    // Вывод исходного массива
    std::cout << "Исходный массив: ";
    printArray(arr, n);

    // 1. Замена последнего отрицательного элемента
    replaceLastNegative(arr, n);
    std::cout << "Массив после замены последнего отрицательного элемента: ";
    printArray(arr, n);

    // 2. Удаление элементов с одинаковыми цифрами
    removeElementsWithEqualDigits(arr, n);
    std::cout << "Массив после удаления элементов с одинаковыми первой и второй цифрами: ";
    printArray(arr, n);

    // 3. Преобразование массива по правилу
    std::unique_ptr<int[]> mArr = transformArray(arr, n);
    std::cout << "Массив M, сформированный из массива P: ";
    printArray(mArr, n);

    return 0; // Успешное завершение программы
}

// РЕАЛИЗАЦИИ ФУНКЦИЙ

// Заполнение массива случайными числами в диапазоне [-10, 20]
void fillArrayRandom(std::unique_ptr<int[]>& arr, int n) {
    std::random_device rd; // Источник энтропии
    std::mt19937 gen(rd()); // Генератор случайных чисел
    std::uniform_int_distribution<> distrib(-10, 20); // Равномерное распределение

    for (int i = 0; i < n; ++i) {
        arr[i] = distrib(gen); // Заполняем каждый элемент случайным числом
    }
}

// Заполнение массива с клавиатуры с проверкой диапазона
void fillArrayKeyboard(std::unique_ptr<int[]>& arr, int n) {
    std::cout << "Введите " << n << " целых чисел в диапазоне [-10; 20]:" << std::endl;
    for (int i = 0; i < n; ++i) {
        int input;
        std::cout << "Элемент " << i + 1 << ": ";
        std::cin >> input;

        // Проверка на корректность ввода
        if (std::cin.fail() || input < -10 || input > 20) {
            std::cout << "Ошибка: Введенное число не входит в диапазон [-10; 20] или не является числом. Повторите ввод." << std::endl;
            --i; // Повторяем ввод для этого же элемента
            std::cin.clear(); // Сбрасываем флаги ошибок
            std::cin.ignore(10000, '\n'); // Очищаем буфер
            continue;
        }

        arr[i] = input; // Сохраняем корректное значение
    }
}

// Замена последнего отрицательного элемента на модуль первого элемента
void replaceLastNegative(std::unique_ptr<int[]>& arr, int n) {
    int lastNegativeIndex = -1; // Индекс последнего отрицательного элемента
    
    // Поиск последнего отрицательного элемента
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            lastNegativeIndex = i; // Запоминаем индекс
        }
    }

    // Если найлен отрицательный элемент, заменяю его
    if (lastNegativeIndex != -1) {
        arr[lastNegativeIndex] = std::abs(arr[0]); // Заменяем на модуль первого элемента
    }
}

// Проверка, совпадают ли первая и вторая цифры числа
bool hasEqualFirstTwoDigits(int num) {
    if (num < 0) {
        num = -num; // Работаем с абсолютным значением
    }

    // Для однозначных чисел нет второй цифры
    if (num < 10) {
        return false;
    }

    // Для двузначных чисел сравниваем цифры
    if (num < 100) {
        return (num / 10) == (num % 10);
    }
    // Для многозначных чисел преобразуем в строку и сравниваем первые два символа
    else {
        std::string s = std::to_string(num);
        return s[0] == s[1];
    }
}

// Удаление элементов с одинаковыми первой и второй цифрами
void removeElementsWithEqualDigits(std::unique_ptr<int[]>& arr, int& n) {
    std::vector<int> tempArray; // Временный вектор для хранения подходящих элементов
    
    // Копируем в вектор только те элементы, которые НЕ имеют одинаковых цифр
    for (int i = 0; i < n; ++i) {
        if (!hasEqualFirstTwoDigits(arr[i])) {
            tempArray.push_back(arr[i]);
        }
    }

    // Обновление размера массива
    n = tempArray.size();

    // Пересоздание массива с новым размером
    arr.reset(new int[n]);

    // Копирую элементы обратно в массив
    for (int i = 0; i < n; ++i) {
        arr[i] = tempArray[i];
    }
}

// Преобразование массива по правилу: четные -> i*Pi, нечетные -> -Pi
std::unique_ptr<int[]> transformArray(const std::unique_ptr<int[]>& pArr, int n) {
    std::unique_ptr<int[]> mArr(new int[n]); // Создаем новый массив

    for (int i = 0; i < n; ++i) {
        if (pArr[i] % 2 == 0) { // Если элемент четный
            mArr[i] = i * pArr[i]; // Умножаем на индекс
        } else { // Если элемент нечетный
            mArr[i] = -pArr[i]; // Меняем знак
        }
    }

    return mArr; // Возвращаю новый массив
}

// Вывод массива на экран
void printArray(const std::unique_ptr<int[]>& arr, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl; // Переход на новую строку после вывода
}
>>>>>>> d9704823981906b87314c3553dd256045c25b5af
