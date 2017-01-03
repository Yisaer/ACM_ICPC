//  main.cpp
//  SHU1941
//
//  Created by 高松 on 16/2/29.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <vector>
#define ll long long 

int  dp[100];
vector<int> v;


void exgcd(ll a,ll mod, ll &d,ll&x,ll&y){
    if (!mod) {d = a; x = 1; y = 0;}
    else {
        exgcd(mod, a % mod, d, y, x);
        y -= x * (a / mod);
    }
}


ll inv(ll a, ll mod ){
    ll x,y,d;
    exgcd(a,mod,d,x,y);
    return d == 1 ? (x + mod) % mod : -1;
}

ll cal(int l,int r,int k,int step){
    ll res= 1;
    for(int i=l;i<=r;i++){
        int tmp = i;
        for(int j=0;j<v.size();j++){
            int y = v[j];
            while(tmp%y==0){
                dp[j]+=step;
                tmp/=y;
            }
        }
        res = res* (ll) tmp %k;
        
    }
    return res%k;
}


ll Quick_Pow(ll base ,ll index,int mod){
    ll  t = 1;
    for(;index;index>>=1,base=(base*base)%mod){
        if(index&1) t = (t*base)%mod;
    }
    return t%mod;
}

ll solve(int n,int m,int k){
    memset(dp,0,sizeof(dp));
    v.clear();
    int mod = k;
    for(int i=2;i*i<=mod ;i++){
        if(mod%i==0){
            while(mod%i==0){
                mod/=i;
            }
            v.push_back(i);
        }
    }if(mod!=1) v.push_back(mod);
    ll ans = cal(n-m+1,n,k,1);
    ll FenMu = cal(2,m,k,-1);
    for(int j = 0;j<v.size();j++){
        ans = (ans* (Quick_Pow(v[j],dp[j],k)%k))%k;
    }
    ans = ((ans* inv(FenMu,k)) %k+k)%k;
    return ans;
}


int main(int argc, const char * argv[]) {
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        int k;
        scanf("%d%d%d",&n,&m,&k);
        printf("%lld\n",solve(n,m,k));
        
    }
}
