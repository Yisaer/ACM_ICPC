//  main.cpp
//  SHU Q
//
//  Created by 高松 on 15/11/24.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#include <algorithm>

struct A
{
    int s;
    int e;
    
}F[105];

bool cmp(A a,A b)
{
    if(a.s==b.s)
        return a.e<b.e;
    return a.s<b.s;
}


int main(int argc, const char * argv[]) {
    
    int n;
    while(cin>>n,n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>F[i].s>>F[i].e;
        }
        sort(F,F+n,cmp);
        
        int ans=1;
        int cur=F[0].e;
        for(int i=1;i<n;i++)
        {
            if(F[i].s<cur)
            {
                continue;
            }
            ans++;
            cur=F[i].e;
            if(cur==24)
                break;
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
