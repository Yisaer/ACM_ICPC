//  main.cpp
//  SHU1910 正方形环
//
//  Created by 高松 on 15/12/24.
//  Copyright © 2015年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstdio>
#define ll long long
ll A[32];
ll d[5];
ll C[32][32];




int main(int argc, const char * argv[]) {
    d[1]=1;
    d[2]=4;
    d[3]=6;
    d[4]=3;
    C[0][0]=C[1][0]=C[1][1]=1;
    for(int i=2;i<=32;i++)
    {
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)
            C[i][j]=C[i-1][j]+C[i-1][j-1];
    }
    A[1]=1;
    A[2]=6;
    A[3]=21;
    for(int i=4;i<=32;i++){
    A[i]=d[1]*i+d[2]*C[i][2]+d[3]*C[i][3]+d[4]*C[i][4];
   //     cout<<"i="<<i<<" C="<<A[i]<<endl;
    }
    int n;
    while(cin>>n){
        cout<<A[n]<<endl;
    }

    
    return 0;
}

