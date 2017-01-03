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
int const Maxn = 500;
int F[Maxn];


int main(int argc, const char * argv[]) {
    F[0]=0;
    F[1]=1;
    for(int i=2;i<=47;i++){
        F[i]=F[i-1]+F[i-2];
    }
    int n;
    while(cin>>n,n>=0){
        for(int i=0;i<=48;i++){
            if(n==F[i])
            {
                cout<<i<<endl;
                break;
            }
            if(F[i]>n){
                cout<<"Not a Fibonacci number."<<endl;
                break;
            }
        }
    }
}
