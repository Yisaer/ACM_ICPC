//  main.cpp
//  SHU1951 Apple trees
//
//  Created by 高松 on 15/12/4.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#include <algorithm>
#include <cstring>
struct T{
    int d;
    int num;
    
}P[2000];
int n;
#define ll long long

bool cmp(T a ,T b)
{
    return a.d>b.d;
}
/*
 
 1
 3 2
 1 3
 2 1
 3 2
 
 */
int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    while(T--)
    {
        memset(P,0,sizeof(P));
        int Lim;
        cin>>n>>Lim;
        for(int i=1;i<=n;i++)
        {
            cin>>P[i].d>>P[i].num;
        }
        sort(P+1,P+n+1,cmp);
        ll ans=0;
        int cur=1;
        int take=0;
        int Run=0;
        P[0].d=0;
        while(P[n].num!=0)
        {
            take=0;
            Run=0;
            Run+=P[cur].d;
            while(take!=Lim&&cur<=n)
            {
              
              if(P[cur].num>Lim-take)
              {
                  P[cur].num-=Lim-take;
                  take=Lim;
                  break;
              }
              else if(P[cur].num<Lim-take){
                  take+=P[cur].num;
                  P[cur].num=0;
                  if(cur<n)
                  Run+=P[cur].d-P[cur+1].d;
                  else
                      break;

                  cur++;
              }
              else{
                  
                  take=Lim;
                  P[cur].num=0;
                  break;
                  
              }
                
            }
            
            if(cur<=n)
            Run+=P[cur].d;
            else Run+=P[n].d;
        //    cout<<"run="<<Run<<endl;
            ans+=Run;
            if(P[cur].num==0)
            cur++;
        }
        cout<<ans<<endl;
    }
   
    return 0;
}
