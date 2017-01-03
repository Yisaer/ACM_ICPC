//
//  main.cpp
//  求ax 同余 1 mod m 即 a关于mod m的逆元
//
//  Created by 高松 on 16/1/2.
//  Copyright © 2016年 yisa. All rights reserved.
//

//
//  main.cpp
//  求mod m 的逆元
//
//  Created by 高松 on 15/12/10.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
// 求ax 同余 1 mod m

long mod_reverse(long a, long m){ // 接受a 与m
    long y=0,x=1,r=a%m, q, t, mm=m;//初始化
    if(r<0)r=r+m;
    while((m%r) != 0) {
        a=m; m=r;
        q= a/m; r=a % m;
        t=x; x=y-x*q; y=t;
    }
    if(r!=1) return 0;
    if(x<0) x=x+mm;
    return x; // 返回逆元
}

int main(int argc, const char * argv[]) {
    
    long a, m,ans;
    while(cin>>a>>m){
        ans= mod_reverse(a,m);
        cout<<"ans="<<ans<<endl;
        cout<<a*ans<<" mod "<<m<<"="<<(ans*a)%m<<endl;
    }
    
    return 0;
}
