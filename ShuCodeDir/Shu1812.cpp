#include <cstdio>
#include <iostream>
using namespace std;


int main ()
{
	char str[105];
	int T;
	cin>>T;
	int t=T;
	char q;
	q=getchar();
	while(T--)
	{

		gets(str);
		
		for(int i=0;str[i]!='\0';i++)
		{
			if(str[i]>='a'&&str[i]<='z')
			str[i]=str[i]+'A'-'a';
			
		}
		puts(str);
	
	
	}
	

}
