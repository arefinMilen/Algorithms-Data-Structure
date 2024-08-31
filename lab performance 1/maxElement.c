#include<stdio.h>


int main()

{
    int n ,i;
    int a[100];
    printf("enter how many number you want to add\n");
    scanf("%d",&n);

    printf("enter your number's\n");
    for( i;i<n;i++)
    {
        scanf("%d",&a[i]);


    }
 int max=a[0];

 for(i=1;i<n;i++)
 {

     if(max <a[i])
 {
     max=a[i];

 }

 }


    printf("the max num is : %d",max);


    return 0;
}
