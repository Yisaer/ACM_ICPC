//  main.cpp
//  QY
//
//  Created by 高松 on 16/3/28.
//  Copyright © 2016年 yisa. All rights reserved.
//
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long

ll gcd(ll a, ll b)
{
    if(a>=b)
    {
        if(b==0) return a;
        return gcd(b,a%b);
        
    }
    else
    {
        if(a==0)  return b;
        return gcd(b%a,a);
        
    }
    
}

int main ()
{
    int T;
    cin>>T;
    ll ans;
    while(T--)
    {
        ans=1;
        ll a=1;
        ll b=1;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            //   cout<<"a="<<a<<endl;
            
//            ans=a*b/gcd(a,b);
//            b=ans;
            ans=a*b/gcd(a,b);
            b=ans;
            
            
        }
        cout<<ans<<endl;
        
    }

}
