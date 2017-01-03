//  main.cpp
//  SHU1335 VIJP1076
//
//  Created by 高松 on 15/12/8.
//  Copyright © 2015年 伊萨. All rights reserved.
//
#include<cstdio>
#include<cstdlib> 
#include<iostream>
#include <cstring>
using namespace std;

int  Map[1005][1005];
int n,m;
int main (){

    while(cin>>n>>m){
        memset(Map,0,sizeof(Map));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                char q;
                cin>>q;
                if(q=='#'){
                    Map[i][j]=1;
                }
                
            }
            
            
        }
        int ans=0;
        bool flag =true;
        for(int i=1;i<=n;i++){
            
            for(int j=1;j<=m;j++){
                int up=Map[i-1][j];
                int left=Map[i][j-1];
                int ul=Map[i-1][j-1];
                int now=Map[i][j];
                if(now==1&&left==0&&up==0)
                    ans++;
                else if(up+left+ul+now==3)
                {
                    flag=false;
                    break;
                }
            }
            if(!flag)
                break;
        }
        if(flag)
            cout<<"There are "<<ans<<" ships."<<endl;
        else
            cout<<"Bad placement."<<endl;
    }

}
