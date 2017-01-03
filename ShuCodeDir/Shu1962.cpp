//  main.cpp
//  SHU1962 water and fire
//
//  Created by 高松 on 15/12/23.
//  Copyright © 2015年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <queue>

int n,m;
int const Maxn = 100+5;
char Map[Maxn][Maxn];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
#define Z(a,b,c) (100*100*a+100*b+c)
#define P(a)  push(a)
int Time[Maxn][Maxn][2];
int Sx,Sy;
int Fx,Fy;
int sta;
bool flag;
#define Max 0x3f3f3f3f
#define PII pair<int ,int>
#define MP make_pair
#define X first
#define Y second


bool Is(int x, int y,int z){
    if(Map[x][y]=='#') return false;
    if(Map[x][y]=='~'&& z==1) return false;
    if(Map[x][y]=='w'&& z==0) return false;
    return true;
    
    
}

void bfs(){
    Time[Sx][Sy][0]=0;
    queue< pair<PII,int> > q;
    q.P(MP(MP(Sx,Sy),0));
    while(!q.empty()){
        pair<PII,int> u = q.front();
        q.pop();
        PII v=u.X;
        int z=u.Y;
        int x=v.X;
        int y=v.Y;
        /*
        cout<<"x="<<x<<" y="<<y<<" z="<<z<<endl;
        cout<<"T="<<Time[x][y][z]<<endl;
        cout<<endl;
         */
        if(Map[x][y]=='T'){
        //    cout<<"find"<<endl;
            sta=z;
            flag =true;
            return;
        }
        for(int i=0;i<4;i++){
            int tx=x+dir[i][0];
            int ty=y+dir[i][1];
            if(tx<0||tx>=n||ty<0||ty>=m)continue;
            if(!Is(tx,ty,z)) continue;
            if(Time[tx][ty][z]==Max){
                Time[tx][ty][z]=Time[x][y][z]+1;
                q.P(MP(MP(tx,ty),z));
                
            }
            
        }
        if(Map[x][y]=='@'){
            if(Time[x][y][z^1]==Max){
                Time[x][y][z^1]=Time[x][y][z]+1;
                q.P(MP(MP(x,y),z^1));
                
            }
            
        }
            
    }
        
}
    




int main(int argc, const char * argv[]) {
   
    
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
         {
                cin>>Map[i][j];
                if(Map[i][j]=='S'){
                    Sx=i;
                    Sy=j;
                }
                if(Map[i][j]=='T')
                {
                    Fx=i;
                    Fy=j;
                }
         }
        flag=0;
        memset(Time,Max,sizeof(Time));
        flag =false;
        bfs();
        if(flag)
            cout<<Time[Fx][Fy][sta]<<endl;
        else
            cout<<"Sad Yaoge!"<<endl;
    }
    
    
    return 0;
}
