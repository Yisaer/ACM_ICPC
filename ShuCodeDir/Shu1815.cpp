#include <cstdio>
#include <iostream>
using namespace std;
char str[65540];

int main ()
{

	int T;
	cin>>T;
	int t=T;
	char q;
	q=getchar();
	int cas=0;
	while(T--)
	{
		cas++;
		gets(str);
		int cnt=1;
		for(int i=0;str[i]!='\0';i++)
		{
			if(str[i]==' '&&str[i+1]!=' ')
			cnt++;
		}
		printf("Case %d: %d\n",cas,cnt);
		
	}
	

}
