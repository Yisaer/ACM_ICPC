//  main.cpp
//  SHU1979 自写
//
//  Created by 高松 on 15/12/18.
//  Copyright © 2015年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
int const Maxn = 100000+10;
#include <cstdio>

struct X{
    int l,r;
    int val;
    int lazy;
}Node[Maxn<<2];

void set_up(int rt){
    Node[rt].val=max(Node[rt*2].val,Node[rt*2+1].val);
}

void init (int L,int R,int rt){
    Node[rt].l=L;
    Node[rt].r=R;
    Node[rt].val = 0;
    Node[rt].lazy=0;
    if(L!=R){
        int mid= (L+R)/2;
        init(L,mid,2*rt);
        init(mid+1,R,2*rt+1);
    }
}

void set_down(int rt){
    if(Node[rt].lazy){
        int t = Node[rt].lazy;
        Node[rt*2].val+=t;
        Node[rt*2].lazy+=t;
        Node[rt*2+1].val+=t;
        Node[rt*2+1].lazy+=t;
        Node[rt].lazy = 0;
    }
}

int query(int  L,int R,int rt){
    if(Node[rt].l==L&&Node[rt].r==R){
        return Node[rt].val;
    }
    set_down(rt);
    int mid = (Node[rt].l+Node[rt].r)/2;
    if(R<=mid)
        return query(L,R,rt*2);
    else if(mid<L)
        return query(L,R,rt*2+1);
    else
    return max(query(L,mid,2*rt),query(mid+1,R,2*rt+1));
}

void insert(int L, int R ,int rt){
    if(Node[rt].l==L&&Node[rt].r==R){
        Node[rt].val++;
        Node[rt].lazy++;
        return;
    }
    set_down(rt);
    int mid = (Node[rt].l+Node[rt].r)/2;
    if(R<=mid)
        insert(L,R,rt*2);
    else if(L>mid)
        insert(L,R,rt*2+1);
    else{
        insert(L,mid,2*rt);
        insert(mid+1,R,2*rt+1);
    }
    set_up(rt);
    
}




int main(int argc, const char * argv[]) {

    int n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)==3){
        init (1,100000,1);
        while(m--){
            int a,b;
            scanf("%d%d",&a,&b);
            b--;
            int num =query(a,b,1);
            if(num<k){
                printf("Yes\n");
                insert(a,b,1);
            }else{
                printf("No\n");
            }
        }
        
    }
    
    return 0;
}

