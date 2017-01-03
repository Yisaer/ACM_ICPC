//  main.cpp
//  SHU 1270
//
//  Created by 高松 on 16/1/3.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cmath>
#include <cstring>
#include <cstdio>
double const Pie = 3.1415926;
double x[105];
double y[105];
int main(int argc, const char * argv[]) {
    
    int n;
    double r;
    while(cin>>n>>r){
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        double sum = 0;
        sum+=2*Pie*r;
        for(int i=0;i<n;i++){
            cin>>x[i]>>y[i];
        }
        x[n]=x[0];
        y[n]=y[0];
        for(int i=1;i<=n;i++){
            sum+=sqrt(pow(x[i]-x[i-1],2)+pow(y[i]-y[i-1],2));
        }
        printf("%.2lf\n",sum);
        
    }
    return 0;
}
