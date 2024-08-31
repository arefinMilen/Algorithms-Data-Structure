#include<stdio.h>

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);

    int scores[n];
    for(int i;i<n;i++)
    {

        scanf("%d",&scores[i]);
    }


    int k_score = scores[k-1];
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(scores[i]> 0 && scores[i] >= k_score)
        {
            count++;
        }
    }

    printf("%d\n",count);


    return 0;
}
