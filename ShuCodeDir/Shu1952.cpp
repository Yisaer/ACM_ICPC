#include <cstring>
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
#define ll long long
ll A[100010];

int main ()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		ll temp=0;
		for(int i=1;i<=n;i++)
		{
			int a;
			scanf("%d",&a);
			if(a%2)
			{
				temp++;
				A[i]=temp;	
			}
			else A[i]=A[i-1];
			
			
		}
		while(q--)
		{
			int l,r;
			ll  ans;
			scanf("%d%d",&l,&r);
			if(l==1)
			{
			
			ans=A[r]*(r-l+1-A[r]);	
			}
			else
			ans=(A[r]-A[l-1])*(r-l+1-(A[r]-A[l-1]));
			printf("%lld\n",ans);
		}
	
	}
	
	return 0;
}
