#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long
int n,m;
ll dp[26][26];
ll C(int n,int m)
{
	ll ans=1;
	if(n>(m-n))
	{
	for(int i=n+1;i<=m;++i)ans*=i;
	//cout<<ans<<endl;
	for(int i=2;i<=m-n;++i)ans/=i;
	//cout<<ans<<endl; 
    }
    else
    {
    for(int i=m-n+1;i<=m;++i)ans*=i;
	//cout<<ans<<endl;
	for(int i=2;i<=n;++i)ans/=i;
	//cout<<ans<<endl; 
	}
	return ans;
}



int main ()
{
	
	int n,m;
	while(cin>>n>>m)
	{
		ll temp1=C(n,24+n);
		ll temp2=C(n-m,24+n-2*m)*C(m,2*m);
			cout<<temp1-temp2<<endl;
		
	}
	

}
