#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,s=0,i;
    cin>>m;
    int a[m+5];
    for(i=0; i<m; i++)
        cin>>a[i];
    sort(a,a+m);
    for(i=0; i<m; i+=2)
    {
        if(a[i]!=a[i+1])
            s+=(a[i+1]-a[i]);
    }
    cout<<s<<endl;
    return 0;
}
