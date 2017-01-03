//
//  main.cpp
//  扩展欧几里得算法
//
//  Created by 高松 on 16/1/2.
//  Copyright © 2016年 yisa. All rights reserved.
//


//扩展欧几里得算法 求解求解形如ax+by=c的整数解 x y



#include <iostream>
using namespace std;

int exgcd(int a,int b,int & x,int & y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int r = exgcd(b, a%b, x, y);
    int t = y;
    y = x - (a/b)*y;
    x = t;
    return r;
}

int main() {

    
    int x,y;
    int a,b;
    cin>>a>>b;
    int c;
    cin>>c;
    int  gcd=exgcd(a,b,x,y);
    int ansx=c/gcd*x+b;
    int ansy=c/gcd*y-a;
    cout << "ax+by=c 的一个整数解为: x=" << ansx << ", y=" << ansy << endl;
    return 0;
}
