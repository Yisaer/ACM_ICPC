//
//  main.cpp
//  埃氏筛法
//
//  Created by 高松 on 16/1/6.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const long long maxn=10000007+10;
const long long maxp=700000;
int vis[maxn];//i是合数vis为1，i是素数，vis为0
long long prime[maxp];
void sieve(long long n){
    long long m=(long long)sqrt(n+0.5);
    memset(vis,0,sizeof(vis));
    vis[2]=0;
    for(long long i=3;i<=m;i=i+2){
        if(!vis[i])for(long long j=i*i;j<=n;j+=i)vis[j]=1;
        if(i*i>n)break;
    }
}
long long gen(long long n){
    sieve(n);
    long long c=1;
    prime[0]=2;
    for(long long i=3;i<=n;i=i+2)if(!vis[i])
        prime[c++]=i;
    return c;
}
int main()
{
    
    long long n,c;
    cin>>n;
    c=gen(n);
    cout<<"num="<<c<<endl;
    for(long long i=0;i<c;i++)
    {
        if(i)cout<<" ";
        printf("%lld",prime[i]);
    }
    cout<<endl;
    return 0;
}
