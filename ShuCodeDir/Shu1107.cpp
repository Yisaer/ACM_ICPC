#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int t[4];
bool cmp (int a,int b)
{
	
	return a<b;	
}

int main ()
{
		int a,b,c,d;
	while(cin>>a>>b>>c>>d)
	{
		t[0]=a;
		t[1]=b;
		t[2]=c;
		t[3]=d;	
		sort(t,t+4,cmp);
		for(int i=0;i<4;i++)
		{
			if(i)
			cout<<' ';
			cout<<t[i];	
		}
		
		
	}
	
	
}
