//
//  main.cpp
//  判断是否存在欧拉回路
//
//  Created by 高松 on 16/1/1.
//  Copyright © 2016年 yisa. All rights reserved.
//


#include<iostream>
#include<cstring>
#define MAXN 1005
using namespace std;

int n;// 点的数量

int d[MAXN];//点的入度
int father[MAXN];//点所在连通集合的根节点

int getfather(int x)    //寻找根节点
{
    if (father[x]==x) return x;
    return father[x]=getfather(father[x]);// 改变father[x]的值，为了最后和father[1]判断是否相等
}

void init(){
    
    memset(d,0,sizeof(d));
    for(int i=1;i<=n;i++)
        father[i]=i;
    
}

void getedge(int u,int v){
    d[u]++;
    d[v]++;
    u=getfather(u);
    v=getfather(v);
    father[u]=v;
}

bool Is_Euler(){
    for( int i=1;i<=n;i++)
        if(d[i]%2||getfather(i)!=father[1])
            return false;
    return true;
    
}


int main()
{
  
}
