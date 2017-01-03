
int main ()
{
	int n,m;
	int x;
	long long res;
	while(scanf("%d%d",&n,&m)==2)
	{
		res=1;
		x=n;
		while(x>=n-m+1)
		{
		res*=x;
		x--;
		}
		int i;
		long long temp=1;
		for(i=1;i<=m;i++)
		temp=temp*i;
		long long  fin;
		fin=res/temp;
		printf("%lld\n",fin);
	}
	
	
	return 0;
}
