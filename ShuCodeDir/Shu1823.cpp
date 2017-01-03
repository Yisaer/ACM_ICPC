#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;

int main ()
{
	int n,m;
	int cas=0;
	while(cin>>n>>m)
	{
		cas++;
		if(m>n)
		{
		printf("Case %d: ",cas);
		cout<<"不存在"<<endl; 
		}
		else
		{
			int flag=0;
			int ans;
			for(int i=n;i>=2;i--)
			{
				if(i%m==0)
				{
					flag=1;
					ans=i;
					break;	
				}
				
				
			}
				if(flag)
				{
				printf("Case %d: ",cas);
				cout<<ans<<endl;
			}
				else
				{
					printf("Case %d: ",cas);
					cout<<"不存在"<<endl; 
					
				}
			
		}
	
	}
	
	
	
}
