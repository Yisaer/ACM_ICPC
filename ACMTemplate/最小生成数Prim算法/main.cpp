//
//  main.cpp
//  最小生成数Prim算法
//
//  Created by 高松 on 16/1/2.
//  Copyright © 2016年 yisa. All rights reserved.
//
//
//
//Prim算法简单介绍：
//  将所得的点集与边集合组合成一颗最小生成树，首先先随机取一个节点，将这个节点放入一个集合中，这个集合所存放的元素即为已经放入最小生成树中的点的集合中，所以当放入的边的数量为（n-1）或者集合中的元素的数量为n时 最小生成树便生成了。 将集合中的点所有的边的权值进行比较，对于u,v,w u为集合内的点，v为集合外的点，w为边（u,v)所对应的权值，我们每次搜索w权值最小的边，然后将点v放入集合中，这项操作循环n-1次即可


#include <iostream>
using namespace std;
#include <cstring>
int const Maxn =10+5;
int G[Maxn][Maxn];
int vis[Maxn];
int low[Maxn];
int n,m;
int const Max =0x3f3f3f3f;
int ans;


void prim(){
    vis[1]=1;
    int pos =1;
    int Min;
    int num=0;
    for(int i=1;i<=n;i++){
        if(i!=pos) low[i]=G[pos][i];
    }
    while(num<m-1){
        Min=Max;
        for(int i=1;i<=n;i++){
            if(vis[i]==0&&Min>low[i])
                Min=low[i],pos=i;
        }
        ans+=Min;
        num++;
        vis[pos]=1;
        for(int i=1;i<=n;i++){
            if(vis[i]==0&&low[i]>G[pos][i])
                low[i]=G[pos][i];
        }
        
    }
    
}

int main(int argc, const char * argv[]) {
    
    while(cin>>n>>m){ //n为点的个数 m为边的个数
        ans = 0;
        memset(vis,0,sizeof(vis));
        memset(G,Max,sizeof(G));
        for(int i=0;i<m;i++){
            int a,b,d;
            cin>>a>>b>>d;
            G[a][b]=d;
            G[b][a]=d;
            
        }
        prim();
        cout<<ans<<endl;//输出生成最小树所需的边的最小的权值和
    }
    
    return 0;
}