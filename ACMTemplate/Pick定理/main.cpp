//
//  main.cpp
//  Pick定理
//
//  Created by 高松 on 16/3/3.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cmath>



struct POINT {
    int x;
    int y;
};

int gcd ( int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

int OnSegment(POINT A,POINT B){
    return gcd(fabs(A.x-B.x),fabs(A.y-B.y))+1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
