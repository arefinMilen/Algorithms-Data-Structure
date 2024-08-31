#include<stdio.h>


int main()
{
    int a;
    while(1)
    {
        scanf("%d",&a);
       if(a==0)
       {
           break;
       }
       int ans = g(a);
       printf("%d",ans);
    }

    return 0;
}

int g(int a)
{
    if(a==0)
    {


        return 0;
    }
    if (a%9==0)
    {
        return 9;
    }
    return a%9;

}
