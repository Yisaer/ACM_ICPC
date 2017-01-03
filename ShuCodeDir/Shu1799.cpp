#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;

const int MAXN=30;

int Tan[MAXN][MAXN];

int main()
{
	int cas=0;
	while(cin>>n)
	{
		cas++;
		memset(Tan,0,sizeof(Tan));
		for(int i=1;i<=n+1;i++)
		{
			Tan[i][1]=1;
			Tan[i][i]=1;	
		}
		for(int i=2;i<=n+1;i++)
		{
			for(int t=2;t<=n;t++)
			{
				Tan[i][t]=Tan[i-1][t]+Tan[i-1][t-1];
			}
			
		}
		printf("Case %d: n=%d\n",cas,n);
		for(int i=1;i<=n+1;i++)
		{
			if(i-1)
			cout<<" ";
			cout<<Tan[n+1][i];	
		}
		cout<<endl;
	}
	
	return 0;
}
