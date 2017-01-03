//
//  main.cpp
//  容斥原理求解a-b中与n互质的个数
//
//  Created by 高松 on 16/1/6.
//  Copyright © 2016年 yisa. All rights reserved.
//


#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define LL long long
#define maxn 70

LL prime[maxn];
LL make_ans(LL num,int m)
{
    LL ans=0,tmp,i,j,flag;
    for(i=1;i<(LL)(1<<m);i++) //用二进制来1,0来表示第几个素因子是否被用到,如m=3，三个因子是2,3,5，则i=3时二进制是011，表示第2、3个因子被用到
    {
        tmp=1,flag=0;
        for(j=0;j<m;j++)
            if(i&((LL)(1<<j)))//判断第几个因子目前被用到
                flag++,tmp*=prime[j];
        if(flag&1)//容斥原理，奇加偶减
            ans+=num/tmp;
        else
            ans-=num/tmp;
    }
    return ans;
}

int main()
{
    int T,t=0,m;
    LL n,a,b,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&a,&b,&n);
        m=0;
        for(i=2;i*i<=n;i++) //对n进行素因子分解
            if(n&&n%i==0)
            {
                prime[m++]=i;
                while(n&&n%i==0)
                    n/=i;
            }
        if(n>1)
            prime[m++]=n;
        printf("Case #%d: %lld\n",++t,(b-make_ans(b,m))-(a-1-make_ans(a-1,m)));
    }
    return 0;
}