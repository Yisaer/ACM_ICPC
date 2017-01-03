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

int main (){
    int T;
    cin>>T;
    while(T--){
        int a;
        cin>>a;
        int num = 0;
        while(a){
            if(a&1){
                num++;
            }
            a/=2;
        }
        cout<<(long long)(1<<num)<<endl;
    }
}

