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

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
    
}

int main (){
    int T;
    cin>>T;
    while(T--){
        int a,b,m;
        cin>>a>>b>>m;
        for(int i=m/a;i>=0;i--)
            for(int j=0;j<=m/b;j++){
                if(a*i+j*b==m){
                    cout<<i<<" "<<j<<endl;
                goto A;
                }
            }
        cout<<"Impossible"<<endl;
    A:
        continue;
        
        
        
    }
    
    
    
}



