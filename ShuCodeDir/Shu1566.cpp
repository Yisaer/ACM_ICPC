#include <cstring>
#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;
#include <stack>

int const Maxn=10;
int vis[Maxn][Maxn];
int Map[Maxn][Maxn];
int par[Maxn][Maxn];
int dir[4][2] = { {1,0},{-1,0},{0,1},{0,-1}};

void bfs() {
	queue<int>q;
	vis[1][1]=1;
	q.push(1*10+1);
	while(!q.empty())
	{
		int m=q.front();
		q.pop();
		int x=m/10;
		int y=m%10;
		
		if(x==5&&y==5)
		{
	
			return ;
		}
		for(int i=0;i<4;i++)
		{
			int tx=x+dir[i][0];
			int ty=y+dir[i][1];
	
			
			if(tx<1||tx>5||ty<1||ty>5||vis[tx][ty]==1||Map[tx][ty]==1)
			{
		
			continue;
			}
		
			vis[tx][ty]=1;
			par[tx][ty]=10*x+y;
			q.push(10*tx+ty);
				
		}
	
	
	}
	
	
}


int main ()
{
	int T;
	cin>>T;
	int cas=0;
	while(T--)
	{
		cas++;
		memset(vis,0,sizeof(vis));
		memset(par,0,sizeof(par));
		memset(Map,0,sizeof(Map));
		for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
		{
			cin>>Map[i][j];
			
		}
		bfs();
		stack<int> s;
		s.push(55);
		int m=par[5][5];
		s.push(m);
		int x=m/10;
		int y=m%10;
		while(m!=0)
		{
			m=par[x][y];
			if(m==0)
			break;
			s.push(m);
			x=m/10;
			y=m%10;	
		}
		printf("Case %d:\n",cas);
		while(!s.empty())
		{
			int v=s.top();
			s.pop();
			int x=v/10;
			int y=v%10;
			cout<<"("<<x-1<<", "<<y-1<<")"<<endl;
		}
	
	}

	
}
