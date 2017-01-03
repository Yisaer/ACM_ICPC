#include <cstdio>
#include <cstring>
int const Maxn = 105;

using namespace std;
int high[Maxn];
int L[Maxn];
int R[Maxn];

int main()
{
    int n;
    while(cin>>n){
        
        memset(R,0,sizeof(R));
        memset(L,0,sizeof(L));
        
    for(int i = 0; i < n; i++)
        scanf("%d", &high[i]);
    for(int i = 0; i < n; i++)
    {
        L[i] = 1;
        for(int j = 0;j < i; j++)
        {
            if(high[j] <high[i] && L[j] > L[i] - 1)   // 找出左边最长递增子序列
                L[i] = L[j] + 1;
        }
    }
    for(int i = n-1; i >= 0; i--)
    {
        R[i] = 1;
        for(int j = n-1;j > i; j--)
        {
            if(high[j] < high[i] && R[j] > R[i] - 1)  // 找出右边最长递减子序列
                R[i] = R[j] + 1;
        }
    }
    int max = 0;
    for(int i = 0; i < n; i++)
    {
        if(max < L[i] + R[i] - 1)
            max = L[i] + R[i] - 1;  // 寻找最多合唱人数
    }
    printf("%d\n",n - max);
    }
    return 0;
}

