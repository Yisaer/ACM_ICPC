//  main.cpp
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

using namespace std;
int a[1005];
int main()
{
    int n, i;
    while(cin>>n)
    {
        
        for(i = 0; i < n; i++)
            cin>>a[i];
        sort(a,a+n);
        int sum = 0;
        while(n >= 4)
        {
            if((a[1] * 2 + a[n-1] + a[0]) > (2 * a[0] + a[n-1] + a[n-2]))
            {
                sum += a[n-1];
                sum += a[0];
                sum += a[n-2];
                sum += a[0];
            }
            else
            {
                sum += a[1];
                sum += a[0];
                sum += a[n-1];
                sum += a[1];
            }
            n -= 2;
        }
        if(n == 3)
            sum += a[1] + a[0] + a[2];
        else if(n == 2)
            sum += a[1];
        else
            sum += a[0];
        cout<<sum<<endl;
    }
    return 0;
}

