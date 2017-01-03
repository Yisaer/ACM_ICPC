//  main.cpp
//  SHU1556  三角迷宫
//
//  Created by 高松 on 15/12/2.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>
int Map[10][10];
//int vis[10][10];
int par[10][10];
bool flag;
void dfs(int x,int y)
{
    
   // cout<<"x="<<x<<" y="<<y<<endl;
   // cout<<"Map["<<x<<"]["<<y<<"]="<<Map[x][y]<<endl;
   // cout<<endl;
    int m=par[x][y];
    while(m>0)
    {
        int tx=m/10;
        int ty=m%10;
        if(Map[x][y]==Map[tx][ty])
        {
            return;
        }
        m=par[tx][ty];
    }
    /*
    cout<<"pass"<<endl;
    cout<<endl;
     */
    if(x==9)
    {
        flag=true;
        return;
    }
    par[x+1][y]=x*10+y;
    dfs(x+1,y);
    par[x+1][y+1]=x*10+y;
    dfs(x+1,y+1);

    
}


int main(int argc, const char * argv[]) {

    int T;
    int cas=0;
    cin>>T;
    while(T--)
    {
        cas++;
        memset(Map,0,sizeof(Map));
        memset(par,0,sizeof(par));
        for(int i=1;i<=9;i++)
        {
           
            for(int j=1;j<=i;j++)
            {
                cin>>Map[i][j];
            }
            
        }
        flag=false;
        par[1][1]=0;
        par[0][0]=-1;
        dfs(1,1);
        cout<<"Case "<<cas<<":"<<endl;
        if(flag)
            
            cout<<"Possible"<<endl;
        else
            cout<<"Impossible"<<endl;
    }
    
    return 0;
}

