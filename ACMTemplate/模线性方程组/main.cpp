
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>

using namespace std;

#define LL long long
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
int n;
void ex_gcd(LL a, LL b, LL &d, LL &x, LL &y)
{
    if (!b) {d = a, x = 1, y = 0;}
    else
    {
        ex_gcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}
LL ex_crt(LL *m, LL *r, int n)
{
    LL M = m[1], R = r[1], x, y, d;
    for (int i = 2; i <= n; ++i)
    {
        ex_gcd(M, m[i], d, x, y);
        if ((r[i] - R) % d) return -1;
        x = (r[i] - R) / d * x % (m[i] / d);
        R += x * M;
        M = M / d * m[i];
        R %= M;
    }
    return R > 0 ? R : R + M;
}
int main()
{
    while (~scanf("%d",&n))
    {
        //m为除数，r为余数
        LL m[maxn], r[maxn];
        for (int i = 1; i <= n; ++i)
            scanf("%lld%lld", &m[i], & r[i]);
        printf("%lld\n",ex_crt(m,r,n));
    }
    return 0;
}


