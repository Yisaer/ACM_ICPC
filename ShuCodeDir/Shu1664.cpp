long long san(long long);
int main()
{
	long long n;

	while(scanf("%lld",&n)==1)
	{
		long long i=0;
		long long res=1;
		while(res<=n)
		{
			res=res*3;
			i++;
		}
		i--;
		//printf("i=%d\n",i);
		long long x;
		long long temp;
		temp=n;
		long long  chu;
		long long sum=0;
		long long m;
		long long q=i;
		for(m=0;m<=q;m++)
		{
			chu=san(i);
			//printf("chu=%d\n",chu);
			x=temp/chu;
			temp=temp-x*chu;
			sum=sum*10+x;
			i--;
		}
		printf("%lld\n",sum);
	}
	
	return 0;
}
long long san(long long i)
{
	long long k=1;
	long long t;
	for(t=1;t<=i;t++)
	k*=3;
	
	return k;
}
