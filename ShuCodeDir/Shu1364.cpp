//  main.cpp
//  SHU1364 导弹来袭
//
//  Created by 高松 on 15/12/1.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>
int h[31];
int vis[31];
char s [160];
int dp[160];
int DP[160];
int par[160];
int MaxIndex;

int main(int argc, const char * argv[]) {
    while(cin>>s)
    {
        int Max=1;
        int MMax=1;
        memset(h,0,sizeof(h));
        int num=0;
        int len=strlen(s);
        int index=0;
        for(int i=0;i<=len;i++)
        {
            if(s[i]=='\0')
            {
                h[index++]=num;
                break;
                
            }
            if(s[i]!=',')
            {
                num=num*10+s[i]-'0';
            }
            else
            {
                h[index++]=num;
                num=0;
                
            }
        }
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
                else if(h[j]<=h[i])
                {
                    DP[i]=max(DP[i],DP[j]+1);
                    if(DP[i]>MMax)
                        MMax=DP[i];
                    
                }
                
            }
            
        }
        cout<<Max<<","<<MMax-1<<endl;
    }
    return 0;
}

