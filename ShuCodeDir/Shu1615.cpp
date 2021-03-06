#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;


int const Maxn = 1000+5;
int const INF = 0x3f3f3f3f;
int G[Maxn][Maxn];
int vis[Maxn];
int dis[Maxn]; //记录从起点到到终点的最短路径
int to[Maxn]; //路径记录 从起点走到终点
int S,T; //起点S 终点D
int n; //点得数量 标号从0一直到n-1
//初始化
void init(){
    memset(G,INF,sizeof(G));
    memset(vis,0,sizeof(vis));
    memset(dis,INF,sizeof(dis));
}

void add_edge(int u ,int v,int w){
    G[u][v]=min(G[u][v],w);
}

void Dij(){
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
        for(int j=0;j<n;j++){
            dis[j]=min(dis[j],dis[x]+G[x][j]);
            to[x]=j;//从x走到j 记录为to[x]=j
        }

    }
}
// 最后输出dis[T]为s->到T得最短距离 若dis[T]==INF 则说明不能到终点


//输出路径
void Print_Path(){
    int x=S;
    int In=0;
    cout<<S;
    while(x!=T){
        if(++In)cout<<" ";
        cout<<to[x]<<endl;
        x=to[x];
    }
    cout<<endl;
}







int main(){
    int cas = 0;
    while(cin>>n){
        cas++;
        init();
        for(int  i =0;i<n;i++){
            for(int j = 0;j<n;j++){
                int val;
                cin>>val;
                if(val!=-1){
                    add_edge(i,j,val);
                }
            }
        }
        int s,t;
        cin>>s>>t;
        S = s-1;
        T = t-1;
        Dij();
        cout<<"Case "<<cas<<endl;
        cout<<dis[T]<<endl;
    }
}

