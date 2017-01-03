//  main.cpp
//  SHU1265
//
//  Created by 高松 on 16/1/2.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <algorithm>
int const INF =0x3f3f3f3f;
#define ll long long
int const Maxn= 10000+5;
bool stone[Maxn];
int  dp[Maxn];
int   dis[105];
#define min(a,b) (a<b?a:b)

int main(int argc, const char * argv[]) {
    int L;
    while(cin>>L){
        int S,T,n;
        scanf("%d%d%d",&S,&T,&n);
        memset(stone,0,sizeof(stone));
        memset(dis,0,sizeof(dis));
        memset(dp,INF,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            int pos;
            scanf("%d",&pos);
            dis[i]=pos;
        }
        sort(dis,dis+n+1);
        int ans = 0;
        if(S==T){
            for(int i=1;i<=n;i++){
               if(dis[i]%S==0)
                   ans++;
            }
            printf("%d\n",ans);
            continue;
        }else{
            int i,j;
            for(i=1,j=0;i<=n;i++){
               if(dis[i]-dis[i-1]>90)
                   j+=90;
                else
                    j+=dis[i]-dis[i-1];
                stone[j]=1;
            }
            int path = j+90;
            
            stone[0]=0;
            dp[0]=0;
            for(int i=1;i<=path;i++){
                dp[i]=INF;
                for(int j=S;j<=T;j++){
                    if(i<j) break;
                    dp[i]=min(dp[i],dp[i-j]+stone[i]);
                }
                
            }
            ans = dp[path];
            printf("%d\n",ans);
            continue;
        }
    }
    
    return 0;
}
