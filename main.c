#include <stdio.h>
#include <math.h>

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
