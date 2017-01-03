//  main.cpp
//  SHU1919
//
//  Created by 高松 on 15/12/23.
//  Copyright © 2015年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#define ll long long

ll dp[21][21];



int main(int argc, const char * argv[]) {
    
    dp[0][0]=dp[1][0]=dp[1][1]=1;
    for(int i=2;i<=20;i++)
    {
        dp[i][0]=dp[i][i]=1;
        for(int j=1;j<i;j++)
        dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
    }
    int n ,k;
    int T;
    cin>>T;
    while(T--){
        cin>>n>>k;
        cout<<dp[n][k]*dp[n][k-1]/n<<endl;
    }
    
    
    return 0;
}
