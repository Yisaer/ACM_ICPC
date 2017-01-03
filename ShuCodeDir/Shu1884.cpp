//  main.cpp
//  SHU1883 求个和  树状数组
//
//  Created by 高松 on 15/12/21.
//  Copyright © 2015年 yisa. All rights reserved.
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
int main(int argc, const char * argv[]) {
    ll q;
    while(scanf("%lld%lld",&N,&q)==2){
        memset(a,0,sizeof(a));
        for(int i=1;i<=N;i++){
            ll val;
            scanf("%lld",&val);
            update(i,val);
        }
        while(q--){
            ll a,b,c;
            scanf("%lld%lld%lld",&c,&a,&b);
            if(c==1)
                update(a,b);
            else
                printf("%lld\n",getSum(b)-getSum(a-1));
        }
        
    }
    
    return 0;
}

