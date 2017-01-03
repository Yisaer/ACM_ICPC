//  main.cpp
//  SHU1785
//
//  Created by 高松 on 16/1/3.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;
#include <cstring>
#include <algorithm>
#include <cmath>

int const Maxn =25;
int a[Maxn];
int b[Maxn];
int vis[Maxn];
#define ll long long
#define MEM(a) memset(a,0,sizeof(a))

int gcd(int x,int y)
{
    if (y == 0) {
        return x;
    }
    else
        return gcd(y,x%y);
}
int lcm(int x,int y)
{
    return x*y/gcd(x,y);
}

int main (){
    ll n ;
    int m;
    while(cin>>n>>m){
        MEM(a);
        MEM(b);
        MEM(vis);
        bool flag =false;
        for(int i =0 ;i<m;i++)
        {
            cin>>a[i];
            if(a[i]==1)
            {
                flag =true;
            }
        }
        if(flag)
        {
            cout<<n<<endl;
            continue;
        }
      
        for(int i=1;i<m;i++)
            for(int j=0;j<i-1;j++){
                if((a[i]%a[j])==0){
                    vis[i]=1;
                }
            }
        int len = 0;
        for(int i=0;i<m;i++)
            if(vis[i]==0)
                b[len++]=a[i];
        ll ans = 0;
        for (int i = 1; i<(1<<len); i++) {
            int val = 1;
            int cnt = 0;
            for (int j = 0; j<len; j++) {
                if ((1<<j)&i) {
                    val = lcm(val,b[j]);
                    cnt++;
                }
            }
            //cout<<(pow(-1, cnt-1)*val)<<' '<<(int)pow(-1, cnt-1)*n/val<<' ';
            ans += (long long)pow(-1, cnt-1)*n/val;
        }
        
        
        cout<<ans<<endl;
        
    }

}
