//***
//***Dij 邻接表(向量）

#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;


int const Maxn = 1000+5;
int const INF = 0x3f3f3f3f;
vector<int> G[Maxn]; //G[x]为点x所指向的点集
vector<int>GW[Maxn]; // G[x]的每个点得距离
int vis[Maxn];
int dis[Maxn];
int n;
int S,T;

void init(){
    for(int i=0;i<n;i++){
        G[i].clear();
        GW[i].clear();
    }
        memset(vis,0,sizeof(vis));
        memset(dis,INF,sizeof(dis));
    
}

void add_edge(int u,int v,int w){
    G[u].push_back(v);
    GW[u].push_back(w);
}

void dij(){
    dis[S]=0;
    for(int i=0;i<n;i++){
        int x;
        int Min=INF;
        for(int j=0;j<n;j++){
            if(!vis[j]&&dis[j]<=Min){
                x=j;
                Min=dis[j];
            }
        }
        vis[x]=1;
        for(int j=0;j<(int)G[x].size();j++){
            int y=G[x][j];
            int w=GW[x][j];
            dis[y]=min(dis[y],dis[w]+w);
        }
        
    }
    
}






int main (){

}