#include <cstdio>
#include <iostream>
using namespace std;


int main ()
{
	char str[40004];
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
		
		int len=strlen(str);
		printf("Case %d: ",cas);
		for(int i=len-1;i>=0;i--)
		cout<<str[i];
		cout<<endl;
		
		
	}
	

}
