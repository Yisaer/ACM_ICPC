//  main.cpp
//  SHU1017 麦森数
//
//  Created by 高松 on 15/12/31.
//  Copyright © 2015年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cmath>
#include <cstring>
int const Maxn =500+1;
int num[Maxn];
int ans[Maxn];

//高精度乘法
void mul(int* x,int* y){
    int tmp[Maxn];
    memset(tmp,0,sizeof(tmp));
    int lx;
    int ly;
    lx=ly=500;
    while(x[lx]==0&&lx>0) lx--;
    while(y[ly]==0&&ly>0) ly--;
    int len = lx+ly;
    for(int i=1;i<=ly;i++){
        for(int j=1;j<=lx;j++){
            if(i+j-1<=500)
                tmp[i+j-1]+=x[j]*y[i];
        }
    }
    for(int i=1;i<=500;i++){
        tmp[i+1]+=tmp[i]/10;
        tmp[i]%=10;
        if(i<500&&tmp[i+1]==0){
            len=i;
            break;
        }
    }
    for(int i=500;i>0;i--){
        x[i]=tmp[i];
    }
    
    
    
}

int main(int argc, const char * argv[]) {
   
    long p;
    while(cin>>p){
        memset(num,0,sizeof(num));
        memset(ans,0,sizeof(ans));
        cout<<int(p*log10(2)+1)<<endl;
        ans[1]=1;
        num[1]=2;
        while(p){
            if(p&1) mul(ans,num);
            p>>=1;
            mul(num,num);
        }
        ans[1]-=1;
        for(int i=500;i>0;i--){
            cout<<ans[i];
            if((i-1)%50==0)
                cout<<endl;
        }
        
    }
    
    return 0;
}

