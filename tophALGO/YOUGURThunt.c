#include<stdio.h>

int main()
{
    int N;
    scanf("%d",&N);

    int yougurt_amount[N];
    for(int i=0;i<N;i++)
    {
        scanf("%d",&yougurt_amount[i]);
    }

    int max_yougurt = -1;
    int max_yougurt_house = -1;

    for(int i=0;i<N;i++)
    {
        if(yougurt_amount[i]>max_yougurt)
        {
              max_yougurt = yougurt_amount[i];
            max_yougurt_house = i;
        }
        else if(  yougurt_amount[i] == max_yougurt && i>max_yougurt_house)
        {
            max_yougurt_house = i;
        }

    }

    printf("%d\n",max_yougurt_house + 1);


    return 0;
}
