#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
int n,m;

ll C(int n,int m)
{
	ll ans=1;
	if(n>(m-n))
	{
	for(int i=n+1;i<=m;++i)ans*=i;

	for(int i=2;i<=m-n;++i)ans/=i;
	 
    }
    else
    {
    for(int i=m-n+1;i<=m;++i)ans*=i;

	for(int i=2;i<=n;++i)ans/=i;
 
	}
	return ans;
}

int main ()
{
	int n,m;
	while(cin>>n>>m)
	{
	
		cout<<C(m-1,n+m-1)<<endl;
	}
	
	
}
