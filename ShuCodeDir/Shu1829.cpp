#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);	
	
}

int main ()
{
	int T;
	cin>>T;
	while(T--)
	{
	int a,b,c;
	cin>>a>>b>>c;
	int Max=max(a,b);
	int Min=min(a,b);
	int m=gcd(Max,Min);
	if(c%m)
	{
		cout<<"No"<<endl;	
	}
	else
	{
		cout<<"Yes"<<endl;	
	}
	
	
	}
	
	
}
