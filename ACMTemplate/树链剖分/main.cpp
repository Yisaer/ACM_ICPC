//
//  main.cpp
//  树链剖分
//
//  Created by 高松 on 16/4/2.
//  Copyright © 2016年 yisa. All rights reserved.
//
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;


int const Maxn = 10010;

struct E{
    int next;
    int to;
}edge[Maxn*2];
int head[Maxn];
int tot;

int num[Maxn];//num[u] 以u为根节点的子树的结点数量
int par[Maxn];//par[u] u的父亲结点
int dep[Maxn];//dep[u] u的深度
int son[Maxn];//sun[u] u的重儿子
//以上为dfs1所得
int top[Maxn];//top[u] u所在重链的顶端
int pos[Maxn];//pos[u] 第u号边在线段树的结点位置
int POS;

void init(){
    tot=0;
    memset(head,-1,sizeof(head));
    POS=0;
    memset(son,-1,sizeof(son));
}

struct L{
    int u,v,w;
}Line[Maxn];

void add_edge(int u,int v){
    edge[tot].to =v;
    edge[tot].next=head[u];
    head[u]=tot++;
    //邻接表存图
}

//第一遍DFS得到par,dep,son,num
void dfs1(int cur,int Par,int Dep){
    dep[cur]=Dep;
    par[cur]=Par;
    num[cur]=1;
    for(int i=head[cur]; i!=-1; i=edge[i].next){
        int to = edge[i].to;
        if(to!=Par){
            dfs1(to,cur,Dep+1);
            num[cur]+=num[to];
            if(son[cur] == -1 || num[to]>num[son[cur]])
                son[cur]=to;
        }
    }
}


void getpos(int cur,int TopPar){
    top[cur]=TopPar;
    if(son[cur] != -1){
        pos[cur] = POS++;
        getpos(son[cur],TopPar);
    }
    else{
        pos[cur] = POS++;
        return;
    }
    
    for(int i= head[cur];i != -1;i=edge[i].next){
        int to = edge[i].to;
        if(to != son[cur] && to != par[cur])
            getpos(to,to);
    }
    
    
    //   注：这里先将结点cur的重儿子往下递归得到位置，再处理他的轻儿子，
    //    使得重链的各边在线段树中连续分布
}


//线段树部分
struct X{
    int L,R;
    int Max;
}Node[Maxn*3];


void build(int l,int r,int rt){
    Node[rt].L=l;
    Node[rt].R=r;
    Node[rt].Max = 0;
    if(l==r){
        return;
    }
    int mid = (l+r)/2;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
}

void push_up(int rt){
    Node[rt].Max = max(Node[rt*2].Max,Node[rt*2+1].Max);
}

void update(int position,int val,int rt){
    if(Node[rt].L == position && Node[rt].R == position){
        
        Node[rt].Max = val;
        return;
    }
    int mid = (Node[rt].L+Node[rt].R)/2;
    if(position<=mid){
        update(position,val,rt*2);
    }
    else{
        update(position,val,rt*2+1);
    }
    push_up(rt);
}

int query(int l,int r,int rt){
    if(Node[rt].L==l&&Node[rt].R==r){
        return Node[rt].Max;
    }
    int mid = (Node[rt].L+Node[rt].R)/2;
    if(r <= mid)
        return query(l,r,rt*2);
    else if(l > mid)
        return query(l,r,rt*2+1);
    else return max(query(l,mid,rt*2),query(mid+1,r,rt*2+1));
    
}

int find(int u,int v){
    
    int tmpMax= 0 ;
    int f1 = top[u];
    int f2 = top[v];
    while(f1 != f2){
        if(dep[f1] < dep[f2]){
            swap(f1,f2);
            swap(u,v);
        }
        tmpMax = max (tmpMax , query(pos[f1],pos[u],1));
        u = par[f1]; f1 = top[u];
    }
    if(u==v)
        return tmpMax;
    if(dep[u] > dep[v]) swap(u,v);
    return max(tmpMax,query(pos[son[u]],pos[v],1));
}


int main (){
    int n;
    int T;
    scanf("%d",&T);
    while(T--){
        
        init();
        scanf("%d",&n);
        for(int i=0;i<n-1;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            Line[i].u=u;
            Line[i].v=v;
            Line[i].w=w;
            
            //上面是建立树边，下面是图（建立关系）
            add_edge(u,v);
            add_edge(v,u);
        }
        //       cout<<"here1"<<endl;
        //建图完毕 开始dfs1
        dfs1(1,0,0);
        
        //        cout<<"here2"<<endl;
        //第二次dfs，得到重链顶端与树边在线段树中位置
        getpos(1,1);
        //建立线段树
        build(1,n,1);
        //        cout<<"here3"<<endl;
        for(int i=0;i<n-1;i++){
            if(dep[Line[i].u]< dep[Line[i].v])
                swap(Line[i].u,Line[i].v);
            //            将树边的下端顶点置于u处
            update(pos[Line[i].u],Line[i].w,1);
        }
        
        char str[10];
        int u,v;
        while( scanf("%s",str)==1){
            if(str[0]=='D')
            {
                break;
            }
            scanf("%d%d",&u,&v);
            if(str[0]=='Q'){
                printf("%d\n",find(u,v));
                continue;
            }
            else{
                update(pos[Line[u-1].u],v,1);
                continue;
            }
        }
    }
    return 0;
}