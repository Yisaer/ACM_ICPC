//  main.cpp
//  qqq
//
//  Created by 高松 on 16/4/9.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include<iostream>
#include<cstring>
#include <queue>
using namespace std;
int n,m;
int ZS,C;
char G[110][110];

bool vis[110][110][30];
int dir[4][2] = {1,0,-1,0,0,1,0,-1};

struct X{
    int t;
    int S;
    int x,y;
};

struct cmp{
    
      bool  operator  () (X a,X b){
        return a.t>b.t;
    }
};

int Sx,Sy;
int Fx,Fy;
int main()
{
    int T;
    cin >> T;
    while(T--){
        cin>>n>>m>>ZS>>C;
        memset(G,0,sizeof(G));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>G[i][j];
                if(G[i][j]=='S'){
                    Sx=i;
                    Sy=j;
                }
                if(G[i][j]=='T'){
                    Fx=i;
                    Fy=j;
                }
            }
        }
        int ans =-1;
        X F;
        F.x=Sx;
        F.y=Sy;
        F.t=0;
        F.S=ZS;
        memset(vis,0,sizeof(vis));
        vis[Sx][Sy][ZS]=1;
        priority_queue<X,vector<X> ,cmp> q;
        q.push(F);

        while(!q.empty()){
            
            
            
            X now = q.top();
            q.pop();
            int x = now.x;
            int y = now.y;
            int t = now.t;
            int S = now.S;
//            cout<<"t="<<t<<endl;
//            cout<<"x="<<x<<endl;
//            cout<<"y="<<y<<endl;
//            cout<<"s="<<S<<endl;
//            cout<<endl;
            
            
            
            if(x==Fx&&y==Fy){
                ans = t;
                break;
            }
            for(int i=0;i<4;i++){
                int tx= x+dir[i][0];
                int ty= y+dir[i][1];
                if(tx<0||tx>=n||ty<0||ty>=m||G[tx][ty]=='X'||vis[tx][ty][S])
                    continue;
                X next;
                next.x=tx;
                next.y=ty;
                if(G[tx][ty]=='D'){
                    if(S>=C){
                        int curS = S-C;
                        if(vis[tx][ty][curS])
                            continue;
                        vis[tx][ty][curS]=1;
                        next.S=curS+1;
                        next.t=t+2;
                        q.push(next);
                    }else{
                        int curs = S+1;
                        if(curs>ZS)
                            curs=ZS;
                        if(vis[tx][ty][curs])
                            continue;
                        vis[x][y][curs]=1;
                        next.S=curs;
                        next.t=t+1;
                        next.x=x;
                        next.y=y;
                        q.push(next);
                    }
                }
                else{
                    int curS = S+1;
                    if(curS>ZS)
                        curS=ZS;
                    if(vis[tx][ty][curS])
                        continue;
                    vis[tx][ty][curS]=1;
                    next.t=t+1;
                    next.S=curS;
                    q.push(next);
                }
                
                
            }
            
            
        }
        cout<<ans<<endl;
        
    }


}

