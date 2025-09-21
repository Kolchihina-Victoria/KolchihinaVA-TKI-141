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
