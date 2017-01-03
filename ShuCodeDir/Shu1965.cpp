#include <cstdio>
#include <iostream>
using namespace std;
#include <algorithm>
#include <queue>
#define ll long long

ll  H[92];
int  q[100];
int  h[100];

int main ()
{
	
	H[1]=0;
	H[2]=0;
	H[3]=0;
	
	h[3]=1;
	q[3]=0;
	q[2]=1;
	h[2]=1;
	for(int i=4;i<=90;i++)
	{
		q[i]=q[i-2];
		h[i]=h[i-1];
		H[i]=H[i-1]+H[i-2];
		if(h[i-2]&&q[i-1])
		H[i]++;
	
	}
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		cout<<H[n]<<endl;	
		
	}
	
	
	
}
