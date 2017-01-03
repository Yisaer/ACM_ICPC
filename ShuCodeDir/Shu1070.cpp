//  main.cpp
//  ANS
//
//  Created by 高松 on 15/10/13.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#define ll long long

int dp[999999];
#include <cstring>


int main ()
{
    int n;
    while(cin>>n,n)
    {
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        dp[2]=2;
        dp[3]=4;
        for(int i=4;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
            
        }
        cout<<dp[n]<<endl;
    }



}
