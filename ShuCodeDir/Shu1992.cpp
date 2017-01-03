//  main.cpp
//  shuye
//
//  Created by 高松 on 16/2/22.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include<iostream>
using namespace std;
#include <cstring>

const int MAXN = 510;
int sum[MAXN],path[MAXN],dp[MAXN][MAXN];

int main(){
    int m,k,i,j,v,ca,p,t;
    int cas = 0;
    while(cin>>m>>k){
        cas++;
        for(sum[0]=0,i=1;i<=m;i++){
            scanf("%d",&p);
            sum[i]=sum[i-1]+p;
        }
        memset(dp,-1,sizeof(dp));
        for(dp[0][0]=0,i=1;i<=m;i++)
            for(j=1;j<=i && j<=k;j++){
                if(j==1) dp[i][j]=sum[i];
                else
                    for(v=j-1;v<=i-1;v++){
                        t=max(dp[v][j-1],sum[i]-sum[v]);
                        if(dp[i][j]==-1 || t<=dp[i][j])
                            dp[i][j]=t;
                    }
            }
        for(i=m,j=k-1,p=0;i>=1;i--){
            p+=sum[i]-sum[i-1];
            if(p>dp[m][k] || i<=j){
                path[j--]=i+1;
                p=sum[i]-sum[i-1];
            }
        }
        printf("Case %d: ",cas);
        cout<<dp[m][k]<<endl;
    }
    return 0;
}
