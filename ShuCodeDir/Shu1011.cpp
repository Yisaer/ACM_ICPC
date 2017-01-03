#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

#define ll long long

int const Maxn=20+2;

ll A[Maxn];


int n,k;
int ans;

bool Isprime(ll x)
{
	if(x==1)
	return 0;
	if(x==2)
	return 1;
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		return 0;
		
	}
	
	return 1;

}

void dfs(int cur,int cnt ,ll sum)
{
	if(cur>n||cnt>k)
	return ;

	if(cnt==k)
	{
		if(Isprime(sum))
		{
			ans++;	
					
		}
		return ;
		

	}
	for(int i=cur;i<=n;i++)
	dfs(i+1,cnt+1,sum+A[i+1]);
	
}


int main ()
{
	while(cin>>n>>k)
	{
	ans=0;
	for(int i=1;i<=n;i++)
	cin>>A[i];


	dfs(0,0,0);
	cout<<ans<<endl;	
		
	}
	
	return 0;
}
