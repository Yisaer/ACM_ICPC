//  main.cpp
//  SHU1944 GCD
//
//  Created by 高松 on 15/12/21.
//  Copyright © 2015年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstdio>
int const Maxn= 100000+10;
#define ll long long

struct X{
    ll l,r;
    ll num;
}Node[Maxn<<2];

ll gcd(ll a, ll b){
    ll c;
    while(b!=0){
        c=b;
        b=a%b;
        a=c;
    }
    return a;
}

void set_up(ll rt){
   // cout<<"rt="<<rt<<endl;
    Node[rt].num=gcd(Node[rt*2].num,Node[rt*2+1].num);
  //  cout<<"num="<<Node[rt].num<<endl;
}


void init (ll L, ll R, ll rt){
    Node[rt].l=L;
    Node[rt].r=R;
    if(L==R){
        scanf("%lld",&Node[rt].num);
        //cout<<"num="<<Node[rt].num<<endl;
        return;
    }
    ll mid =(Node[rt].l+Node[rt].r)/2;
    init (L ,mid, rt*2);
    init (mid+1,R ,rt*2+1);
    set_up(rt);
}

ll query (ll L, ll R ,ll rt){
    if(L==Node[rt].l&&Node[rt].r==R)
        return Node[rt].num;
    ll mid =(Node[rt].l+Node[rt].r)/2;
    if(R<=mid)
        return query (L,R ,rt*2);
    else if(L>mid)
        return query (L,R,rt*2+1);
    else
    return gcd(query(L,mid,rt*2),query(mid+1,R,rt*2+1));
}

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    ll n ,q;
    while(scanf("%lld%lld",&n,&q)==2){
        init(1,n,1);
        while(q--){
            ll a,b;
            scanf("%lld%lld",&a,&b);
            printf("%lld\n",query(a,b,1));
        }
        
    }
    
    return 0;
}
