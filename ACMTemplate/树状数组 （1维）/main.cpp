//
//  main.cpp
//  树状数组 （1维）
//
//  Created by 高松 on 16/1/2.
//  Copyright © 2016年 yisa. All rights reserved.
//
#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#define ll long long
ll N;
int const Maxn =1e5+10;
ll a[Maxn];

ll lowbit(ll x){
    return x&(-x);
}

void  update(ll x, ll num){
    while(x<=N){
        a[x]+=num;
        x+=lowbit(x);
    }
    
}


ll getSum(ll x){
    ll sum = 0;
    while(x>0){
        sum+=a[x];
        x-=lowbit(x);
    }
    return sum;
}


//树状数组区域更新
//先用一个初始数组来存储一开始的每个节点的值
//再用a数组存储每次区域的变化情况
//这样每次查询所求的节点[x]的值则为b[x]+getSum(x)两者之和
//树状数组更新方法
//若区域x,y每个数同时加z
//则update(x,z) 然后update(y+1,-z)


/*
ll q;
while(scanf("%lld%lld",&N,&q)==2){
    memset(a,0,sizeof(a));
    for(int i=1;i<=N;i++){
        ll val;
        scanf("%lld",&val);
        b[i]=val;
    }
    while(q--){
        ll x,y,z;
        int c;
        scanf("%d",&c);
        if(c==1){
            scanf("%lld%lld%lld",&x,&y,&z);
            update(x,z);
            update(y+1,-z);
        }
        else{
            scanf("%lld",&x);
            printf("%lld\n",b[x]+getSum(x));
            
        }
    }
    
}
*/




int main (){}
