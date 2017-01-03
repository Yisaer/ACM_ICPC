//  main.cpp
//  SHU1461 采集苹果
//
//  Created by 高松 on 15/12/4.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#include <queue>
#include <cstring>

#define ll long long
int const Maxn=1e5+10;
ll  ans;
int n;
ll L[Maxn];
void solve()
{
    priority_queue<ll ,vector<ll>,greater<ll> >que;
    for(int i=0;i<n;i++)
        que.push(L[i]);
    while(que.size()>1)
    {
       // cout<<"here"<<endl;
        ll l1,l2;
        l1=que.top();
        que.pop();
        l2=que.top();
        que.pop();
        ans+=(l1+l2);
        que.push(l1+l2);
    }
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    while(cin>>n){
        for(int i=0;i<n;i++)
        {
            cin>>L[i];
        }
        ans=0;
        solve();
        cout<<ans<<endl;
    }
    
    
    return 0;
}

