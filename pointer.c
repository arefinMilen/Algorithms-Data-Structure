#include<stdio.h>
void withPointerSwap(int *ptr1,int *ptr2)
{

    int temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;

}
void withOutPointer(int a,int b)
{

    int temp;
    temp=a;
    a=b;
    b=temp;
}


int main()
{
    int a=30,b=40;

    withOutPointer(a, b);
    printf("after swaping a= %d, b= %d\n",a,b);


    withPointerSwap(&a,&b);
    printf("After swaping a= %d, b= %d",a,b);



    return 0;
}
