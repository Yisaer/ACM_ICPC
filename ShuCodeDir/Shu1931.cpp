//  main.cpp
//  Yaoge和死循环
//
//  Created by 高松 on 15/11/27.
//  Copyright © 2015年 伊萨. All rights reserved.
//
#include <iostream>
using namespace std;
#include <cstring>
#include <map>

map<int ,int> P; //左起点，右终点
map<int ,bool>vis;
#define ll long long
int main ()
{
    int T;
    cin>>T;
    while(T--)
    {
        ll N,K;
        cin>>N>>K;
        //init();
        P.clear();
        vis.clear();
        P[N]=-1;
        while(K--)
        {
            ll a, b;
            cin>>a>>b;
            P[a]=b;
        }
        map<int,int>::iterator it;
        int cnt=1;
        while(cnt!=N)
        {
            if(cnt==-1) break;
            if(vis[cnt]) break;
            vis[cnt]=1;
            
            for(it=P.begin();it!=P.end();it++)
            {
                if(it->first>=cnt)
                {
                    cnt=it->second;
                    break;
                }
            }
            
        }
        if(cnt==N||cnt==-1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
}




/*
 3
 10 3
 3 7
 9 4
 6 10
 */

