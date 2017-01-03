//  main.cpp
//  小6的难题
//
//  Created by 高松 on 15/11/27.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;

#include <algorithm>
int const Max=1010;
int  p[Max];

int main(int argc, const char * argv[]) {
   
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=0;i<2*n;i++)
        {
            cin>>p[i];
        }
        sort(p,p+2*n);
        int i,j;
        long long sum=0;
        for(i=0,j=2*n-1;i<=j;i++,j--)
        {
            sum+=(p[j]-p[i])*(p[j]-p[i]);
        }
        cout<<sum<<endl;
    }
    
    return 0;
}
