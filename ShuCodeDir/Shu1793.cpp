#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n;
const int MAXN=100+10;

int a[MAXN][MAXN];
int b[MAXN][MAXN];

int main ()
{
	cin>>n;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	cin>>a[i][j];
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	cin>>b[i][j];
	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	b[i][j]+=a[i][j];
	
	for(int i=0;i<n;i++)
	{
	for(int j=0;j<n;j++)
	{
		if(j)
		cout<<" ";
		cout<<b[i][j];	
	}
	cout<<endl;
	}
	
	return 0;
	
}
