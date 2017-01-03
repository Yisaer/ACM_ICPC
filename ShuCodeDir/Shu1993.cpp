//  main.cpp
//  计算思维测试2
//
//  Created by 高松 on 16/2/22.
//  Copyright © 2016年 yisa. All rights reserved.
//
#include <cstring>
#include <iostream>
using namespace std;
#define ll long long
int const Maxn = 105;
int G[Maxn][Maxn];

int main ()
{
    int n,m;
    while(cin>>n>>m){
        memset(G,0,sizeof(G));
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            G[a][b]=1;
        }
        bool flag = true;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(G[i][k]==1&&G[k][j]==1){
                        if(G[j][i]==1){
                            flag = false;
                            goto A;
                        }else
                            G[i][j]=1;
                    }
                }
            }
            
        }
        A:
        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        
    }

}
