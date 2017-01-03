#include <cstdio>
#include <iostream>
using namespace std;
char str[65540];

int main ()
{
	/*
	int T;
	cin>>T;
	int t=T;
	char q;
	q=getchar();
	*/
	int cas=0;
	while(gets(str))
	{
		cas++;
	//	gets(str);
		int cnt=0;
		int flag=0;
		for(int i=0;str[i]!='\0';i++)
		{
			if(str[i]>='0'&&str[i]<='9'&&flag==0)
			{
				flag=1;
				cnt++;
				
			}
			if((str[i]>'9'||str[i]<'0')&&flag)
			flag=0;
			
		}
		printf("Case %d: %d\n",cas,cnt);
	}
	

}
