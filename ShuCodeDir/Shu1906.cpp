//  main.cpp
//  1906 磁带最优
//
//  Created by 高松 on 15/11/28.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>
#include <algorithm>

#include <cmath>
#define ll long long
struct x{
    int l;
    int k;
    double p;
    double cost;
    
}P[8019];


bool cmp(x a,x b)
{
    double A=a.p*a.l*1.0;
    double B=b.p*b.l*1.0;
    return A<B;
}

int main(int argc, const char * argv[]) {
   
    int n;
    while(cin>>n)
    {
        memset(P,0,sizeof(P));
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>P[i].l>>P[i].k;
            sum+=P[i].k;
        }
        for(int i=0;i<n;i++)
        {
            P[i].p=P[i].k*1.0/sum;
        }
       
        sort(P,P+n,cmp);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                P[i].cost+=P[j].p*P[j].l;
            }
            
        }
        double ans=0;
        
        
        for(int i=0;i<n;i++)
        {
            ans+=P[i].cost;
           
        }
        printf("%.4lf\n",ans);
    }
    
    
    return 0;
}
