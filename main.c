#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>
#include <time.h>

/**
 * @brief считывает массив и число обозначающее количество элементов массива
 * @return сумму четных элементов массива
 */
int sum_even_numb(int num[],int n);

/**
 * @brief считывает массив и число обозначающее количество элементов массива
 * @return произведение четных положительных эдементов мссива на последний элемент
 */
int multiplicatiom_numbers(int num[],int n);

/**
 * @brief считывает массив и число обозначающее количество элементов массива
 * @return номер первой пары соседних элементов с разными знаками
 */
int first_pair(int num[],int n);

/**
*@brief выводит значение массива
*@return  возращаеь 0 в случае успеха
*/
int main() 
{
    int n,i,z,r;
    int sum=0;
    printf("enter array size:");
    scanf("%d",&n);
    int num[n];
    printf("how to fill the array:\n");
    printf("1.random numbers:\n");
    printf("2.input numbers yourself:\n");
    scanf("%d",&i);    
    if (i==1)
    {
        srand(time(NULL));
        for(z=0;z<n;z++)
        {
            num[z]=rand()%300-100;
        }
    }
    else if(i==2)
    {
        for (z=0;z<n;z++)
        {
            printf("enter number from -100 to 200 %d:",z);
            scanf("%d",&num[z]);
            if ((num[z]<=200)&&(num[z]>=-100))
            {
                printf("enter right value:\n");
            }
            else
            {
                printf("invalid value entered:\n");
                return 0;
            }
        }
    }
    else
    {
        printf("invalid number:\n");
    }
    for(z=0;z<n;z++)
    printf("%d\n",num[z]);
    sum_even_numb(num,n);
    multiplicatiom_numbers( num, n);
    first_pair( num,n);
    return 0;
}
int sum_even_numb(int num[],int n)
{
    int sum=0;
    int r;
    printf("enter the number \n");
    scanf("%d",&r);
    for (int z=0;z<n;z++)
    {
        if ((num[z]%2==0)&&(num[z]>r))
        {
            sum=sum+num[z];
            printf("%d\n",sum);
        }
        else
        {
            printf("the array value does not match condidtion:\n");
        }
    }
    printf("summ even elements %d\n",sum);
    return 0;
}
int multiplicatiom_numbers(int num[],int n)
{
     for(int z=0;z< n;z++)
    {
        if ((num[z]%2==0)&&(num[z]>0))
        {
             printf("number is positive and even: %d\n",num[z]);
             num[z]=num[z]*num[n-1];
             printf("product of even positive number of an array by the last element %d\n",num[z]);
        }
        else
        {
             printf(" the invalid number  %d\n",num[z]);
        }
    }
    return 0;
}
int first_pair(int num[],int n)
{
     for(int z=0;z<n;z++)
   {
       if(num[z]*num[z+1]<0)
       {
           printf("number of the first pair: %d\n",(z+1));
           break;
       }
   }
   return 0;
}