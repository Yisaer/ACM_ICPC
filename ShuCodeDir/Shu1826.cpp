#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

bool Isprime (int n)
{
	if (n==1)
	return false;
	if(n==2)
	return true;
	for(int i=2;i*i<=n;	i++)
	{
		if(n%i==0)
		return false;	
	}
	return true;
	
}

int main ()
{
	int n;
	int cas=0;
	while(cin>>n)
	{
		cas++;
			printf("Case %d: ",cas);
		if(Isprime(n))
		{
			cout<<n<<" is a prime."<<endl;	
		}
		else
		{
			cout<<n<<" is not a prime."<<endl;
		}
	
	}
	
	
}
