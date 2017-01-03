#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int M[22][22];

int num5(int x)
{
	int cnt=0;
	int m;
	do{
		m=x%5;
		x=x/5;
		if(!m)
		cnt++;	
		
		
	}while(m==0);
	
	return cnt;
	
}

int main ()
{
	
	int n;
	int cas=0;
	while(cin>>n)
	{
		cas++;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
				
			ans+=num5(i);
		}
		printf("Case %d:%d,%d\n",cas,n,ans);
		
		
	}
	
	
}
