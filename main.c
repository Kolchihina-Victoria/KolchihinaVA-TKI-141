#include <stdio.h>
#include <math.h>

/*
* @brief функция для вычисления значения y
* @param x значение переменной х
* @return результат значения у
**/ 

double get_y(const double x);

/*
* @brief точка входа в программу
* @return 0 в случае успеха
**/

int main(void){
	double x = 0.5;
	for (x; x <= 1; x += 0.05) 
	{
		printf("y=%lf\n", get_y(x));
	}
	return 0;
}
double get_y(const double x) {
	return x + cos(pow(x, 0.52) + 2);
}
