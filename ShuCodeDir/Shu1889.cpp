//  main.cpp
//  SHU 1889
//
//  Created by 高松 on 16/1/18.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>

int const Maxn =1e5+10;
int const null = -1;
int cnt,root;
int a[Maxn];
struct node {
    int key;
    int par;
    int sum;
    int size;
    int cld[2];
}ts[Maxn];

void init(){
    cnt=  0;
    root = null;
    
}

int new_node(int key,int par){
    ts[cnt].key=key;
    ts[cnt].par=par;
    ts[cnt].size=1;
    ts[cnt].cld[0]=ts[cnt].cld[1]=null;
    return cnt++;
}

void push_up(int x){
    ts[x].sum=ts[x].key;
    ts[x].size=1;
    if(ts[x].cld[0]!=null){
        ts[x].sum+=ts[ts[x].cld[0]].sum;
        ts[x].size+=ts[ts[x].cld[0]].size;
    }
    if(ts[x].cld[1]!=null){
        ts[x].sum+=ts[ts[x].cld[1]].sum;
        ts[x].size+=ts[ts[x].cld[1]].size;
    }
    
}
int build(int p,int l,int r){
    if(r<l)
        return -1;
    int mid = (l+r)>>1;
    int t= new_node(a[mid],p);
    if(p==null){
        root=t;
    }
    ts[t].cld[0]=build(t,l,mid-1);
    ts[t].cld[1]=build(t,mid+1,r);
    push_up(t);
    return t;
}

void rotate(int x,int k){
    int y=ts[x].par,z=ts[y].par;
    ts[y].cld[!k]=ts[x].cld[k];
    push_up(y);
    if(ts[x].cld[k]!=null)
        ts[ts[x].cld[k]].par=y;
    ts[x].par=z;
    if(z!=null)
        ts[z].cld[(y==ts[z].cld[1])]=x;
    ts[y].par=x;
    ts[x].cld[k]=y;
}

void splay (int x, int S){
    while(ts[x].par!=S){
        int y=ts[x].par;
        if(ts[y].par==S)
            rotate(x,ts[y].cld[0]==x);
        else{
            
            int d = (ts[ts[y].par].cld[0]==y);
            //判断x与y是否处在同一旋转方向
            if (ts[y].cld[d]==x)
            //x与y处于不同子树，则不同旋转
                rotate(x,!d),rotate(x,d);
            else
            //相同子树，相同旋转
                rotate(y,d),rotate(x,d);
            
        }
    }
    push_up(x);
    if(S==-1)
        root=x;
}

void find_kth(int k,int goal){
    int r=root,ls;
    while(r!=null){
        ls=(ts[r].cld[0]==null?0:ts[ts[r].cld[0]].size);
        if(k<=ls)
            r=ts[r].cld[0];
        else if(k==ls+1){
            splay(r,goal);
            return;
        }
        else{
            k-=(ls+1);
            r=ts[r].cld[1];
        }
        
    }
    
}

int main(int argc, const char * argv[]) {
    int n,m;
    while(scanf("%d%d",&n,&m)==2){
    init();
    
    a[0]=a[n+1]=0;
    for(int i=1;i<=n;i++){
        int val;
        scanf("%d",&val);
        a[i]=val;
    }
    build(null,0,n+1);
    for(int i=0;i<m;i++){
        int t,l,r,x;
        scanf("%d%d%d",&t,&l,&r);
        if(t==1){
            find_kth(l,null);
            find_kth(r+2,root);
            printf("%d\n",ts[ts[ts[root].cld[1]].cld[0]].sum);
        }
        else{
            scanf("%d",&x);
            find_kth(l,null);
            find_kth(r+2,root);
            int temp = ts[ts[root].cld[1]].cld[0];
            ts[ts[root].cld[1]].cld[0]=null;
            splay(ts[root].cld[1],null);
            if(x>r)
                x-=(r-l+1);
            find_kth(x+1,null);
            find_kth(x+2,root);
            ts[temp].par=ts[root].cld[1];
            ts[ts[root].cld[1]].cld[0]=temp;
            splay(ts[root].cld[1],null);
        }
        
        
    }
    }
    
    return 0;
}

