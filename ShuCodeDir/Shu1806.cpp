#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
			  
int Y,M,D;
bool IsLeap(int );

int main ()
{
	int cas=0;
	while(cin>>Y>>M>>D)
	{
		cas++;
		int sum=0;
		for(int i=1;i<=M-1;i++)		
		{
			sum+=day[i]	;
			
		}
		sum+=D;
		if(IsLeap(Y))
		if(M>2||(M==2&&D==28))
		{
			sum++;
		}
		printf("Case %d: %02d/%02d/%04d, %d\n",cas,M,D,Y,sum);
	}	
	
	return 0;	
}


bool IsLeap(int y)
{
	bool Is=0;
	if(y%4==0&&y%100!=0||y%400==0)
	Is=1;
	
	
	return Is;	
	
}
