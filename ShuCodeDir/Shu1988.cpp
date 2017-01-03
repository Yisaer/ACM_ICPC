//  main.cpp
//  计算思维测试2
//
//  Created by 高松 on 16/2/22.
//  Copyright © 2016年 yisa. All rights reserved.
//
#include <cstring>
#include <iostream>
using namespace std;
#define ll long long
int main ()
{
    int a,b,c,d;
    int A,B,C,D;
    while(cin>>a>>b>>c>>d)
    {
        cin>>A>>B>>C>>D;
        D+=d;
        if(D>=60){
            D-=60;
            C++;
        }
        C+=c;
        if(C>=60){
            C-=60;
            B++;
            
        }
        B+=b;
        if(B>=24){
            B-=24;
            A++;
            
        }
        A+=a;
        cout<<A<<" "<<B<<" "<<C<<" "<<D<<endl;
    }
    
    
}
