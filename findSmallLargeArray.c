#include<stdio.h>

int main()
{
     int size;

             printf("enter array size : \n");
             scanf("%d",&size);


             int arr[size];

             printf("enter %d elements : \n",size);
             for(int i =0; i<size; i++)
             {
                 scanf("%d",&arr[i]);
             }

              int smallest = arr[0];
             int highest = arr[0];
             for(int i =1; i<size; i++)
             {
                 if(arr[i] < smallest)
                 {
                     smallest = arr[i];

                 }
                 if(arr[i] > highest)
                 {
                     highest = arr[i];
                 }

             }



             printf("the smallest arr is %d",smallest);
             printf("the highest arr is %d",highest);

             return 0;
}





