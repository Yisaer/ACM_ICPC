#include <cstdio>
#include <iostream>
#include <cctype> 
using namespace std;
char  A[1000000];


int muti(int n,int x)
{
	int ans=1;
	for(int i=0;i<n;i++)
	ans*=x;
	
	
	return ans;
	
	
}

int main ()
{
	int cas=0;
	int n;
	int x;
	while(cin>>n>>x)
	{
		cas++;
		int t=n;
		int index=0;
		int tmuti=1;
		while(tmuti<=t)
		{
			index++;
			tmuti*=x;
			
		}
	//	cout<<index<<endl;
		index++;
		int j=0;
		while(index)
		{
			int l;
			l=t/muti(index-1,x);
			t%=muti(index-1,x);
			char q;
			if(l>=0&&l<=9)
			q=l+'0';
			else
			{
				q=l-10+'A';
				
			}
			A[j++]=q;
			index--;
		}
		A[j]='\0';
		printf("Case %d: ",cas);
		for(int i=1;A[i]!='\0';i++)
		{
			cout<<A[i];
		}
		cout<<endl;
	}
	
}
