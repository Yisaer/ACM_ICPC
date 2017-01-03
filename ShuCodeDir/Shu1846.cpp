//  main.cpp
//  SHU1846 项目组
//
//  Created by 高松 on 15/12/6.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
int const Maxn=1e5;
int par[Maxn];
int Rank[Maxn];
int num[Maxn];

void make_set(int x){
    par[x]=x;
    Rank[x]=0;
    num[x]=1;
}


int find_set(int x)
{
    if(x!=par[x])
        par[x]=find_set(par[x]);
    return par[x];
}

void union_set(int x, int y){
    
    x=find_set(x);
    y=find_set(y);
    if(x==y) return;
    if(Rank[x]>Rank[y]){
        par[y]=x;
        num[x]+=num[y];
    }
    else{
        par[x]=y;
        if(Rank[x]==Rank[y])
            Rank[y]++;
        num[y]+=num[x];
    }
}

int main(int argc, const char * argv[]) {
    
    int s,e;
    while(cin>>s>>e){
        for(int i=1;i<=s;i++)
        {
            make_set(i);
        }
        while(e--){
            int a,b;
            cin>>a>>b;
            union_set(a,b);
        }
        int ans=0;
        for(int i=1;i<=s;i++)
        {
            if(par[i]==i)
                ans++;
            
        }
        cout<<ans<<endl;
        
    }
    
    return 0;
}
