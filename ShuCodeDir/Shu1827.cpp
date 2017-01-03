#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

int main ()
{
	int T;
	cin>>T;
	char str[100];
	while(T--)
	{
		cin>>str;
		int len=strlen(str);
		int sum=0;
		for(int i=0;i<len;i++)
		{
			if(i%2==0)
			{
				sum-=str[i]-'0';	
				
			}
			else
			{
				sum+=str[i]-'0';	
			}
		}
		if(sum<0)
		sum=-sum;
	//	cout<<sum<<endl;
		if(sum%11)
		{
			cout<<"No"<<endl;
		}
		else 
		{
			cout<<"Yes"<<endl;	
		}
		
		
	}
	
	
}
