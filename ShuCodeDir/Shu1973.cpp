//  SHU1973 鸡排销售系统
//
//  Created by 高松 on 15/12/18.
//  Copyright © 2015年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstdio>
int const Maxn =100000+10;


struct X{
    int y1;
    int y2;
    int y0;
    int lazy;
    int l,r;
}Node[Maxn<<2];


void set_down(int rt){
    int n=Node[rt].lazy;
    if(n){
        n=n%3;
        while(n--){
            int ta=Node[rt*2].y0;
            int tb=Node[rt*2].y1;
            int tc=Node[rt*2].y2;
            Node[rt*2].y0=tc;
            Node[rt*2].y1=ta;
            Node[rt*2].y2=tb;
            Node[rt*2].lazy++;
            ta=Node[rt*2+1].y0;
            tb=Node[rt*2+1].y1;
            tc=Node[rt*2+1].y2;
            Node[rt*2+1].y0=tc;
            Node[rt*2+1].y1=ta;
            Node[rt*2+1].y2=tb;
            Node[rt*2+1].lazy++;
        }
        Node[rt].lazy=0;
    }
}

void set_up(int rt){
    Node[rt].y0=Node[rt*2].y0+Node[rt*2+1].y0;
    Node[rt].y1=Node[rt*2].y1+Node[rt*2+1].y1;
    Node[rt].y2=Node[rt*2].y2+Node[rt*2+1].y2;
}
void init (int L,int R,int rt){
    Node[rt].l=L;
    Node[rt].r=R;
    Node[rt].y1=0;
    Node[rt].y2=0;
    Node[rt].lazy=0;
    if(L==R){
        Node[rt].y0=1;
        return;
    }
    if(L!=R){
        int mid=(L+R)/2;
        init(L,mid,rt*2);
        init(mid+1,R,rt*2+1);
        set_up(rt);
    }
    
}

void insert(int L,int R,int rt){
    if(Node[rt].l==L&&Node[rt].r==R){
        int ta=Node[rt].y0;
        int tb=Node[rt].y1;
        int tc=Node[rt].y2;
        Node[rt].y0=tc;
        Node[rt].y1=ta;
        Node[rt].y2=tb;
        Node[rt].lazy++;
        return ;
    }
    set_down(rt);
    int mid =(Node[rt].l+Node[rt].r)/2;
    if(R<=mid)
        insert(L,R,rt*2);
    else if(L>mid)
        insert(L,R,rt*2+1);
    else{
        insert(L,mid,rt*2);
        insert(mid+1,R,rt*2+1);
    }
    set_up(rt);
}

int query(int L, int R ,int rt){
    if(Node[rt].l==L&&Node[rt].r==R){
        return Node[rt].y0;
    }
    set_down(rt);
    int mid = (Node[rt].r+Node[rt].l)/2;
    if(R<=mid)
        return query(L,R,rt*2);
    else if(L>mid)
        return query(L,R,rt*2+1);
    else
      return  query(L,mid,rt*2)+query(mid+1,R,rt*2+1);
    
}


int main(int argc, const char * argv[]) {
    int n,q;
    while(scanf("%d%d",&n,&q)==2){
        init(1,100000,1);
        while(q--){
            int x,a,b;
            scanf("%d%d%d",&x,&a,&b);
            if(x){
                int ans =query(a,b,1);
                printf("%d\n",ans);
            }else{
                
                insert(a,b,1);
            }
        }
        
    }
    
    return 0;
}

