//  main.cpp
//  QY
//
//  Created by 高松 on 16/3/28.
//  Copyright © 2016年 yisa. All rights reserved.
//
#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#define ll long long
int F[8];


int main (){
    while(cin>>F[0]){
        for(int i=1;i<=5;i++)
            cin>>F[i];
        bool flag = true;
        for(int i=0;i<6;i++){
            if(F[i]) flag = false;
        }
        if(flag) break;
        int a = F[0]+F[1];
        int b = F[0]+F[2]+F[4]-F[1]-F[3]-F[5];
        cout<<"Anna's won-loss record is "<<(a-b)/2<<"-"<<(a+b)/2<<"."<<endl;
      
        
    }

}
