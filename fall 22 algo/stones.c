#include<stdio.h>
int same_parity(int n,int stones[])
{
    int even_count =0;
    int odd_count = 0;

    for(int i = 0; i<n;i++)
    {
        if(stones[i]%2 ==0)
        {
           even_count++;
        }

        else
        {
          odd_count++;
        }

    }
    if(even_count==n || odd_count == n)
    {
         return "Yes";
    }
    else
    {
        return "No";
    }

}


int main()
{
   int n;
   scanf("%d",&n);
   int stones[n];
   for(int i = 0;i<n;i++)
   {
       scanf("%d",&stones[i]);
   }
printf(same_parity(n,stones));
    return 0;
}
