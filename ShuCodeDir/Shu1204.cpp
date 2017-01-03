//  main.cpp
//  shu1204 文科生的悲哀
//
//  Created by 高松 on 15/12/15.
//  Copyright © 2015年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;

int a[5]={0,2,13,24,3};
#define ll long long
ll ans;
int  fib[10005];
int const mod = 7654321;

int n;
/*
void dfs(int step,int num){
    if(step==n){
        ans++;
        return;
    }
    int tmp=a[num];
    while(tmp!=0){
        int t=tmp%10;
        dfs(step+1,t);
        tmp/=10;
    }
}
*/
int main(int argc, const char * argv[]) {
    fib[1]=1;
    fib[2]=1;
    for(int i=3;i<=10000;i++){
        fib[i]=(fib[i-1]%mod+fib[i-2]%mod)%mod;
    }
    while(cin>>n){
        cout<<fib[n]<<endl;
    }
    
    return 0;
}
