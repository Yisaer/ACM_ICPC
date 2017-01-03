//  main.cpp
//  SHU1202
//
//  Created by 高松 on 15/12/17.
//  Copyright © 2015年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
int dp[300005];
bool IsS(int n){
    
    while(n!=0){
        int x=n%10;
        n/=10;
        if(x==7)
            return true;
        
    }
    
    
    return false;
}

int main(int argc, const char * argv[]) {
    dp[1]=0;
    for(int i=2;i<=30000;i++){
        dp[i]=dp[i-1];
        if(i%7==0||IsS(i)){
            dp[i]++;
        }
    }
    int n;
    while(cin>>n){
        cout<<dp[n]<<endl;
    }
    
    return 0;
}
