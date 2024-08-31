#include<stdio.h>

int sum(int a, int b)
{
    int c = a+b;


}

void swap(int x,int y)
{
    printf("before swaping x= %d   y= %d\n",x,y);
    int temp;
    temp=x;
    x=y;
    y=temp;

    printf("after swaping x=%d  y=%d\n",x,y);

}


int main()
{
    int result = sum(3,4);

    printf("the sum is : %d\n",result);
    //the benifit of call outsite funtion is if i again sum multiple numbers i dont need to code all the program
    //before i have done already outsite that one,so i just call the function and pass the numbers thats it se in next line .!!
    printf("the other sum is: %d\n",sum(4,5));

    //swaping

    int a=20;
    int b=30;
    swap(a,b);

    return 0;
}
