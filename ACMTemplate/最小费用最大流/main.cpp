//
//  main.cpp
//  testmod
//
//  Created by 高松 on 16/1/10.
//  Copyright © 2016年 yisa. All rights reserved.
//

//最大流算法  Dinic分层算法
#include<iostream>
#include<string.h>
#include<queue>
using namespace std;
#define min(a,b)(a<b?a:b)
#define INF 1000000
const int MAX=210;
struct Node
{
    int c;
    int f;
};
int sx,ex;//sx和ex分别代表源点和汇点
int pre[MAX];
Node map[MAX][MAX];
int n,m;
bool BFS()//BFS搜索层次网络
{
    memset(pre,0,sizeof(pre));
    queue< int > Q;
    Q.push(sx);
    pre[sx]=1;
    while(!Q.empty())
    {
        int d=Q.front();
        Q.pop();
        for(int i=1;i<=n;i++)
        {
            if(!pre[i]&&map[d][i].c-map[d][i].f)
            {
                pre[i]=pre[d]+1;
                Q.push(i);
            }
        }
    }
    return pre[ex]!=0;
}
int dinic(int pos,int flow)//pos是顶点号，flow是当前顶点所能得到的流量
{
    int f=flow;
    if(pos==ex)
        return flow;
    for(int i=1;i<=n;i++)
    {
        if(map[pos][i].c-map[pos][i].f&&pre[pos]+1==pre[i])
        {
            int a=map[pos][i].c-map[pos][i].f;
            int t=dinic(i,min(a,flow));
            map[pos][i].f+=t;
            map[i][pos].f-=t;
            flow-=t;//我最开始就是这里没弄明白，我不明白为什么要此顶点得到的流量减去改变量；答案就在下面的  return f-flow;
        }
    }
    return f-flow;//其实这里返回给他前一层的就是这个t;因为t在层函数里面都有，所以所过避免重复就写成这样；
}
int slove()
{
    int sum=0;
    while(BFS())
    {
        sum+=dinic(sx,INF);
    }
    return sum;
}
int main()
{
    int u,v,w;
    while(cin>>m>>n)
    {
       
        memset(map,0,sizeof(map)) ;
        for(int i=1;i<=m;i++)
        {
            cin>>u>>v>>w;
            map[u][v].c+=w;
        }
        cin>>sx>>ex;
        cout<<slove()<<endl;
    }
    return 0;
}
/*
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <queue>


#define min(x,y) ((x<y)?(x):(y))
using namespace std;
int const Maxn = 250;
int tab[Maxn][Maxn];//邻接矩阵
int dis[Maxn];//距源点距离,分层图
int q[2000],h,r;//BFS队列 ,首,尾
int N,M,ANS;//N:点数;M,边数
int Start ;int Target;

int BFS()
{
    memset(dis,-1,sizeof(dis));//以-1填充
    dis[Start]=0;
    queue<int> Q;
    Q.push(Start);
    while(!Q.empty()){
        int x =Q.front();
        Q.pop();
        for(int i=1;i<=N;i++){
            if(dis[i]<0&&tab[x][i]>0)
            {
                dis[i]=dis[x]+1;
                Q.push(i);
            }
        }
    }
    
    
    if (dis[N]>0)
        return 1;
    else
        return 0;//汇点的DIS小于零,表明BFS不到汇点
}


//Find代表一次增广,函数返回本次增广的流量,返回0表示无法增广
int find(int x,int low)//Low是源点到现在最窄的(剩余流量最小)的边的剩余流量
{
    int i,a=0;
    if (x==Target)return low;//是汇点
    for (i=1;i<=N;i++)
        if (tab[x][i] >0 //联通
            && dis[i]==dis[x]+1 //是分层图的下一层
            &&(a=find(i,min(low,tab[x][i]))))//能到汇点(a <> 0)
        {
            tab[x][i]-=a;
            tab[i][x]+=a;
            return a;
        }
    return 0;
}
int main()
{
    //freopen("ditch.in" ,"r",stdin );
    //freopen("ditch.out","w",stdout);
    int i,f,t,flow,tans;
    while (scanf("%d%d",&M,&N)!=EOF){
        memset(tab,0,sizeof(tab));
        for (i=1;i<=M;i++)
        {
            scanf("%d%d%d",&f,&t,&flow);
            tab[f][t]+=flow;
        }
        cin>>Start>>Target;
        //
        ANS=0;
        while (BFS())//要不停地建立分层图,如果BFS不到汇点才结束
        {
            while(tans=find(1,0x7fffffff),tans)ANS+=tans;//一次BFS要不停地找增广路,直到找不到为止
        }
        printf("%d\n",ANS);
    }
    
}
*/

