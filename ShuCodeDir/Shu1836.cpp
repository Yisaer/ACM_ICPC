//  A
//
//  Created by 高松 on 16/1/4.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <queue>
#include <stack>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#define  PB(X) push_back(X)
#define  PII   pair<int,int>
#define  MP    make_pair
#define  X     first
#define  Y     second
#define  MEM(a,val) memset(a,val,sizeof(a));
#define  ll long long
// 如果只需要组合数,以下为纯数学计算
//
//
//x+4*y+10*z=n-2
//n-2-10*z=x+4*y

#include <iostream>
#include <cstring>
using namespace std;
int sum;
int main()
{
    int A,B,C;
    int n;
    while(cin>>n>>A>>B>>C)
    {
        sum = 0;
        for(int i=0;i<100;i++)
            sum++;
        n-=2;C/=2;B=(B-1)/2;
        long long nums=0;
        int a=0,t=n;
        while(t>=0)
        {
            t=max(-4,t-max(0,t/4-B)*4-(max(0,t-A+3)/4)*4);
            
             sum = 0;
            for(int i=0;i<100;i++)
                sum++;
            
            
            
            if(t<0)t=-4;
            nums+=(int)(t)/4+1;
            a++;t=n-10*a;
            if(a>C)break;
            
            sum = 0;
            for(int i=0;i<100;i++)
                sum++;
        }
        cout<<nums<<endl;
    }
    return 0;
}

