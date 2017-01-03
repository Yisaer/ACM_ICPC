//  main.cpp
//  D6-排座
//
//  Created by 高松 on 15/10/12.
//  Copyright © 2015年 伊萨. All rights reserved.
//


#include <iostream>
using namespace std;
#define ll long long


ll P(int n)
{
    
    ll ans=1;
    for(int i=n;i>=1;i--)
        ans*=i;
    return ans;
    
}
int main(int argc, const char * argv[]) {
    int n;
    while(cin>>n)
    {
        cout<<P(n-1)-4*P(n-2)+2*P(n-3)<<endl;
    }
    
    
    return 0;
}

// (n-3)!   
// D B A C  ABCDE   B A C E D  B A C D E

// B A C D  B C D A
