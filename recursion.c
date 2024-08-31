#include<stdio.h>

int fact(int num)
{
    if(num==1) return 1;

    else
    {
        return num= num*fact(num-1);

    }

}


int main()
{

    printf("Factorial of the number is = %d",fact(5));


    return 0;
}
