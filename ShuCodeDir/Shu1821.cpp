#include <cstdio>
#include <iostream>
#include <cctype> 
using namespace std;
char  str[1000000];

int main ()
{
	int n,m;
	while(cin>>n>>m)
	{
		cin>>str;
		for(int i=0;i<n;i++)
		{
			if(str[i]>='A'&&str[i]<='Z')
			{
			int index=str[i]-'A';
			int ans=(index+m)%26;
			str[i]='A'+ans;
			}
			if(str[i]>='a'&&str[i]<='z')
			{
			int index=str[i]-'a';
			int ans=(index+m)%26;
			str[i]='a'+ans;	
			}
		}
		cout<<str<<endl;
		
	}
	



}
