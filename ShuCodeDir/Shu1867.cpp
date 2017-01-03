//  main.cpp
//  SHU1867 Littlefish的难题
//
//  Created by 高松 on 15/12/7.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>
int x,y,z;
int cnt=0;
int vis[15625];
#define S(a,b,c) (a*20*20+b*20+c)
int ans[30];

void dfs(int a, int b ,int c){
    
    if(vis[S(a,b,c)]==1)
    {
        return;
    }
    vis[S(a,b,c)]=1;
    if(a==0){
        cnt++;
        ans[c]=1;
    //    return;
    }
//    cout<<"a="<<a<<" b="<<b<<" c="<<c<<endl;
    // c->a,b
    if(c!=0){
        //c->a    // a  b  c    c-(y-b)
        if(a+c>=x&&a!=x){
          
            dfs(x,b,c-x+a);
        }
        else if(a+c<x){
            
            dfs(a+c,b,0);
        }
        //c->b
        if(b+c>=y&&b!=y){
            dfs(a,y,c-y+b);
        }else if(b+c<y){
            dfs(a,b+c,0);
        }
        
    }
    // b->a,c
    if(b!=0){
        //b->a
        if(b+a>=x&&a!=x){
            dfs(x,b+a-x,c);
        }else if(b+a<x){
            dfs(b+a,0,c);
        }
        //b->c
        if(b+c>=z&&c!=z){
            dfs(a,b+c-z,z);
        }else if(b+c<z){
            dfs(a,0,b+c);
        }
        
    }
    // a->c,b
    if(a!=0){
        //a->c
        if(a+c>=z&&c!=z){
            dfs(a+c-z,b,z);
        }else if(a+c<z){
            dfs(0,b,a+c);
        }
        //a->b
        if(b+a>=y&&b!=y){
            dfs(a+b-y,y,c);
        }
        else if(a+b<y){
            dfs(0,a+b,c);
        }
        
    }
    
}


int main(int argc, const char * argv[]) {
    
    while(cin>>x>>y>>z){
        memset(vis,0,sizeof(vis));
        memset(ans,0,sizeof(ans));
        cnt =0;
        dfs(0,0,z);
       // cout<<"here"<<endl;
        int num=0;
        for(int i=0;i<=20;i++){
            
            if(ans[i]==1)
            {
                if(num)
                    cout<<" ";
                num++;
                cout<<i;
            }
            
        }
        cout<<endl;
            
        
        
    }
   
    return 0;
}


