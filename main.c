#include <stdio.h>
#include <math.h>

/**
*@brief factorial считает факториал числа 
*@return возвращает значение факториала
*/
int factorial(int n);

/**
*@brief  raising_to_the_third_power возводит число в 3 степень 
*@return возвращает значение числа в 3 степени
*/
float raising_to_the_third_power(int z);

/**
*@brief raising_to_the_k_power возводит число в к степень
*@return возвращает значение числа в к степени
*/
float raising_to_the_k_power(int x);

/**
*@brief res_p свыводит промежуточный результат
*@return возвращает значение промежуточного результата
*/
float res_p(int e);

/**
*@brief выводит значение выражения
*@return  возращаеь 0 в случае успеха
*/
int main() 
{
    float otvet=0.0;
    printf("Введите значение к:");
    int k;
    scanf("%d",&k);
    if (k>=1)
    {
    for (int i=1;i<=k;i++)
   {
    float ryad=res_p(i);
    otvet=otvet+ryad;
   }
printf("%f",otvet);
     }
else 
printf("введено неверное значение:");
}
int factorial(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * factorial(n - 1);
}
float raising_to_the_third_power(int z)
{
    if (z==0)
    {
        return 1;
    }
    else 
    return pow(z+1,3);
}
float raising_to_the_k_power(int x)
{
    if (x==0)
    {
        return 1;
    }
    else
    return pow(-1,x);
}
float res_p(int e)
{
  float resp=raising_to_the_k_power(e)*vraising_to_the_third_power(e)/factorial(e);
  printf("%f\n",resp);
  return resp;
  return 0;
}
