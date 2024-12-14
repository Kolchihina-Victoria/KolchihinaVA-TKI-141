#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <float.h>
#include <math.h>

/**
 *@brief считывает целочисленное значение.
 *@return целое значение.
*/
int GetInt(void);

/**
 *@brief считывает неотрицательное целое число.
 *@return неотрицательное целое значение.
*/
size_t GetNonNegativeInt(void);

/**
 *@brief  вычисляет сумму на основе заданного значения count.
 *@param count количество слагаемых, используемых при расчете суммы.
 *@return вычисленную сумму в виде double.
*/
double GetSumCount(const size_t count);

/**
 *@brief вычисляет значение на основе рекуррентного отношения.
 *@param k - параметр, используемый при повторном вычислении.
 *@return ввычисленное значение в виде double.
*/
double GetReccurent(const size_t k);

/**
 *@brief считывает число с плавающей запятой.
 *@return число типа double .
*/
double GetDouble(void);

/**
 *@brief считывает положительное число с плавающей запятой.
 *@return  положительное число типа double .
*/
double GetEpsilon(void);

/**
 *@brief вычисляет сумму на основе значения epsilon.
 *@param epsilon - пороговое значение, используемое для остановки вычисления суммы.
 *@return вычисленную сумму на основе указанного значения epsilon.
*/
double GetSumEpsilon(const double epsilon);

/**
 * @brief точка входа в программу 
 * @return возращает summ в случае успеха
 */
int main(void)
{
    puts("Количество членов последовательности");
    size_t count = GetNonNegativeInt();
    printf("Сумма последовательности из %zu элементов равна %.18lf", count, GetSumCount(count));
    
    puts("\nВведите точность вычиления");
    double epsilon = GetEpsilon();
    printf("Сумма последовательности с точностью %lf равна %.18lf", epsilon, GetSumEpsilon(epsilon));
    return EXIT_SUCCESS;
}

int GetInt(void)
{
    int a = 0;
    int result = scanf("%d", &a);
    if (result != 1)
    {
        errno = EIO;
        perror("Не удалось считать число");
        exit(EXIT_FAILURE);
    }
    
    return a;
}

size_t GetNonNegativeInt(void)
{
    int a = GetInt();
    if (a <= 0)
    {
        errno = EDOM;
        perror("Количество членов последовательности должно быть > 0");
        exit(EXIT_FAILURE);
    }
    
    return (size_t)a;
}

double GetSumCount(const size_t count)
{
    double summ = 0;
    double current = -8.0;
    for(size_t k = 1; k < count; ++k)
    {
        summ += current;
        current *= GetReccurent(k);
        
    }
    
    return summ;
}

double GetReccurent(const size_t k)
{
    return pow(-1,k)*((pow(k+1,3))/k) ;
}

double GetEpsilon()
{
    double epsilon = GetDouble();
    if (epsilon <= DBL_EPSILON)
    {
        errno = EDOM;
        perror("Точность должна быть > 0");
        exit(EXIT_FAILURE);
    }
    
    return epsilon;
}

double GetDouble(void)
{
    double a = 0.0;
    int result = scanf("%lf", &a);
    if (result != 1)
    {
        errno = EIO;
        perror("Не удалось считать число");
        exit(EXIT_FAILURE);
    }
    
    return a;
}

double GetSumEpsilon(const double epsilon)
{
    double summ = 0;
    double current = -8.0;
    int k = 1;

    while(fabs(current) >= epsilon)
    {
        summ += current;
        current *= GetReccurent(k);
        ++k;
        
    }
    
    return summ;
}
