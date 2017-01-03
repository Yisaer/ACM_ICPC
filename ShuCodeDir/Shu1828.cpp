#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

int main ()
{
	int T;
	cin>>T;
	char str[100];
	char tem[100];
	while(T--)
	{
		cin>>str;
		int len=strlen(str);
		int L;
		if(len%3)
		{
			
			int P=3-len%3;
			for(int i=0;i<len;i++)
			{
				tem[i+P]=str[i];	
				
			}
			L=len;
			for(int i=0;i<P;i++)
			{
			tem[i]='0';
			L++;
			}
			
		}
		else
		{	L=len;
			for(int i=0;i<len;i++)
			tem[i]=str[i];	
			
		}
	

		int CNT=1;
		int sum=0;
		int num=0;
		int cnt=0;
		for(int i=0;i<L;i++)
		{
			cnt++;
			if(cnt%3)
			{
				num=num*10+tem[i]-'0';
			
			}
			else
			{
				num=num*10+tem[i]-'0';
				CNT++;
				if(CNT%2)
				{
					sum+=num;
				
				}
				else
				{
					sum-=num;
				}
				num=0;
				
			}
			
		}
	//	cout<<sum<<endl;
		if(sum%13)
		{
			cout<<"No"<<endl;
		}
		else
		{
			cout<<"Yes"<<endl;	
		}
			
	}
	
	
}
