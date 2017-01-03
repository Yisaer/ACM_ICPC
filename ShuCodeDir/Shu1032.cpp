#include <cstdio>
#include <iostream>
using namespace std;
int const Max=105;
char str[Max];
char ans[Max];


int main ()
{
	while(gets(str))
	{
	
		int len=strlen(str);
		for(int j=len-1;j>=0;j--)
		{
			cout<<str[j];
		
		}
		cout<<endl;
	}
	
	
	
}
