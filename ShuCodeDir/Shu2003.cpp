//  main.cpp
//  qqq
//
//  Created by 高松 on 16/4/9.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include<iostream>
#include<cstring>
#include <queue>
using namespace std;
//int S[10
#include <cmath>
int F[50000];
int main (){
    int T;
    cin>>T;
    memset(F,0,sizeof(F));
    while(T--){
        int n;
        cin>>n;
        double tmp = sqrt(n);
        int Tmp = tmp;
        if(Tmp>=tmp){
            Tmp--;
        }
        if(n%2==0){
        }
        else{
            Tmp++;
        }
        cout<<n-Tmp<<endl;
    }
}

