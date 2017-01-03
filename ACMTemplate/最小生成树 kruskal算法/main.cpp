//
//  main.cpp
//  最小生成树 kruskal算法
//
//  Created by 高松 on 16/1/1.
//  Copyright © 2016年 yisa. All rights reserved.
//


#include <iostream>
using namespace std;
#include <vector>
#include <cstring>
#include <algorithm>
#define PII pair<int,int>
#define MP(X,Y)  make_pair(X,Y)
#define PB(X)  push_back(X)
struct edge { int u ; int v; int cost ;};
vector <edge> G;
#define IT iterator
int const Maxn =1000+5;
int V,E; //点的数量，边的数量


bool cmp( edge a, edge b){
    return a.cost<b.cost;
}

int par[Maxn];
int Rank[Maxn];

void init (int n){
    G.clear();
    memset(par,0,sizeof(par));
    memset(Rank,0,sizeof(Rank));
    for(int i=1;i<=n;i++)
    {
        par[i]=i;
        Rank[i]=0;
    }
}

int find_set(int x){
    if(par[x]==x)
        return x;
    else
        return  find_set(par[x]);
}

void union_set(int x,int y){
    x=find_set(x);
    y=find_set(y);
    if(Rank[x]>Rank[y]){
        par[y]=x;
        
    }else{
        par[x]=y;
        if(Rank[x]==Rank[y])
            Rank[y]++;
    }
    
}

bool ISame_set(int x,int y){
    return find_set(x)==find_set(y);
}


int kruskal(int n){
    init(n);
    sort(G.begin(),G.end(),cmp);
    int num = 0;
    vector<edge>::IT it;
    int sum = 0;
    for( it=G.begin();it!=G.end()&&num!=n-1;it++){
        int u =it->u;
        int v =it->v;
        int d =it->cost;
        if(!ISame_set(u,v)){
            //   cout<<"u="<<u<<" v="<<v<<" d="<<d<<endl;
            union_set(u,v);
            sum+=d;
            num++;
        }
    }
    return sum;//sum为最小权值
    
}
//加边
void add_edge(int u,int v,int w){
    
    edge X;
    X.u=u;
    X.v=v;
    X.cost=w;
    G.PB(X);
}


int main(int argc, const char * argv[]) {
    

    return 0;
}

