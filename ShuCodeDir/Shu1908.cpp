//  main.cpp
//  ANS
//
//  Created by 高松 on 15/10/13.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#define ll long long
#include <cstring>
#define ll long long
ll dp[100];


int main ()
{
    dp[1]=0;
    dp[2]=1;
    for(int i=3;i<=21;i++)
    {
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
    }
    int n;
    while(cin>>n)
        cout<<dp[n]<<endl;


}
