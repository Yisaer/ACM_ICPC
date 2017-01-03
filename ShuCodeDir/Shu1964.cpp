//  main.cpp
//  SHU 1964
//
//  Created by 高松 on 16/1/19.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
int const INF = 0x3f3f3f3f;
#include <algorithm>

int const Maxn = 105;
int dp[Maxn][Maxn];
int a[Maxn];
int b[Maxn];
int c[Maxn];
int id[Maxn];

bool cmp(int A,int B){
    return b[A]<b[B];
}

int main(int argc, const char * argv[]) {
   
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m,e;
        scanf("%d%d%d",&n,&m,&e);
        for(int i=0;i<=m;i++)
            for(int j=0;j<=e;j++)
                dp[i][j]=-INF;
        dp[0][0]=0;
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
            id[i]=i;
        }
        sort(id,id+n,cmp);
        for(int d=0;d<n;d++){
            int i=id[d];
            for(int j=0;j<m;j++){
                for(int k=0;k<e;k++){
                    if(dp[j][k]>=0){
                        dp[min(j+b[i], m)][min(k+a[i], e+1)]=max(dp[min(j+b[i], m)][min(k+a[i], e+1)],dp[j][k]+c[i]);
                    }
                    
                }
            }
            
        }
        int ans = -INF;
        for(int i=0;i<=e;i++)
            ans = max(dp[m][i],ans);
        if(ans==-INF)
            printf("Sad Yaoge!\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}

