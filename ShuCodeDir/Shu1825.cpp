#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);	
	
}


bool Isprime(int x,int y)
{
	
		int Max=max(x,y);
		int Min=min(x,y);
		if(gcd(Max,Min)==1)
		return true;
		return false;
	
	
}

int main ()
{
	int n,m;
	int cas=0;
	while(cin>>n>>m)
	{
		cas++;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(Isprime(i,m))
			cnt++;
			
		}
		printf("Case %d: ",cas);
		cout<<cnt<<endl;
	
	}
	
	
	
}
