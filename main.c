#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stbool.h>
#include <float.h>


/**
* @brief проверяет равно ли число нулю(через эпсилон)
* @param number сравнимое число
* @return true если число равно нулю,в противном случае false
*/
bool isZero(const double number);
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

/*
* @brief точка входа в программу
* @return 0 в случае успеха
**/
int main(void){
	const double start = input(), end = input();
	const double step = input();
	
	for (double x = start; x < (end + step); x += step) 
	{
		printf("y=%lf\n", get_y(x));
	}
	return 0;
}
double get_y(const double x) {
	return x + cos(pow(x, 0.52) + 2);
}
bool isZero(const double number)
{
  return (fabs(number) < DBL_EPSILON);
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
  if ((number < 0) || isZero(number))
  {
    puts("Введенное число меньше или равно нулю!");
    exit(EXIT_FAILURE);
  }
  return number;
}
