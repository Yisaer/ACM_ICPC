//  main.cpp
//  SHU1043 采药
//
//  Created by 高松 on 15/12/15.
//  Copyright © 2015年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>

#define ll long long 

ll dp[1005];
int T[105];
int v[105];


int main(int argc, const char * argv[]) {
    
    int t,n;
    while(cin>>t>>n){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            cin>>T[i]>>v[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=t;j>=T[i];j--){
                dp[j]=max(dp[j],dp[j-T[i]]+v[i]);
            }
        }
        cout<<dp[t]<<endl;
    }
    
    return 0;
}

