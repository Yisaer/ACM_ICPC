//  main.cpp
//  SHU1212 核电站问题
//
//  Created by 高松 on 15/12/21.
//  Copyright © 2015年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>
/*
int pos [20];
int len ;
int cnt = 0;
void dfs(int num,int sta){
    pos[num]=sta;
    if(num==len) {
        /*
        for(int i=1;i<=num;i++){
            if(i-1) cout<<" ";
            cout<<pos[i];
        }
        cout<<endl;
         */
/*
        bool flag =true;
        for(int i=1;i<=num;i++){
            if(pos[i]==1&&pos[i+1]==1&&pos[i+2]==1)
            {
             flag=false;
             break;
            }
        }
        if(flag==true)
            cnt++;
        return;
    }
    dfs(num+1,1);
    dfs(num+1,0);
}
*/

int P[50];
int main(int argc, const char * argv[]) {
    /*
    for( len=1;len<=10;len++){
        memset(pos,0,sizeof(pos));
        cnt =0;
        dfs(1,0);
        dfs(1,1);
        cout<<cnt<<endl;
    }
    */
    P[1]=2;
    P[2]=4;
    P[3]=7;
    P[4]=13;
    for(int i=5;i<=40;i++){
        P[i]=P[i-1]*2-P[i-4];
    }
    int n;
    while(cin>>n){
        cout<<P[n]<<endl;
    }
    
}

