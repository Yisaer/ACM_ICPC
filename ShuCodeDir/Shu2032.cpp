#include <cstdio>

#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int const Maxn = 105;

struct X
{
    int pla, num;
}p[105];
int a[105];
int cmp(int x, int y)
{
    return x>y;
}
int main()
{
    int T, i, n, m;
    cin>>T;
    while(T--)
    {
        memset(p,0,sizeof(p));
        memset(a,0,sizeof(a));
        queue<X>Q;
        
        scanf("%d%d", &n, &m);
        for(i=0; i<n; i++)
        {
            scanf("%d", &a[i]);
            p[i].num=a[i], p[i].pla=i;
            Q.push(p[i]);
        }
        sort(a, a+n, cmp);
        int maxtop=0;
        int num=1;
        while(1)
        {
            X x=Q.front();
            Q.pop();
            if(x.num==a[maxtop]&&x.pla!=m)
                maxtop++, num++;
            else if(x.num==a[maxtop]&&x.pla==m)
                break;
            else
                Q.push(x);
        }
        cout<<num<<endl;
    }
    return 0;
}
