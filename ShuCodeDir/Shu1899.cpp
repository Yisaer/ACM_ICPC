//  main.cpp
//  小6和奇怪公式
//
//  Created by 高松 on 15/11/27.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;

#include <cmath>
#define ll long long

int main(int argc, const char * argv[]) {
    
    int T;
    cin>>T;
    while(T--)
    {
            ll n;
            double tmp;
            int tmp2;
            cin>>n;
            tmp=sqrt(n);
            tmp2=int(tmp);
            if(tmp2%2==0)
                cout<<0<<endl;
            else
                cout<<1<<endl;
            
        
        
    }
    
    return 0;
}
