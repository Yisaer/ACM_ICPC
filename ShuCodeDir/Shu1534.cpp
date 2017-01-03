//  main.cpp
//  SHU1534 ezProblem
//
//  Created by 高松 on 15/12/2.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;

int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
    
}

int main(int argc, const char * argv[]) {
    
    int a,b;
    while(cin>>a>>b)
    {
        int ans=1;
        ans*=gcd(a,b);
        int div=ans;
       // cout<<"div="<<div<<endl;
        a/=div;
        for(int i=2;i<=b;i++)
        {
            if(gcd(a,div)!=1)
            {
                int tmp=gcd(a,div);
                ans*=tmp;
                a/=tmp;
                div=tmp;
            }
            else
                break;
            
        }
        cout<<ans<<endl;
    }
    
    
    
    return 0;
}

