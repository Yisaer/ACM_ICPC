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

int const Maxn = 65;

ll dp [Maxn];
int main (){
    for(int i=1;i<=60;i++){
        dp[i]=2*(pow(2,(i-1))+pow((-1),(i-2)));
    }
    int n;
    dp[1]=3;
    while(cin>>n)
        cout<<dp[n]<<endl;
    
}
