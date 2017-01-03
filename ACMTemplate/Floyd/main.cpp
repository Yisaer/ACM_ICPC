//
//  main.cpp
//  Floyd
//
//  Created by 高松 on 16/1/1.
//  Copyright © 2016年 yisa. All rights reserved.



//  Floyd算法不能记录路径


#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int const Maxn = 1+5;
int const INF  = 0x3f3f3f3f;
int G[Maxn][Maxn];
int S,T,n;

void init(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) G[i][j]=0;
            else
                G[i][j]=INF;
        }
        
    }
}

void add_edge(int u,int v,int w){
    G[u][v]=min(w,G[u][v]);
}

void Floyd(){
    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
            G[i][j] = min(G[i][j],G[i][k] + G[k][j]);
            }
        }
    }
}

//则从起点到终点的最短路径为G[S][T] 若G[S][T]为INF 说明没有路径






int main(){
  
    n=6;
      init();
    for(int i=0;i<11;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,w);
    }

    Floyd();
    
    for(int i=0;i<n+1;i++){
        
        for(int j=0;j<n+1;j++){
            if(i==0&&j==0){
                cout<<"  "; continue;
            }
            if(i*j==0){
                if(i==0){
                    cout<<j-1<<"   ";
                    continue;
                }
                cout<<i-1<<"  ";
                continue;
            }
            if(G[i-1][j-1]<999){
                cout<<G[i-1][j-1]<<"  ";
            }
            else cout<<"wu  ";
        }
        cout<<endl;
    }
    
}


