#include <cstdio>
#include <iostream>
using namespace std;

int main ()
{
	
	int a,b,c;
	int cas=0;
	
	while(cin>>a>>b>>c)
	{
			
		cas++;
		printf("Case %d:\n",cas);
		for(int i=100/a;i>=1;i--)
		for(int j=100/b;j>=1;j--)
		for(int k=100/c;k>=1;k--)
		{
			if(i+j+3*k==100&&a*i+b*j+c*k==100)
			{
				
				cout<<i<<" "<<j<<" "<<3*k<<endl;	
				goto
				A;
					
				
			}
			
		}
		
		cout<<"Impossible"<<endl;
	A:
		continue;
	}
	
}
