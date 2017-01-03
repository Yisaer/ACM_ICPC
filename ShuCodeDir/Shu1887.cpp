//  main.cpp
//  SHU1887 变着法的求个和
//
//  Created by 高松 on 15/12/14.
//  Copyright © 2015年 yisa. All rights reserved.
//
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 900010;
#define lson l, mid, root<<1
#define rson mid+1, r, root<<1|1
struct node
{
    int l, r;
    LL sum, odd, add;
}a[N<<2];
void PushUp(int root)
{
    a[root].sum = a[root<<1].sum + a[root<<1|1].sum;
    a[root].odd = a[root<<1].odd + a[root<<1|1].odd;
}
void PushDown(int len, int root)
{
    if(a[root].add)
    {
        a[root<<1].add += a[root].add;
        a[root<<1|1].add += a[root].add;
        a[root<<1].sum += LL(len - (len>>1)) * a[root].add;
        a[root<<1|1].sum += LL(len>>1) * a[root].add;
        if(a[root].add % 2 == 1)
        {
            a[root<<1].odd = len - (len>>1) - a[root<<1].odd;
            a[root<<1|1].odd = (len>>1) - a[root<<1|1].odd;
        }
        a[root].add = 0;
    }
}
void build_tree(int l, int r, int root)
{
    a[root].l = l;
    a[root].r = r;
    a[root].add = 0;
    a[root].odd = 0;
    if(l == r)
    {
        scanf("%lld",&a[root].sum);
        if(a[root].sum % 2 == 1)
            a[root].odd = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build_tree(lson);
    build_tree(rson);
    PushUp(root);
}
void update(int l, int r, int root, LL k)
{
    if(l <= a[root].l && r >= a[root].r)
    {
        a[root].add += k;
        a[root].sum += LL(a[root].r - a[root].l + 1) * k;
        if(k % 2 == 1)
            a[root].odd = (a[root].r - a[root].l + 1) - a[root].odd;
        return;
    }
    PushDown(a[root].r - a[root].l + 1, root);
    int mid = (a[root].l + a[root].r) >> 1;
    if(l <= mid) update(l, r, root<<1, k);
    if(r > mid) update(l, r, root<<1|1, k);
    PushUp(root);
}
LL Query(int l, int r, int root, char ch)
{
    if(l <= a[root].l && r >= a[root].r)
    {
        if(ch == 'Q') return a[root].odd;
        else if(ch == 'S') return a[root].sum;
    }
    PushDown(a[root].r - a[root].l + 1, root);
    LL ans = 0;
    int mid = (a[root].l + a[root].r) >> 1;
    if(l <= mid) ans += Query(l, r, root<<1, ch);
    if(r > mid) ans += Query(l, r, root<<1|1, ch);
    return ans;
}
int main()
{
    int n, m, i, x, y;
    LL z;
    char ch[5];
    while(~scanf("%d%d",&n,&m))
    {
        build_tree(1, n, 1);
        while(m--)
        {
            int val;
            scanf("%d",&val);
            if(val == 1)
            {
                scanf("%d%d%lld",&x,&y,&z);
                update(x, y, 1, z);
            }
            else
            {
                ch[0]='S';
                scanf("%d%d",&x,&y);
                printf("%lld\n", Query(x, y, 1, ch[0]));
            }
        }
    }
    return 0;
}
