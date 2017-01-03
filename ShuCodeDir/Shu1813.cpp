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
		
		int len=strlen(str);
		int cnt=0;
		for(int i=0;i<len;i++)
		if(str[i]==' ')
		cnt++;
		cout<<len-cnt<<' '<<cnt<<endl;
	
	}
	

}
