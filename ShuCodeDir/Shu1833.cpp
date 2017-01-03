#include <cstring>
#include <iostream>
using namespace std;
#define ll long long
int main ()
{
	int n,m;
	while(cin>>n>>m)
	{
		ll temp1=1;
		for(int i=m-1;i>=1;i--)
		temp1*=i;
		
		ll temp2=1;
		for(int i=m;i>=m-n+1;i--)
		temp2*=i;
		
		ll ans;
		ans=temp1*temp2;
		cout<<ans<<endl;
	
	
	}
	
	
}
