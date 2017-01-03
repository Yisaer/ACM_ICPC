#include <iostream>

using namespace std;
int const  MOD = 100000007;
#define ll long long



struct matrix
{
    long long  m[2][2];
}ans, base;

matrix multi(matrix a, matrix b)
{
    matrix tmp;
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < 2; ++j)
        {
            tmp.m[i][j] = 0;
            for(int k = 0; k < 2; ++k)
                tmp.m[i][j] = (tmp.m[i][j] %MOD + (a.m[i][k] * b.m[k][j])%MOD) % MOD;
        }
    }
    return tmp;
}
int fast_mod(ll n)  // 求矩阵 base 的  n 次幂
{

    base.m[0][1] = 8;
    base.m[0][0] = base.m[1][0] = 1;
    base.m[1][1] = 0;
    ans.m[0][0] = ans.m[1][1] = 1;  // ans 初始化为单位矩阵
    ans.m[0][1] =ans.m[1][0] = 0;

    while(n)
    {
        if(n & 1)  //实现 ans *= t; 其中要先把 ans赋值给 tmp，然后用 ans = tmp * t
        {
            ans = multi(ans, base);
        }
        base = multi(base, base);
        n >>= 1;
    }
    return ans.m[0][1]+ans.m[0][0];
}

int main()
{
    long long n;
    while(cin>>n)
    {
        if(n<=2){
            cout<<1<<endl;
            continue;
        }
        int val = fast_mod(n-2);
        cout<<((val%MOD)+MOD)%MOD<<endl;
        continue;
    }
    return 0;
}
