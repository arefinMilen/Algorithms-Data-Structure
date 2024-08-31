#include<stdio.h>
int main()
{
    int a;
    while(1)
    {
        scanf("%d",&a);
         int ans = g(a);
        printf("%d",ans);

        if(a==0)
        {
            break;

        }

    }

    return 0;
}


int g(int a)
{
    if(a==0)
    {
        return 0;
    }
    if(a%9==0)
    {

        return 9;
    }
    return a%9;
}















/*
#include<stdio.h>

int binarySearch(int arr[],int left,int right,int key)
{
    while(left <= right)
    {


    int mid = left + (right - left )/2;

        if(arr[mid] <key)
    {
        left = mid +1;


    }

    else if (arr[mid] >key)
    {

        right = mid - 1;
    }

    else if (arr[mid]==key)
    {

        return 1;
    }


}

return 0;

}





/*
int main()
{
    int arr[]={11,22,33,44,55,66,77,88,99};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key;
    printf("enter your key number : \n");

    scanf("%d",&key);

    int result = binarySearch(arr,0,n-1,key);
    if(result!=-1){
        printf("the number of %d is found at  %d ",key,result);
    }

    else{

        printf("the number of %d is not found !!",key);
    }



    return 0;
}

int main ()
{

    int m,p;
    scanf("%d %d",&m,&p);
    int arr[m];

    for(int i = 0; i<m; i++)
    {
        scanf("%d",&arr[i]);

    }

    if(binarySearch(arr,0,m-1,p))
    {

        printf("true\n");
    }

    else
    {
        printf("false\n");
    }
}
*/