/*
 
 
 10 6
 5 1 3
 5 2 7
 1 2 2
 1 3 5
 1 4 4
 2 3 1
 2 4 4
 3 4 2
 3 6 8
 4 6 3
 5 6
//
//  main.cpp
//  最小费用最大流
//
//  Created by 高松 on 16/1/13.
//  Copyright © 2016年 yisa. All rights reserved.
//


#include <iostream>
using namespace std;
#include <queue>
#include <cstring>

int const Maxn= 1e5;
int const MaxM = 1e6;
int const INF  = 0x3f3f3f3f;

struct Edge {
    int to,next,cap,flow,cost;
}edge[MaxM];

int head [Maxn] ,tol;
int pre[Maxn];
int dis[Maxn];
bool vis[Maxn];

int N ;//结点总数，从0~N-1

void init (int n){
    N=n;
    tol=0;
    memset(head,-1,sizeof(head));
}


void addedge (int u,int v ,int cap ,int cost){
    edge[tol].to=v;
    edge[tol].cap=cap;
    edge[tol].cost = cost;
    edge[tol].flow = 0;
    edge[tol].next=head[ u];
    head[u]= tol++;
    edge[tol].to = u;
    edge[tol].cap = 0;
    edge[tol].cost = - cost;
    edge[tol].flow = 0;
    edge[tol].next= head[v];
    head [v] = tol++;
}

bool spfa (int s, int  t){
    queue<int>q ;
    for(int i=0;i<N;i++){
        dis[i]=INF;
        vis[i]=false;
        pre[i]=-1;
    }
    
    dis[s]=0;
    vis[s]= true;
    q.push(s);
    
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        vis[u]=false;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v = edge[i].to;
            if(edge[i].cap>edge[i].flow&&dis[v]>dis[u]+edge[i].cost)
            {
                dis[v]=dis[u]+edge[i].cost;
                pre[v]=i;
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
            
        }
        
    }
    if(pre[t]==-1) return false;
    return true;
}


int minCostMaxflow ( int s , int t , int &cost){
    int flow = 0;
    cost = 0;
    
    while(spfa(s,t)){
        
        int Min = INF;
        for(int i = pre[t];i!=-1;i=pre[edge[i^1].to]){
            if(Min>edge[i].cap-edge[i].flow){
                Min = edge[i].cap-edge[i].flow;
            }
        }
        
        for(int i=pre[t];i!=-1;i=pre[edge[i^1].to]){
            
            edge[i].flow+=Min;
            edge[i^1].flow -=Min;
            cost+= edge[i].cost*Min;
        }
        
        flow+=Min;
    }
    return flow ;
}

int main (){
    int n,m;
    while(cin>>n>>m){
        
        init(n);
        //点数n 边数M 点以0~n-1编号
        while(m--){
            //输入有向边（u,v) 最大流量cap ,单位费用cost
            int u,v,cap,cost;
            cin>>u>>v>>cost>>cap;
            addedge(u,v,cap,cost);
        }
        int s, t;
        cin>>s>>t;//s为起点，t为终点
        int cost = 0;
        int Flow ;
        Flow = minCostMaxflow(s,t,cost);
        cout<<"Flow="<<Flow<<endl;
        cout<<"Cost="<<cost<<endl;
    }
    
    
}
*/
