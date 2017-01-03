//  main.cpp
//  ANS
//
//  Created by 高松 on 15/10/13.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#define ll long long
#include <cstring>
int A[99999];
int main ()
{
    int a,b;
    while(cin>>a>>b,a||b)
    {
        int temp=(a*100)%b;
        int cnt=0;
        int tt=0-temp;
        memset(A,0,sizeof(A));
        int j=1;
        while(tt<100)
        {
            if(tt>=0)
            {
                A[j++]=tt;
                cnt++;
            }
            tt+=b;
        }
        for(int i=1;i<=cnt;i++)
        {
            if(i-1)
                cout<<" ";
            if(A[i]>10)
            cout<<A[i];
            else
                cout<<"0"<<A[i];
        }
        cout<<endl;
        
        
        
    }

}
