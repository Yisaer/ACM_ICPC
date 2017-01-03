//  main.cpp
//  SHU P
//
//  Created by 高松 on 15/11/24.
//  Copyright © 2015年 伊萨. All rights reserved.
//
#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#include <queue>
int const Max=25;
int Map[Max][Max];
int m,n;
int sx,sy,fx,fy;
int ans;
int Step[Max][Max];
int Par[Max][Max];

bool flag;
int dir[4][2]={ {-2,1},{-1,2},{1,2},{2,1}};

void bfs()
{
    queue<int> Q;
    Q.push(sx*20+sy);
    flag=false;
    while(!Q.empty())
    {
        int val=Q.front();
        Q.pop();
        int x=val/20;
        int y=val%20;
      //  cout<<"val="<<val<<endl;
        if(x==fx&&y==fy)
        {
            flag=true;
            return ;
        }
        for(int i=0;i<4;i++)
        {
            int tx=x+dir[i][0];
            int ty=y+dir[i][1];
            if(Map[tx][ty]==1||tx<1||tx>m||ty<1||ty>n)
                continue;
       //     cout<<"tx="<<tx<<" ty="<<ty<<endl;
            Step[tx][ty]=Step[x][y]+1;
            Map[tx][ty]=1;
            Par[tx][ty]=x*20+y;
            Q.push(tx*20+ty);
        }
    }
    
    
    
}

int main(int argc, const char * argv[]) {
    
    while(cin>>m>>n)
    {
        memset(Map,0,sizeof(Map));
        memset(Step,0,sizeof(Step));
        memset(Par,0,sizeof(Par));
        
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                Map[i][j]=0;
            }
        cin>>sx>>sy>>fx>>fy;
        
        ans=0;
        bfs();
        if(flag)
        {
            cout<<Step[fx][fy]<<endl;
            int x;
            x=Par[fx][fy];
            while(x!=0)
            {
                int tx=x/20;
                int ty=x%20;
             //   cout<<tx<<" "<<ty<<endl;
                x=Par[tx][ty];
                
            }
            
            
        }
        else
            cout<<"Impossible"<<endl;
        
        
    }
    return 0;
}
