#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

int main ()
{
	
	int T;
	cin>>T;
	while(T--)
	{
		int S,Q;
		cin>>S>>Q;
		if(Q==0)
		cout<<S<<endl;
		else 
		{
		if(S==2)
		{
			
			if(Q&1)
			{
				cout<<1<<endl;
				
			}else
			{
				
				cout<<2<<endl;
			}
			
		}
		else 
		{
			if(Q&1)
			{
				cout<<2<<endl;	
			}
			else
			{
				cout<<1<<endl;
				
			}
		}
		
	
	
	}
}
	
	
	
	return 0;
}
