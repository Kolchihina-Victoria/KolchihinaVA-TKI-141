#include <stdio.h>
#include <math.h>

/**
*@brief считывает данные типа int,вводимые пользователем
*@return возвращает значение,введённое пользователем
*/
int factorial(int n);

/**
*@brief считывает данные типа float,вводимые пользователем
*@return возвращает значение,введённое пользователем
*/
float vozvedenie_v_tretiu_snepen(int z);

/**
*@brief считывает данные типа float,вводимые пользователем
*@return возвращает значение,введённое пользователем 
*/
float vozvedenie_v_kstepen(int x);

/**
*@brief считывает данные типа float,вводимые пользователем
*@return возвращает значение,введённое пользователем
*/
float res_p(int e);

/**
*@brief считывает данные типа float,вводимые пользователем
*@return возвращает значение,введённое пользователем
*/
float otvet=0.0;

/**
*@brief выводит значение выражения
*@return  возращаеь 0 в случае успеха
*/

int main() 
{
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
float vozvedenie_v_tretiu_snepen(int z)
{
    if (z==0)
    {
        return 1;
    }
    else 
    return pow(z+1,3);
}
float vozvedenie_v_kstepen(int x)
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
  float resp=vozvedenie_v_kstepen(e)*vozvedenie_v_tretiu_snepen(e)/factorial(e);
  printf("%f\n",resp);
  return resp;
  return 0;
}
