#include<stdio.h>
int binarySearch(int arr[],int left,int right,int key)
{
    while(left<=right)
    {
        int mid = left + (right - left)/2;

        if(arr[mid]<key)
        {
            return binarySearch(arr,mid+1,right,key);

        }
        else if(arr[mid]>key)
        {
            return binarySearch(arr,left,mid-1,key);


        }
        else if (arr[mid]=key)
        {

            return 1;
        }
    }

    return 0;
}



int main()
{
   int m,p;
   int arr[100];

   scanf("%d %d",&m,&p);
   for(int i=0;i<m;i++)
   {
       scanf("%d",&arr[i]);

   }
   if(binarySearch(arr,0,m-1,p))
   {

       printf("true\n");

   }
   else{
    printf("false\n");
   }

return 0;
}
