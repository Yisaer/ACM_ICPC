//  main.cpp
//  test
//
//  Created by 高松 on 16/1/21.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)

typedef long long ll;

ll fac[100005];
void qfac(int n,int k){
    fac[1] = 1;
    REP2(i,2,n)
    fac[i] = fac[i-1]*i%k;
}
ll fast_mod(ll n,int m,int k){
    ll ans = 1;
    while(m){
        if(m&1) ans = ans*n%k;
        m>>=1;
        n = n*n%k;
    }
    return ans;
}
ll inv(ll n,int k){
    ll ans = fast_mod(n,k-2,k);
    return ans;
}

int main(){
    int m,n,k;
    int T;
    cin>>T;
    while(T--){
        cin>>m>>n>>k;
        memset(fac,0,sizeof(fac));
        qfac(m,k);
        //REP(i,10)cout<<fac[i]<<endl;
        cout<<fac[m]*inv(fac[n],k)%k*inv(fac[m-n],k)%k<<endl;
    }
    return 0;
}
