//  main.cpp
//  SHU1923 穿墙术
//
//  Created by 高松 on 15/12/24.
//  Copyright © 2015年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstdio>
#include <queue>
#include <cstring>
int const Maxn =22;
char Map[Maxn][Maxn];
int vis[Maxn][Maxn][Maxn];
int k;
int n,m;
int Sx,Sy,Fx,Fy;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int Time[Maxn][Maxn];
#define PII pair<int,int>
#define MP make_pair
#define X first
#define Y second
bool flag ;
void bfs(){
    queue<pair<PII,int> >q;
    
    q.push(MP(MP(Sx,Sy),0));
    vis[Sx][Sy][0]=1;
    while(!q.empty()){
        pair<PII,int> t=q.front();
        q.pop();
        int x =t.X.X;
        int y =t.X.Y;
        int cnt=t.Y;
//        cout<<"x="<<x<<" y="<<y<<" cnt="<<cnt<<endl;
//        cout<<"M="<<Map[x][y]<<endl;
//        cout<<endl;
        if(x==Fx&&y==Fy){
            flag =true;
            return;
        }
        if(Map[x][y]=='.'||Map[x][y]=='S')
        {
        for(int i=0;i<4;i++){
            int tx = x+dir[i][0];
            int ty=  y+dir[i][1];
            if(tx<0||ty<0||tx>=n||ty>=m||vis[tx][ty][cnt]==1)
                continue;
            if(Map[tx][ty]=='x'&&cnt<k){
                vis[tx][ty][cnt+1]=1;
                Time[tx][ty]=Time[x][y]+1;
                int tcnt=cnt+1;
                q.push(MP(MP(tx,ty),tcnt));
            }
            else if(Map[tx][ty]=='.'||Map[tx][ty]=='T'){
            vis[tx][ty][cnt]=1;
            Time[tx][ty]=Time[x][y]+1;
            q.push(MP(MP(tx,ty),cnt));
                
            }
        }
        }else if(Map[x][y]=='x'){
            for(int i=0;i<4;i++){
                int tx=x+dir[i][0];
                int ty=y+dir[i][1];
                if((Map[tx][ty]=='.'||Map[tx][ty]=='T')&&vis[tx][ty][cnt]==0)
                {
                    vis[tx][ty][cnt]=1;
                    Time[tx][ty]=Time[x][y]+1;
                    q.push(MP(MP(tx,ty),cnt));
                }
            }
            
        }
       
        
    }
    
    
}


int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>Map[i][j];
                if(Map[i][j]=='S'){
                    Sx=i;
                    Sy=j;
                }
                if(Map[i][j]=='T')
                {
                    Fx=i,Fy=j;
                }
            }
        }
//        cout<<endl;
//        for(int i=0;i<n;i++){
//            for(int j=0;j<m;j++){
//                cout<<Map[i][j];
//            }
//            cout<<endl;
//        }
        flag =false;
        memset(Time,0,sizeof(Time));
        memset(vis,0,sizeof(vis));
        bfs();
        if(flag)
            cout<<Time[Fx][Fy]<<endl;
        else
            cout<<-1<<endl;
        
    }
    return 0;
}
