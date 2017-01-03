//  main.cpp
//  SHU 1584
//
//  Created by 高松 on 16/1/11.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#define ll long long
ll color;

ll pow ( ll base , ll Index){
    ll res =1;
    while(Index){
        if(Index&1){
            res*=base;
        }
        base*=base;
        Index>>=1;
    }
    return res;
}


int main(int argc, const char * argv[]) {
   
    while(cin>>color){
        ll sum= 0 ;
        sum+=pow(color,10);
//        cout<<"sum="<<sum<<endl;
        sum+=4*pow(color,2);
        sum+=5*pow(color,6);
        sum/=10;
        cout<<sum<<endl;
    }
    
    
    return 0;
}
