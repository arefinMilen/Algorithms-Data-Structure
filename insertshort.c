#include<stdio.h>

void insertSort(int arr[],int n){

int i,j,key;

for(i=1;i<n;i++)
{
    key=arr[i];
    j=i-1;

    while(j>=0 && arr[j]>key)
    {
        arr[j+1]=arr[j];
        j=j-1;
    }

    arr[j+1]=key;

}

}


void print(int arr[],int size)
{

    for(int i=0;i<size;i++)
    {
      printf("%d ",arr[i]);

    }

}

int main()
{
    int arr[]={7,5,8,1,4,3,2,6};
    int element=sizeof(arr)/sizeof(arr[0]);
    insertSort(arr,element);
    printf("the insert sort list is : ");
    print(arr,element);


    return 0;
}
