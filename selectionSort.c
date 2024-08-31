#include<stdio.h>

void swap(int *ptr1,int *ptr2)
{
    int temp=*ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;

}

void selectionSort(int arr[],int n)
{
    int i,j,min_idx;

    for(i=0; i < n-1; i++)
    {
        min_idx= i;

        for(j=i+1; j<n; j++)
         {


            if(arr[j] < arr[min_idx])
             {
                min_idx= j;
             }

         }

            if(min_idx!=i){

                swap(&arr[min_idx], &arr[i]);
            }

        }
}

void print(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d",arr[i]);
        printf("\n");
    }
}

int main()
{

int arr[]={66,22,11,33,44,55,88,99};
int n=sizeof(arr)/sizeof(arr[0]);
selectionSort(arr,n);
printf("The sorted array list is : \n");
print(arr,n);

    return 0;
}
