#include <iostream>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <cstring>
using namespace std;

int n;
double  x;

const int MAXN=12;

double Ratio[MAXN];
double Pro(int ,double); 

int main ()
{

	while(cin>>n>>x)	{
	memset(Ratio,0,sizeof(Ratio));

	double temp;
	for(int i=0;i<n+1;i++)
	{
	cin>>temp;
	Ratio[n-i]=temp;	
	}
	double sum=0;
	sum+=1.0*Ratio[0];
	for(int i=1;i<=n;i++)
	{
		double temp;
		temp=Pro(i,x);
		sum+=Ratio[i]*temp;	
		
	}
	printf("%.2lf\n",sum);
	}
	
	return 0;
}

double Pro(int index,double base)
{
	double pro=1.0;
	for(int i=1;i<=index;i++)
	{
		pro*=base;	
	}
	
		
	return pro	;
}
