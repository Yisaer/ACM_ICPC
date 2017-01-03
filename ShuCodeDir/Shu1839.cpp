#include <iostream>
using namespace std;
#include <cstring>
int const maxn=68;

char num1[maxn];
char num2[maxn];
int str1[maxn];
int str2[maxn];


int main ()
{
	while(cin>>num1>>num2)
	{
		memset(str1,0,sizeof(str1));
		memset(str2,0,sizeof(str2));
		
		int len1=strlen(num1);
		int len2=strlen(num2);
		int j=len1-1;
		for(int i=0;i<len1;i++)
		{
		str1[i]=num1[j--]-'0';
		
		}
		str1[len1]='\0';
		j=len2-1;
		for(int i=0;i<len2;i++)
		{
		str2[i]=num2[j--]-'0';
		
		}
		str2[len2]='\0';
		
		int ans[maxn];
		memset(ans,0,sizeof(ans));
		for(int i=0;i<max(len1,len2);i++)
		{
			ans[i]+=str1[i]+str2[i];
			
			if(ans[i]>=10)
			{
				ans[i]-=10;
				ans[i+1]++;	
			}
		
		}
	
		int Max=max(len1,len2);
		if(ans[Max])
		{
			Max++;	
		}
		ans[Max]='\0';
		int tans[maxn];
		j=Max-1;
		for(int i=0;i<Max;i++)
		{
			tans[i]=ans[j--];	
		}
		tans[Max]='\0';
		cout<<num1<<"+"<<num2<<"=";
		for(int i=0;i<Max;i++)
		cout<<tans[i];
		cout<<endl;
		
	
	
	}
	
	
	
	
}
