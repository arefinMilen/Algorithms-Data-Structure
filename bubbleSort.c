#include<stdio.h>
#include<stdbool.h>
void swap(int *p1,int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;

}

void bubbleSort(int arr[],int n)
{
    int i,j;
    bool swapped;

    for(i=0;i<n-1;i++)
    {
        swapped=false;

        for(j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1])
            swap(&arr[j],&arr[j+1]);
        if(swapped=false)
            break;
    }


}

void print(int arr[],int size)
{
for(int i=0;i<size;i++)
{
    printf("%d \n",arr[i]);
    //printf("\n");
}



}





int main()
{
int arr[]={32,22,44,55,33,11,66,77};
int n =sizeof(arr)/sizeof(arr[0]);

bubbleSort(arr,n);
printf("the bubble sort list is : \n\n");
print(arr,n);

    return 0;
}
