//  main.cpp
//  SHU1545
//
//  Created by 高松 on 16/1/9.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
int const Maxn = 60;
int M[Maxn];
int Z1[Maxn];
int Z2[Maxn];
int Z3[Maxn];

int main (){

    M[1]=1;M[2]=1;M[3]=1;M[4]=1;
    Z1[2]=1;
    Z1[3]=1;
    Z2[3]=1;
    Z1[4]=1;
    Z2[4]=1;
    Z3[4]=1;
    long long F[Maxn];
    F[1]=1;F[2]=2;F[3]=3;F[4]=4;
    for(int i=5;i<=58;i++){
        M[i]=M[i-1]+Z3[i-1];
        Z3[i]=Z2[i-1];
        Z2[i]=Z1[i-1];
        Z1[i]=M[i];
        F[i]=M[i]+Z1[i]+Z2[i]+Z3[i];
    }
//    for(int i=1;i<=56;i++)
//    {
//        cout<<F[i]<<endl;
//    }
    int n ;
    while(cin>>n,n)
        cout<<F[n]<<endl;
}
