#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stbool.h>
#include <float.h>

/*
* @brief функция для вычисления значения y
* @param x значение переменной х
* @return результат значения у
**/ 
double get_y(const double x);

/**
* @brief функция считывает ввод пользователя с проверкой
* @return введенное число типа double
*/
double input(void);

/**
* @brief функция считывает ввод пользователя с проверкой на положительное число
* @return введенное число типа double
*/
double Positiveinput(void);

/**
* @brief функция для проверки того, находится ли значение в пределах домена get_y
* @param x - значение для проверки
* @return true, если x находится в допустимой области get_y, в противном случае false
*/
bool is_in_domain(double x);

/*
* @brief точка входа в программу
* @return 0 в случае успеха
**/
int main(void){
	puts("Введите начальное значение х");
	double start=input();
        puts("Введите конечное значение х");
	double end =input();
        puts("Введите шаг");
	double start=Positiveinput();
	
	for (start;start <= end + DBL_EPSILON; start += step) 
	{
		printf("y=%lf\n", get_y(start));
	}
	return 0;
}
bool is_in_domain(double x) 
{
	if (fabs(x - 2) < DBL_EPSILON)
		return false;
	if (x < 0)
		return false;
	return true;
}
double get_y(const double x) {
	return x + cos(pow(x, 0.52) + 2);
}

double input(void) {
  double number = 0;
  if (scanf_s("%lf", &number) != 1) {
    puts("Ваш ввод некорректен");
    exit(EXIT_FAILURE);
  }
  return number;
}
double positiveinput(void)
{
  double number = input();
  if (number < DBL_EPSILON )
  {
    puts("Введенное число меньше или равно нулю!");
    exit(EXIT_FAILURE);
  }
  return number;
}
