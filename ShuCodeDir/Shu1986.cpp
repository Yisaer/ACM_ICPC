//  main.cpp
//  A
//
//  Created by 高松 on 16/1/4.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <queue>
#include <stack>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#define  PB(X) push_back(X)
#define  PII   pair<int,int>
#define  MP    make_pair
#define  X     first
#define  Y     second
#define  MEM(a,val) memset(a,val,sizeof(a));
#define  ll long long
int  F[1005];


int main (){
    int m,q;
    while(cin>>m>>q){
        for(int i=1;i<=m;i++)
            F[i]=1;
        for(int i=1;i<=q;i++){
            for(int j=i;j<=m;j++){
                if((j%i)==0){
                   if(F[j]==1)
                       F[j]=0;
                    else
                        F[j]=1;
                }
            }
            
        }
        int cnt = 0;
        for(int i=1;i<=m;i++)
            if(F[i]==0)
                cnt++;
                cout<<cnt<<endl;
        
    }
    
}


