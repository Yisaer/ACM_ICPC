
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

#define Rep(i,n) for(int i=0;i<n;i++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define Test 	cout<<"here"<<endl;




int A[10010];
int n,m;
double b[10010];


double fun(int j)
{
	double res=0;
	int sum=0;

	
	for(int i=j;i<j+m;i++)
	{
		sum+=A[i];	
	}

	double T=sum*1.0/m;

	for(int i=j;i<j+m;i++)
	{
		
		res+=(A[i]-T)*(A[i]-T);
	}
	
	
	res=res/m;

	return res;	
	
	
}

int main ()
{
	while(cin>>n>>m)
	{
		
	Rep(i,n)
	{
		cin>>A[i];	
	}
	
	sort(A,A+n);


	for(int i=0;i<=n-m;i++)
	{
	b[i]=fun(i)	;	
	}


	
	double ans=INF;
	Rep(i,n-m+1)
	{
	if(b[i]<ans)
	ans=b[i];	
		
	}
	printf("%.2lf\n",ans);

		
	}
	
	
	
	return 0;	
}
