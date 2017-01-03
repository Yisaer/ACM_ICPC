#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

#define Rep(i,n) for(int i=0;i<n;i++)
#define MEM(array,n) memset(array,n,sizeof(array))
#define NUM(x,y,z)   100*x+10*y+z

string s;

int main ()
{
	while(cin>>s)
	{
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]>='A'&&s[i]<='Z')
		s[i]=s[i]-'A'+'a';
		
	}
	
	
	int i;
	int x=-1;
	for(i=0;s[i]!='\0';i++)
	{
	
	if(s[i]=='b'&&s[i+1]=='o'&&s[i+2]=='b')
	{
	x=i;
	break;
	}
		
	}
	if(x>=0)
	{
	cout<<x<<endl;
	
	}
	else
	cout<<x<<endl;
		
		
		
	}
	
	
	
	
	return 0;
}
