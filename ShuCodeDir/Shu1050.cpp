//  main.cpp
//  SHU1050 纪念品分组
//
//  Created by 高松 on 15/11/30.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>
#include <algorithm>
int const Max=3e5+10;
int a[Max];



int main(int argc, const char * argv[]) {
    int Lim;
    int n;
    while(cin>>Lim)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        int ans=0;
        int srt=0;
        int end=n-1;
        while(n>0)
        {
            if(srt==end)
            {
                ans++;
                n--;
            }
            else if (a[srt] + a[end]  <= Lim)
                n = n - 2, srt++, end--, ans++;
            else
                n--, end--, ans++;
            
        }
        cout<<ans<<endl;
    }
    
    return 0;
}

