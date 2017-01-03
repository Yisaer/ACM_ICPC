#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

int flag[105];
int num[105];

int main ()
{
	int n,m;
	while(cin>>n>>m)
	{
		memset(flag,0,sizeof(flag));
		int cnt=n;
	//	cout<<"n="<<n<<endl;
		for(int i=1;i<=n;i++)
		{
			
			cin>>num[i];	
		}
		int N=0;
		int i=1;
		while(cnt!=1)
		{
		//	cout<<"cnt="<<cnt<<endl;
		//	cout<<"i="<<i<<endl;
			if(flag[i]==0)
			{
				N++;
			//	cout<<"N="<<N<<endl;
				if(N%m==0)
				{
					flag[i]=1;
					m=num[i];
				//	cout<<"m="<<m<<endl;
					cnt--;
					N=0;
				}
				
			}
			
			
			i++;
			if(i==n+1)
			i=1;			
		}
		int ans;
		for(int i=1;i<=n;i++)
		{
			if(flag[i]==0)
			{
			ans=i;	
			break;
		}
		}
		cout<<ans<<endl;
		
	}
	
	
	
}
