//  main.cpp
//  SHU 1548
//
//  Created by 高松 on 16/1/7.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cmath>
int const Maxn= 2000+5;
int ans[Maxn];
int k[Maxn];
int f[Maxn];
#include <cstring>


int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    while(T--){
        int L,N;
        cin>>L>>N;
        memset(ans,0,sizeof(ans));
        memset(k,0,sizeof(k));
        memset(f,0,sizeof(f));
        for(int i=0;i<N;i++)
            cin>>k[i];
        for(int i=0;i<N;i++)
            cin>>f[i];
        for(int i=0;i<=L;i++){
            for(int j=0;j<N;j++){
                ans[i]+=(f[j]-abs(k[j]-i)>0?f[j]-abs(k[j]-i):0);
            }
        }
        int Min =9999999;
        int Index;
        for(int i=0;i<=L;i++){
            if(ans[i]<Min){
                Min=ans[i];
                Index=i;
            }
        }
        cout<<Index<<" "<<Min<<endl;
    }
    return 0;
}

