//
//  main.cpp
//  线段树（ 延迟标记)
//
//  Created by 高松 on 16/1/1.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
int const Maxn = 1e5+10;
#include <cstring>
#include <cstdio>
#define PIII pair<long long ,pair<int, int > >



struct X{
    int l,r;   //结点所覆盖的范围
                //结点所记录的值
    int lazy;  // 延迟标记
    int Max;
    int Min;
    long long sum;
}Node[Maxn<<2];

void set_up(int rt){
    
    //    Node[rt].val = operator(Node[rt*2].val,Node[rt*2+1].val);
    Node[rt].Max = max(Node[rt*2].Max,Node[rt*2+1].Max);
    Node[rt].Min = min(Node[rt*2].Min,Node[rt*2+1].Min);
    Node[rt].sum = Node[rt*2].sum+Node[rt*2+1].sum;
    
}

void init (int L,int R,int rt){
    Node[rt].l=L;
    Node[rt].r=R;
    Node[rt].lazy=0;
    if(L==R){
        
        int val;
        scanf("%d",&val);
        
        Node[rt].Max = val;
        Node[rt].Min = val;
        Node[rt].sum = val;
        return;
        
    }
    int mid = (L+R)/2;
    init(L,mid,rt*2);
    init(mid+1,R,rt*2+1);
    set_up(rt) ;//若是需要值得向上传递则直接向上传值
}

//void set_down(int rt){
//    if(Node[rt].lazy){
//        int t = Node[rt].lazy;
//        //      operator(  Node[rt*2].val );
//        //      operator(  Node[rt*2+1].val );
//        Node[rt*2].lazy+=t;
//        Node[rt*2+1].lazy+=t;
//        Node[rt].lazy = 0;
//    }
//}
//

void update(int L,int R,int rt,int k){
    if(Node[rt].l==L&&Node[rt].r==R){
        //operator Node[rt].val
        Node[rt].Max += k;
        Node[rt].Min += k;
        Node[rt].sum += k;
        return;
    }
//    set_down(rt);//处理延迟标记
    int mid = (Node[rt].l+Node[rt].r)/2;
    if(R<=mid)
        update(L,R,rt*2,k);
    else if(L>mid)
        update(L,R,rt*2+1,k);
    else{
        update(L,mid,2*rt,k);
        update(mid+1,R,2*rt+1,k);
    }
    set_up(rt); //从子节点返回给当前结点 对当前结点的更新
    
}


PIII  query(int L,int R,int rt){
    
    if(Node[rt].l==L&&Node[rt].r==R){
        return  make_pair(Node[rt].sum,make_pair(Node[rt].Max,Node[rt].Min));
    }
//    set_down(rt);
    int mid = ( Node[rt].l+Node[rt].r )/2;
    if (R<=mid)
        return query(L,R,rt*2);
    
    else if(L>mid)
        return query(L,R,rt*2+1);
    
    else  //  需要根据实际情况改变两个子区间的返回值
//        return  make_pair(query(L,mid,rt*2).first+
//        query(mid+1,R,rt*2+1).first,make_pair(query(L,mid,rt*2).second.first));
    
    {
        PIII a = query(L,mid,rt*2);
        PIII b = query(mid+1,R,rt*2+1);
        long long S = a.first+b.first;
        int MMax = max(a.second.first,b.second.first);
        int MMin = min(a.second.second,b.second.second);
        return make_pair(S,make_pair(MMax,MMin));
        
    }
    
}


int main (){

    int n,m;
    while(scanf("%d%d",&n,&m)==2){
        memset(Node,0,sizeof(Node));
        init(1,n,1);
        while(m--){
            int q,x,y;
            scanf("%d%d%d",&q,&x,&y);
            if(q==1){
                update(x,x,1,y);
                
            }else{
                PIII ans = query(x,y,1);
                printf("%d %lld %d\n",ans.second.first,ans.first,ans.second.second);
//                cout<<ans.second.first<<" "<<ans.first<<" "<<ans.second.second<<endl;
            }
            
        }
        
    }
}
