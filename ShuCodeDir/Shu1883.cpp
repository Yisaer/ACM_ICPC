//  main.cpp
//  SHU1883 求个和  树状数组
//
//  Created by 高松 on 15/12/21.
//  Copyright © 2015年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
int N;
int const Maxn =1e5+10;
int a[Maxn];

int lowbit(int x){
    return x&(-x);
    
}

void  update(int x, int num){
    while(x<=N){
        a[x]+=num;
        x+=lowbit(x);
    }
    
}


int getSum(int x){
    int sum = 0;
    while(x>0){
        sum+=a[x];
        x-=lowbit(x);
    }
    return sum;
}
int main(int argc, const char * argv[]) {
    int q;
    while(scanf("%d%d",&N,&q)==2){
        memset(a,0,sizeof(a));
        for(int i=1;i<=N;i++){
            int val;
            scanf("%d",&val);
            update(i,val);
        }
        while(q--){
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%d\n",getSum(b)-getSum(a-1));
        }
        
    }
    
    return 0;
}
