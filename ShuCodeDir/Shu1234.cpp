//  main.cpp
//  能量项链
//
//  Created by 高松 on 15/11/30.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
int const Max=200;
#include <cstring>
int dp[Max][Max];
int a[Max];


int main(int argc, const char * argv[]) {
    int n;
    while(cin>>n)
    {
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            a[i+n]=a[i];
        }
        memset(dp,0,sizeof(dp));
        long long Max=0;
        for(int i=2;i<n+n;i++)
        {
            for(int j=i-1;j>=1&&i-j<n;j--)
            {
                for(int k=j;k<i;k++)
                {
                    dp[j][i]=max(dp[j][i],dp[j][k]+dp[k+1][i]+a[j]*a[k+1]*a[i+1]);
                    if(dp[j][i]>Max)
                        Max=dp[j][i];
                }
                
            }
        }
        cout<<Max<<endl;
    }
    
    
    return 0;
}
