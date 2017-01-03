//  main.cpp
//  SHU1364 导弹来袭
//
//  Created     by 高松 on 15/12/1.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>
int n;
int h[31];
int vis[31];
char s [160];
int dp[160];
int DP[160];
int par[160];
int MaxIndex;

int main(int argc, const char * argv[]) {
    while(cin>>n)
    {
        int Max=1;
        int MMax=1;
        memset(h,0,sizeof(h));
        int num=0;
        int index=n;
        for(int i=0;i<n;i++)
            cin>>h[i];
        
      // cout<<"index="<<index<<endl;
    
        for(int i=0;i<index;i++)
        {
            dp[i]=1;
            DP[i]=1;
            for(int j=0;j<i;j++)
            {
                if(h[j]>h[i])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                    if(dp[i]>Max)
                        Max=dp[i];
                }
                else if(h[j]<h[i])
                {
                    DP[i]=max(DP[i],DP[j]+1);
                    if(DP[i]>MMax)
                        MMax=DP[i];
                    
                }
                
            }
            
        }
        cout<<MMax<<endl;
    }
    return 0;
}
