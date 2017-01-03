#include <cstdio>
#include <iostream>
using namespace std;
long long num[102000];
struct node
{
    int n;
    long long Max;
    long long Min;
};
node t[408000];
void creat(int x, int left, int right)
{
    if (left == right)      //说明到了最底层的叶子节点
    {
        t[x].Max = num[left];
        t[x].Min = num[right];
        t[x].n = 1;
        return;
    }
    creat(x * 2, left, (left + right) / 2);     //建立左子树
    creat(x * 2 + 1, (left + right) / 2 + 1, right);   //建立右子树
    t[x].Max = max(t[x * 2].Max , t[x * 2 + 1].Max);
    t[x].Min = min(t[x * 2].Min , t[x * 2 + 1].Min);
    t[x].n = t[x*2].n + t[x*2+1].n;
}
int count(int x, int left, int right, int lb, int rb,long long k)
//left和right是查询区间，lb和rb是目标区间。
{
    if (left == lb && right == rb )     //正好在这个区间
    {
        if (t[x].Max < k) {
            return t[x].n;
        }
        else if (t[x].Min >= k)
        {
            return 0;
        }
        else
            return count(x * 2, left, (left + right) / 2, lb, (left + right) / 2,k) + count(x * 2 + 1, (left + right) / 2 + 1, right, (left + right) / 2 + 1, rb,k);
    }
    if (rb <= (left + right) / 2)        //要找的区间在左子树
    {
        return count(x * 2, left, (left + right) / 2, lb, rb,k);
    }
    else if (lb > (left + right) / 2)        //要找的区间在右子树
    {
        return count(x * 2 + 1, (left + right) / 2 + 1, right, lb, rb,k);
    }
    else        //说明要找的区间在这个节点的两个子节点中都有。
    {
        return count(x * 2, left, (left + right) / 2, lb, (left + right) / 2,k) + count(x * 2 + 1, (left + right) / 2 + 1, right, (left + right) / 2 + 1, rb,k);
    }
}
int main(void)
{
    int t;
    scanf("%d",&t);
    while (t--) {
        int n,q;
        scanf("%d%d",&n,&q);
        for (int i = 1; i<=n; i++) {
            scanf("%lld",&num[i]);
        }
        creat(1, 1, n);
        while (q--) {
            int l,r,sum;
            long long k;
            scanf("%d%d%lld",&l,&r,&k);
            sum = count(1, 1,n,l,r,k);
            printf("%d\n",sum);
        }
    }
    return 0;
}
