//
//  main.cpp
//  线段树（ 延迟标记)
//
//  Created by 高松 on 16/1/1.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
int const Maxn = 100000+10;
#include <cstdio>

struct X{
    int l,r;   //结点所覆盖的范围
    int val;   //结点所记录的值
    int lazy;  // 延迟标记
}Node[Maxn<<2];

void set_up(int rt){
    
//    Node[rt].val = operator(Node[rt*2].val,Node[rt*2+1].val);
    
}

void init (int L,int R,int rt){
    Node[rt].l=L;
    Node[rt].r=R;
    Node[rt].val = 0;
    Node[rt].lazy=0;
    if(L==R){
        
        //对于结点值得操作 Node[rt].val
        return;
    }
    int mid = (L+R)/2;
    init(L,mid,rt*2);
    init(mid+1,R,rt*2+1);
    //set_up(rt) 若是需要值得向上传递则直接向上传值
}

void set_down(int rt){
    if(Node[rt].lazy){
        int t = Node[rt].lazy;
//      operator(  Node[rt*2].val );
//      operator(  Node[rt*2+1].val );
        Node[rt*2].lazy+=t;
        Node[rt*2+1].lazy+=t;
        Node[rt].lazy = 0;
    }
}


void update(int L,int R,int rt){
    if(Node[rt].l==L&&Node[rt].r==R){
        //operator Node[rt].val
        Node[rt].lazy++;
        return;
    }
    set_down(rt);//处理延迟标记
    int mid = (Node[rt].l+Node[rt].r)/2;
    if(R<=mid)
        update(L,R,rt*2);
    else if(L>mid)
        update(L,R,rt*2+1);
    else{
        update(L,mid,2*rt);
        update(mid+1,R,2*rt+1);
    }
    set_up(rt); //从子节点返回给当前结点 对当前结点的更新
    
}


int  query(int L,int R,int rt){
    
    if(Node[rt].l==L&&Node[rt].r==R){
        return Node[rt].val;
    }
    set_down(rt);
    int mid = ( Node[rt].l+Node[rt].r )/2;
    if (R<=mid)
        return query(L,R,rt*2);
    
    else if(L>mid)
        return query(L,R,rt*2+1);
    
    else  //  需要根据实际情况改变两个子区间的返回值
      return  query(L,mid,rt*2)+query(mid+1,R,rt*2+1);

}







int main(int argc, const char * argv[]) {
    
}
