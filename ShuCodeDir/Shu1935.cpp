//  main.cpp
//  SHU1935 C语言大师的冒泡循环
//
//  Created by 高松 on 15/12/8.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#include <algorithm>
#include <cstring>
#include <cmath>
#define ll long long
struct X{
    ll num;
    int index;
    
}P[100005];

bool cmp(X a, X b){
    
    return a.num<b.num;
}


int main(int argc, const char * argv[]) {
    
    int n;
    while(cin>>n){
        memset(P,0,sizeof(0));
        for(int i=0;i<n;i++){
            cin>>P[i].num;
            P[i].index=i;
        }
        sort(P,P+n,cmp);
        int Max=0;
        for(int i=0;i<n;i++){
            int w=P[i].index-i;
            if(w>Max)
                Max=w;
        }
        cout<<Max<<endl;
        
    }
    
    
    
    return 0;
}
