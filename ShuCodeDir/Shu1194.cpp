//  main.cpp
//  SHU1194 愚蠢的摄影师
//
//  Created by 高松 on 15/12/7.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
int const N = 60;
#define ll long long
ll dp[N];
ll a[20];


int main (){
    a[1] =1;
    a[2] =1;
    a[3] =2;
    a[4] =4;
    a[5]= 6;
    for(int i=4;i<=55;i++)
    {
        a[i+2]=a[i]+a[i+1]-a[i-3];
    }
    int n;
    while(cin>>n)
    {
        cout<<a[n]<<endl;
    }
    
    return 0;
}

