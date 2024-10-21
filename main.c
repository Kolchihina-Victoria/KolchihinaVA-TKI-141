#include <stdio.h>
#include <math.h>

/**
* @brief функция для вычисления значения а
* param count значение переменной cnt
* param f значение переменной f
* @return результат  вычисления а
*/

double get_a(const double count, const double f);

/**
* @brief функция для вычисления значения sr_arifm
* param count значение переменной cnt
* param f значение переменной f
* @return результат  вычисления sr_arifm
*/

double sr_arifm(const double count, const double f);
double input(void);

/**
* @brief точка входа в программу
* @return в случае успеха
*/

int main() {
	puts("Enter the count:");
	double count = input();
	puts("Enter the f:");
	double f = input();
	printf("a = %f\n", get_a(count, f));
	printf("%f", sr_arifm(count, f));
	return 0;
}
double input(void) 
{
	double number;
	scanf_s("%lf", &number);
	return number;
}
double get_a(const double count, const double f) {
	return sqrt(fabs(pow(count, 3)) * fabs(pow(f, 3)));
}
double sr_arifm(const double cnt, const double f) {
	return (fabs(pow(cnt, 3)) * fabs(pow(f, 3))) / 2;
}
