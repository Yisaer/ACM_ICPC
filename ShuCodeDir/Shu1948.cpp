//  main.cpp
//  SHUEE
//
//  Created by 高松 on 15/12/27.
//  Copyright © 2015年 yisa. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
#include <vector>
#include <cstdio>
#define PII pair<int,int>
int const Maxn = 40005;
vector<PII> G[Maxn];
#define MP make_pair
#define X first
#define Y second
#define PB(x) push_back(x)
int F [Maxn];

void dfs(int cur,int par){
    for(int i=0;i<G[cur].size();i++){
        int v=G[cur][i].X;
        int d=G[cur][i].Y;
        if(v==par) continue;
        F[v]=F[cur]^d;
        dfs(v,cur);
    }
}

int main (){
    int T;
    scanf("%d",&T);
    int cas = 0;
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            G[i].clear();
        }
        for(int i=1;i<=n-1;i++){
            int u,v,d;
            scanf("%d%d%d",&u,&v,&d);
            G[u].PB(MP(v,d));
            G[v].PB(MP(u,d));
        }
        memset(F,0,sizeof(F));
        F[1]=1;
        dfs(1,0);
        printf("Case %d:\n",++cas);
        while(m--){
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%d\n",F[a]^F[b]);
            
        }
    }


}
