//  main.cpp
//  C
//
//  Created by 高松 on 15/12/6.
//  Copyright © 2015年 伊萨. All rights reserved.
//
 
#include <iostream>
using namespace std;
 
int fib[99999];
 
int dp[10001];
 
 
int main(int argc, const char * argv[]) {
    dp[1]=0;
    dp[2]=1;
    int a,b;
    for(int i=3;i<=10000;i++)
    {
        for(a=1,b=i-1;a<=b;a++,b--)
        {
            dp[i]=max(dp[i],dp[a]&dp[b]);
            if(dp[i]==1)
                break;
        }
         
    }
     
     
    int T;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        if(dp[n]||dp[m])
        {
            cout<<"yaoge"<<endl;
             
        }
        else
            cout<<"xyiyy"<<endl;
        
    }
     
    return 0;
}
