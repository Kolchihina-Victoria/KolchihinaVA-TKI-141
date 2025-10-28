#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>

/**
 * @brief создает динамически выделяемый массив целых чисел.
 * @param arrayLength количество элементов в массиве.
 * @return вновь выделенный целочисленный массив. 
 */
int* CreateArray(size_t arrayLength);

/**
 * @brief заполняет целочисленный массив на основе выбора пользователя.
 * @param array указатель на целочисленный массив, который требуется заполнить. 
 * @param arrayLength длина массива. 
 */
void FillArray(int* array, size_t arrayLength);

/**
 * @brief заполняет целочисленный массив случайными числами.
 * @param array указатель на целочисленный массив для заполнения.
 * @param arrayLength длина массива.
 */
void FillArrayRandomly(int* array, size_t arrayLength);

/**
 * @brief заполняет целочисленный массив значениями, вводимыми пользователем с клавиатуры.
 * @param array указатель на целочисленный массив для заполнения.
 * @param arrayLength длина массива.
 */
void FillArrayFromKeyboard(int* array, size_t arrayLength);

/**
 * @brief выводит элементы целочисленного массива.
 * @param array указатель на целочисленный массив для заполнения. 
 * @param arrayLength длина массива. 
 */
void PrintArray(const int* array, size_t arrayLength);

/**
 * @brief заменяет первый элемент массива наименьшим по абсолютному значению.
 * @param array указатель на целочисленный массив, который требуется изменить. 
 * @param arrayLength длина массива. 
 */
void ReplaceMinNegAbs(int* array, size_t arrayLength);

/**
 * @brief удаляет все элементы из целочисленного массива, которые заканчиваются цифрой ноль.
 * @param array указатель на целочисленный массив, который требуется изменить.
 * @param arrayLength указатель на длину массива.
 * @return массив с измененным размером.  
 */
int* RemoveLastDigitZero(int* array, size_t *arrayLength);

/**
 * @brief преобразует целочисленный массив в новый массив с измененными элементами.
 * @param array указатель на целочисленный массив для преобразования. 
 * @param arrayLength длина массива.
 * @return преобразованный целочисленный массив.
 */
int* TransformArray(const int* array, size_t arrayLength);

/**
 * @brief считывает целое число .
 * @return целочисленное значение.
 */
int GetInt(void);

/**
 * @brief считывает неотрицательное целое число .
 * @return неотрицательное целое значение.
 */
size_t GetNonNegativeInt(void);

/**
* @brief генерирует случайное целое число в диапазоне [-100, 200].
* @return случайное целое число в диапазоне от -100 до 200.
*/
int GetRandomNumber();

/**
* @brief точка входа в программу.
* @return 0 в случае успеха.
*/
int main(void) {
    puts("Введите размер массива:");
    size_t arrayLength = (size_t)GetNonNegativeInt();

    if (arrayLength == 0) {
        puts("Размер массива должен быть больше 0");
        return 1;
    }

    int* array = CreateArray(arrayLength);
    FillArray(array, arrayLength);

    puts("Исходный массив:");
    PrintArray(array, arrayLength);


    ReplaceMinNegAbs(array, arrayLength);
    puts("Массив после замены:");
    PrintArray(array, arrayLength);


    array = RemoveLastDigitZero(array, &arrayLength);
    puts("Массив после удаления:");
    PrintArray(array, arrayLength);


    int* transformedArray = TransformArray(array, arrayLength);
      puts("Преобразованный массив:");
    PrintArray(transformedArray, arrayLength);


    free(array);
    free(transformedArray);
    return 0;
}
int* CreateArray(size_t arrayLength) {
    int* array = (int*)malloc(arrayLength * sizeof(int));
    if(array == NULL)
        {
           perror("Memory allocation failed");
           return NULL;
        }
    return array;
}

void FillArray(int* array, size_t arrayLength) {
    puts("Выберите способ заполнения массива:\n");
    int choice = GetInt();

    switch (choice) {
    case 2:
        FillArrayFromKeyboard(array, arrayLength);
        break;
    default:
        puts("Неверное значение для метода заполнения:");
        free(array);
        exit(1);
    }
}

void FillArrayRandomly(int* array, size_t arrayLength) {
    srand(time(NULL));
    for (size_t i = 0; i < arrayLength; i++) {
        array[i] = GetRandomNumber();
    }
}

void FillArrayFromKeyboard(int* array, size_t arrayLength) {
    puts("Введите элементы массива:");
    for (size_t i = 0; i < arrayLength; i++) {
        printf("array[%zu] = ", i);
        array[i] = GetInt();
    }
}

void PrintArray(const int* array, size_t arrayLength) {
    for (size_t i = 0; i < arrayLength; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void ReplaceMinNegAbs(int* array, size_t arrayLength) {
    if (arrayLength == 0)
        return;
    int minNegAbs = INT_MAX;
    int minNegIndex = -1;

    for (size_t i = 0; i < arrayLength; i++) {
        if (array[i] < 0 && abs(array[i]) < minNegAbs) {
            minNegAbs = abs(array[i]);
            minNegIndex = i;
        }
    }

    if (minNegIndex != -1) {
        int temp = array[0];
        array[0] = array[minNegIndex];
        array[minNegIndex] = temp;
    }
}

int* RemoveLastDigitZero(int* array, size_t* arrayLength) {
     if (array == NULL || *arrayLength == 0) {
        return array;
    }

    int* temp = (int*)malloc(*arrayLength * sizeof(int));
    if (temp == NULL) {
       perror("Memory allocation failed");
       return array;
    }
    size_t tempIndex = 0;
    for (size_t i = 0; i < *arrayLength; i++) {
        if (abs(array[i]) % 10 != 0) {
            temp[tempIndex] = array[i];
            tempIndex++;
        }
    }


     if (tempIndex != *arrayLength) {

         int *newArray = (int*)realloc(temp, tempIndex * sizeof(int));

          if (newArray == NULL && tempIndex != 0) {
               free(temp);
               return array;
            }
        free(array);
        *arrayLength = tempIndex;
          return newArray == NULL? temp: newArray;
    }
    free(array);
    return temp;

}


int* TransformArray(const int* array, size_t arrayLength) {
     if (array == NULL || arrayLength == 0) {
        return NULL;
    }

    int* transformed = (int*)malloc(arrayLength * sizeof(int));

     if (transformed == NULL) {
           perror("Memory allocation failed");
           return NULL;
    }

    for (size_t i = 0; i < arrayLength; i++) {
        if (i % 2 == 0) {
            transformed[i] = (int)i * array[i];
        } else {
            transformed[i] = -array[i];
        }
    }
    return transformed;
}

int GetInt(void) {
    int value;
    while (scanf("%d", &value) != 1) {
        puts("Неверный ввод. Пожалуйста, введите целое число.");
        while (getchar() != '\n');
    }
    return value;
}

size_t GetNonNegativeInt(void) {
    size_t value;
    while (scanf("%zu", &value) != 1 || (long)value < 0) {
        puts("Неверный ввод. Пожалуйста, введите неотрицательное целое число.");
        while (getchar() != '\n');
    }
    return value;
}

int GetRandomNumber()
{
   const int min = -100;
   const int max = 200;
   return rand() % (max - min + 1) + min;
}
