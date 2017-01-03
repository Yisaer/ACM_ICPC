//  main.cpp
//  SHU 1917 机关迷宫
//
//  Created by 高松 on 15/12/21.
//  Copyright © 2015年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
int const Maxn = 100+5;
char Map[Maxn][Maxn];
int n,m;


int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>Map[i][j];
        int cnt= 0;
        bool flag=false;
        bool Flag=true;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                if(Map[i][j]!='.'){
                    flag =false;
                    if(Map[i][j]=='>'){
                        for(int t=j+1;t<m;t++){
                            if(Map[i][t]!='.')
                            {
                                flag=true;
                                break;
                            }
                        }
                    }
                    if(Map[i][j]=='^'){
                        for(int t=i-1;t>=0;t--){
                            if(Map[t][j]!='.')
                            {
                                flag=true;
                                break;
                            }
                        }
                        
                    }
                    if(Map[i][j]=='v'){
                        for(int t=i+1;t<n;t++){
                            if(Map[t][j]!='.')
                            {
                                flag=true;
                                break;
                            }
                        }
                        
                    }
                    if(Map[i][j]=='<'){
                        for(int t=j-1;t>=0;t--){
                            if(Map[i][t]!='.')
                            {
                                flag=true;
                                break;
                            }
                        }
                        
                    }
                    if(flag==false){
                        Flag=0;
                        for(int x=0;x<n;x++){
                            if(Flag)
                                break;
                            for(int y=0;y<m;y++){
                                if(x==i&&y==j)continue;
                                if(x==i||y==j){
                                    if(Map[x][y]!='.')
                                    {
                                        Flag =1;
                                        cnt++;
                                        break;
                                    }
                                }
                            }
                        }
                        if(Flag==false){
                            cout<<"Sad Bobby!"<<endl;
                            goto A;
                        }
                    }
                }
            }
        cout<<cnt<<endl;
    A:continue;
    }
    
}
