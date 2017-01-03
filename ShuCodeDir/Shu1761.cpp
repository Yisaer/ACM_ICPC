#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>

#define MEM(A,val) memset(A,val,sizeof(A))
#define PB(X) push_back(X)


int const Maxn = 200;
vector<int>G[Maxn];

struct query{
    int x,y;
    int id;
};
vector<query> Q;
int par[Maxn];
int vis[Maxn];
int ans[Maxn];
int find( int x){
    return (par[x]==-1)?(x):(par[x]=find(par[x]));
}

void dfs(int cur,int Par){
    vis[cur]=1;
    for(int i=0;i<Q.size();i++){
        if(Q[i].x==cur&&vis[Q[i].y]==1){
            ans[Q[i].id]=find(Q[i].y);
        }
    }
    for(int i=0;i<G[cur].size();i++){
        dfs(G[cur][i],cur);
    }
    par[cur]=Par;
}

int main (){
    int T;
    cin>>T;
    int cas = 0;
    while(T--){
        cas++;
        for(int i=0;i<Maxn;i++)
            G[i].clear();
        Q.clear();
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            int x,y;
            cin>>x>>y;
            G[x].PB(y);
        }
        int m;
        cin>>m;
        for(int i=1;i<=m;i++){
            query t1,t2;
            int p,q;
            cin>>p>>q;
            t1.x=p;
            t1.y=q;
            t1.id=i;
            t2.x=q;
            t2.y=p;
            t2.id=i;
            Q.PB(t1);
            Q.PB(t2);
        }
        MEM(par,-1);
        MEM(vis,0);
        dfs(0,-1);
        printf("Case %d:\n",cas);
        for(int i=1;i<=m;i++){
            if(i-1)cout<<" ";
            cout<<ans[i];
        }cout<<endl;
        
    }
}

