#define _Shuoj1954_

#include<iostream>
#include<cmath>
#include <cstring>
#include <cstdio> 
#include <string>

using namespace std;

#define ll long long


int const Maxn=1000+10;

char Rec[Maxn][Maxn];

int n,m;





int main ()
{
	
	int T;
	cin>>T;
	while(T--)
	{
		
	
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		cin>>Rec[i][j];
		for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++)
		{
			if(i==0||j==0||i==n+1||j==m+1)
			Rec[i][j]=='x';	
			
		}
		
		
		
		int cnt=0;
		int Max=0;
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{	
			cnt=0;
		

			if(Rec[i][j]=='x')
			continue;
		
			for(int t=i+1;t<=n;t++)
			{
				if(Rec[t][j]=='x')
				break;
				cnt++;	
				
			}
			
			for(int t=i-1;t>=1;t--)
			{
				if(Rec[t][j]=='x')
				break;
				cnt++;
			}
		
			for(int t=j+1;t<=m;t++)
			{
				if(Rec[i][t]=='x')
				break;
				cnt++;
			}
			
			for(int t=j-1;t>=1;t--)
			{
				if(Rec[i][t]=='x')
				break;
				cnt++;	
			}
			
			Max=max(Max,cnt);
			
		}
			
	
		cout<<Max<<endl;
	
	
		
	}


	
	return 0;
}





#endif //_Shuoj1954_
