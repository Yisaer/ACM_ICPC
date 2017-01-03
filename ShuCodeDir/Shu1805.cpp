#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
 
int n;

int main ()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		double input;
		double MAX=0;
		double MIN=9999999;
		double sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>input;
			sum+=input;
			if(input>MAX)
			MAX=input;
			if(input<MIN)
			MIN=input;
				
		}
		sum-=(MAX+MIN);
		double avg;
		avg=sum/(n-2)*1.0;
		printf("%.2lf,%.2lf,%.2lf\n",MIN,MAX,avg);	
	
	}
	
	return 0;
}
