//  main.cpp
//  SHU1932 树链
//
//  Created by 高松 on 15/12/27.
//  Copyright © 2015年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
int const Maxn = 100+5;
vector<int> G[Maxn];
int par[Maxn];
int vis[Maxn];
int s,t;
int ans [Maxn];

void bfs(){
    queue<int> q;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        int x =q.front();
        q.pop();
        if(x==t){
            return;
        }
        for(int i=0;i<G[x].size();i++){
            int next = G[x][i];
            if(vis[next]==1)continue;
            vis[next]=1;
            par[next]=x;
            q.push(next);
        }
    }
    
}

int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    while(T--){
        int N,Q;
        cin>>N>>Q;
        for(int i=0;i<Maxn;i++)
            G[i].clear();
        for(int i=0;i<N-1;i++){
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
    
        while(Q--){
            memset(par,0,sizeof(par));
            memset(vis,0,sizeof(vis));
            cin>>s>>t;
            bfs();
            stack<int> s;
            s.push(t);
            int x =par[t];
            while(x!=0){
                s.push(x);
                x=par[x];
            }
            int tmp=0;
            while(!s.empty()){
                int x =s.top();
                s.pop();
                ans[tmp++]=x;
            }
            for(int i=0;i<tmp;i++)
            {
                if(i) cout<<" ";
                cout<<ans[i];
            }
            cout<<endl;
            
            
        }
        
        
        
    }
    
    
    return 0;
}
