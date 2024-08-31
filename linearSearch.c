#include<stdio.h>

int LinearSearch(int arr[],int number,int key)
{
    for(int i=0;i<number;i++)
    {

        if(arr[i]==key)
        {
            return i;
        }

    }


    return -1;

}






int main()
{

    int arr[]={3,4,7,5,2,1,9};
int    number=sizeof(arr)/sizeof(arr[0]);
    printf("enter a number you want to search \n");
    int key;
    scanf("%d",&key);

    int result= LinearSearch(arr,number,key);

    if(result!=-1)
    {
        printf("Element %d  is founded at index %d\n",key,result);
    }

    else{
         printf("Element %d  is not founded at index \n",key);
    }



    return 0;
}
