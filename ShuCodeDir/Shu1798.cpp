
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a;
int n;
int Fun(int);


int main ()
{
	while(cin>>n>>a)
	{
		int sum=0;
		for(int t=1;t<=n;t++)
		{
			int temp;
			temp=Fun( t);	
			sum+=temp;
		}
	cout<<sum<<endl;
	}
	
	return 0;
}

int Fun(int t)
{
	int res=0;
	for(int i=1;i<=t;i++)
	{
		res=res*10+a;	
		
	}

	return res;
	
}
