#include<stdio.h>
#include<stdlib.h>

int main()
{
    int q,m,a,i,j,max,min;
    while(scanf("%d",&q)==1)
    {
        for(i=1;i<=q;i++)
        {
            scanf("%d",&m);
            max=0,min=100;
            for(j=1;j<=m;j++)
            {
                scanf("%d",&a);
                if(max<a)
                    max=a;
                if(min>a)
                    min=a;
            }
            printf("%d\n",(max-min)*2);
        }
    }
    return 0;
}
