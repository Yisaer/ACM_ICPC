//  main.cpp
//  SHU1757 村村通工程
//
//  Created by 高松 on 15/12/29.
//  Copyright © 2015年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>
int const Maxn  = 200+5;
int G[Maxn][Maxn];
int vis[Maxn];
int dis[Maxn];
#define INF (0x3f3f3f3f)
int N,M;
int S,T;


void dij(){
    memset(dis,INF,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[S]=0;
    for(int i=0;i<N;i++){
        int x;
        int Min =INF;
        for(int j=0;j<N;j++){
            if(!vis[j]&&dis[j]<=Min){
                Min=dis[j];
                x=j;
            }
            
        }
        vis[x]=1;
        for(int j=0;j<N;j++){
            dis[j]=min(dis[j],dis[x]+G[x][j]);
        }
        
    }
    
    
}



int main(int argc, const char * argv[]) {
    
    
    while(cin>>N>>M){
        memset(G,INF,sizeof(G));
        for(int i=0;i<M;i++){
            int u,v,d;
            cin>>u>>v>>d;
            G[u][v]=d;
            G[v][u]=d;
        }
        cin>>S>>T;
        dij();
        if(dis[T]==INF)
            cout<<-1<<endl;
        else
            cout<<dis[T]<<endl;
        
    }
    
    
    return 0;
}
