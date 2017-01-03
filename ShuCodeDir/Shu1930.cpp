using namespace std;
#include <cstring>
#include <cstdio>

int const Maxn=1e6+5;

int A[Maxn];
int dp[Maxn];
int main ()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n;i++)
		{
		cin>>A[i];
			
		}
		int Min=1001;
		for(int i=0;i<k;i++)
		{
			if(A[i]<Min)
			Min=A[i];
		}
		dp[0]=Min;
		for(int i=1;i<=n-k;i++)
		{
			if(dp[i-1]==A[i-1])
			{
				int Min=1001;
				for(int j=i;j<i+k;j++)
				{
					if(A[j]<Min)
					{
						Min=A[j];
					}
					dp[i]=Min;
				}
			
			}
			else if(A[i+k-1]<dp[i-1])
			{
				dp[i]=A[i+k-1];	
				
			}else dp[i]=dp[i-1];
		}
		
		for(int i=0;i<=n-k;i++)
		{
			if(i)
			cout<<" ";
			cout<<dp[i];	
		}
		cout<<endl;
	}
	
	
	return 0;	
}

