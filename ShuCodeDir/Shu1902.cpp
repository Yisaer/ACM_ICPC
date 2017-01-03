//  main.cpp
//  小6的多米诺骨牌，自写版本
//
//  Created by 高松 on 15/11/26.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
int const Max=150;
int p[Max];
int h[Max];
int dp[Max];

int main(int argc, const char * argv[]) {
    
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>p[i]>>h[i];
        }
        dp[0];
        for(int i=1;i<=n;i++)
        {
            dp[i]=99999999;
        }
        for(int i=1;i<=n;i++)
        {
            //head;
            int R=p[i]+h[i];
            for(int j=i;j<=n;j++)
            {
                if(p[j]<R)
                {
                    //beituidao
                    dp[j]=min(dp[j],dp[i-1]+1);
                    R =max(R,p[j]+h[j]);
                }
                else
                {
                    //碰不到右边了 退出 进行自右向左
                    break;
                }
                
            }
            int L=p[i];//bei tui dao wei zhi
            for(int j=i;j<=n;j++)
            {
                if(p[j]-h[j]<L)
                {
                    dp[j]=min(dp[j],dp[i-1]+1);
                    L=p[j];
                    
                }
                
            }
            
            
            
        }
        cout<<dp[n]<<endl;
        
    }
    return 0;
}

