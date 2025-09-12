#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <memory> // Для умных указателей
#include <cmath>   // Для abs() - модуль числа

// Функция для заполнения массива случайными числами в диапазоне [-10; 20]
void fillArrayRandom(std::unique_ptr<int[]>& arr, int n) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> distrib(-10, 20);

  for (int i = 0; i < n; ++i) {
    arr[i] = distrib(gen);
  }
}

// Функция для заполнения массива с клавиатуры
void fillArrayKeyboard(std::unique_ptr<int[]>& arr, int n) {
  std::cout << "Введите " << n << " целых чисел в диапазоне [-10; 20]:" << std::endl;
  for (int i = 0; i < n; ++i) {
    int input;
    std::cout << "Элемент " << i + 1 << ": ";
    std::cin >> input;

    // Проверка на корректность ввода
    if (input < -10 || input > 20) {
      std::cout << "Ошибка: Введенное число не входит в диапазон [-10; 20]. Повторите ввод." << std::endl;
      --i; // Уменьшаем счетчик, чтобы повторно запросить ввод для текущего элемента
      continue;
    }

    arr[i] = input;
  }
}

//1. Заменить последний отрицательный элемент массива на модуль первого элемента массива.
void replaceLastNegative(std::unique_ptr<int[]>& arr, int n) {
  int lastNegativeIndex = -1;
  for (int i = 0; i < n; ++i) {
    if (arr[i] < 0) {
      lastNegativeIndex = i;
    }
  }

  if (lastNegativeIndex != -1) {
    arr[lastNegativeIndex] = std::abs(arr[0]);
  }
}

// Функция для проверки, совпадают ли первая и вторая цифры числа
bool hasEqualFirstTwoDigits(int num) {
  if (num < 0) {
    num = -num; // Работаем с абсолютным значением
  }

  if (num < 10) {
    return false; // У однозначных чисел нет второй цифры
  }

  if (num < 100) {
      return (num / 10) == (num % 10);
  }
  else{
      std::string s = std::to_string(num);
      return s[0] == s[1];

  }
}

//2. Удалить из массива все элементы, у которых первая и вторая цифры одинаковые.
void removeElementsWithEqualDigits(std::unique_ptr<int[]>& arr, int& n) {
  std::vector<int> tempArray;
  for (int i = 0; i < n; ++i) {
    if (!hasEqualFirstTwoDigits(arr[i])) {
      tempArray.push_back(arr[i]);
    }
  }

  // Обновляем размер массива
  n = tempArray.size();

  // Создаем новый массив с новым размером.  Важно: arr должен быть уничтожен перед переназначением!
  arr.reset(new int[n]);


  // Копируем элементы из временного вектора обратно в массив
  for (int i = 0; i < n; ++i) {
    arr[i] = tempArray[i];
  }
}

//3. Из элементов массива P сформировать массив M той же размерности по правилу: если элемент четный, то Mi=i*Pi , если нечетный, то Mi=-Pi.
std::unique_ptr<int[]> transformArray(const std::unique_ptr<int[]>& pArr, int n) {
  std::unique_ptr<int[]> mArr(new int[n]);

  for (int i = 0; i < n; ++i) {
    if (pArr[i] % 2 == 0) { // Четный
      mArr[i] = i * pArr[i];
    } else { // Нечетный
      mArr[i] = -pArr[i];
    }
  }

  return mArr;
}

// Функция для вывода массива
void printArray(const std::unique_ptr<int[]>& arr, int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

int main() {
  int n;
  std::cout << "Введите размер массива: ";
  std::cin >> n;

  // Создаем массив с использованием умного указателя unique_ptr
  std::unique_ptr<int[]> arr(new int[n]);

  int choice;
  std::cout << "Выберите способ заполнения массива:" << std::endl;
  std::cout << "1. Случайными числами" << std::endl;
  std::cout << "2. С клавиатуры" << std::endl;
  std::cout << "Ваш выбор: ";
  std::cin >> choice;

  switch (choice) {
    case 1:
      fillArrayRandom(arr, n);
      break;
    case 2:
      fillArrayKeyboard(arr, n);
      break;
    default:
      std::cout << "Некорректный выбор." << std::endl;
      return 1;
  }

  std::cout << "Исходный массив: ";
  printArray(arr, n);

  replaceLastNegative(arr, n);
  std::cout << "Массив после замены последнего отрицательного элемента: ";
  printArray(arr, n);

removeElementsWithEqualDigits(arr, n);
  std::cout << "Массив после удаления элементов с одинаковыми первой и второй цифрами: ";
  printArray(arr, n);

  std::unique_ptr<int[]> mArr = transformArray(arr, n);
  std::cout << "Массив M, сформированный из массива P: ";
  printArray(mArr, n);

  return 0;
}
