#include<stdio.h>

int is_fav_coin_available(long long P, long long T)
{
    long long change=P-T;
    int fav_coin = 2;

    if((change & fav_coin) == fav_coin)
    {
        return 1;
    }

    return 0;
}

int main()
{
    long long P,T;
    scanf("%lld %lld",&T,&P);

    if(is_fav_coin_available(T,P))
    {
        printf("Yes\n");
    }

    else{
        printf("no\n");

    }


    return 0;
}
