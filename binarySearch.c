#include<stdio.h>

int binarySearch(int array[],int left,int right,int key)
{
    while(left<=right)
    {
        int mid = left+(right-left)/2;

        if(array[mid]<key)
        {
            left=mid+1;
        }
        else if(array[mid]>key)
        {
            right=mid-1;
        }
        else if (array[mid]==key){
            return 1;
        }

    }



    return -1;

}




int main()
{
    int array[]={0,11,22,33,44,55,66,77,88};
    int n=sizeof(array)/sizeof(array[0]);
    int key;
    printf("enter the value you want to search =");
    scanf("%d",&key);
    int result= binarySearch(array,0,n-1,key);

    if(result!=-1)
    {
        printf("the element of %d is founded at %d",key,result);
    }

    else{
        printf("the element of %d is not founded\n",key);
    }


    return 0;
}
