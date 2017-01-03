#include <cstdio>
#include <cstring>
#include <algorithm> 
using namespace std;


#define ll long long
ll a[1010];
int flag;
ll  S;




int main ()
{
	int n;

	while(cin>>n>>S)
	{
		flag=0;
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);

		}	
		sort(a,a+n);
	
		for(int i=0;i<n-2;i++)
		for(int j=i+1;j<n-1;j++)
		{
			int L=j+1;
			int R=n-1;
			long long Ts=a[i]+a[j];
			while(L<R)
			{
				int mid=(L+R)/2;
				ll sum=Ts+a[mid];
				if(sum==S)
				{
					flag=1;
					break;
				}
				if(sum<S)
				{
				 L=mid+1;	
					
				}
				else R=mid-1;
				
				
			}
			
			
			
			
			
			
			
			
			
			
			if(flag)
			break;
		}

		if(flag)
		printf("YES\n");
		else
		printf("NO\n");
		
		
	}
	
	
	
	return 0;	
}
