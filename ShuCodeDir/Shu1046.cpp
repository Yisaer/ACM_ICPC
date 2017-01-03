//  main.cpp
//  SHU1046 开心的金明
//
//  Created by 高松 on 15/12/1.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>


int const Max= 30;
int v[Max];
int w[Max];
int dp[30010];
int n,m;
#define max(a,b) (a>b?a:b)
//dp[i][j]=max(dp[i][j-1],dp[i][

int main(int argc, const char * argv[]) {
    while(cin>>n>>m)
    {
        memset(v,0,sizeof(v));
        memset(w,0,sizeof(w));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;i++)
        {
            cin>>v[i]>>w[i];
        }
        for(int i=0;i<m;i++)
            for(int j=n;j>=v[i];j--)
            {
                dp[j]=max(dp[j],dp[j-v[i]]+v[i]*w[i]);
                
            }
        cout<<dp[n]<<endl;
    }
    
    return 0;
}
