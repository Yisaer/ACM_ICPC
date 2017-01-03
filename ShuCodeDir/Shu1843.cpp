long long er(long long);
long long fan(long long);
int main()
{
	long long n;
	while(scanf("%lld",&n)==1)
	{
		long long i=0;
		long long res=1;
		while(res<=n)
		{
			res=res*2;
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
			chu=er(i);
		//	printf("chu=%lld\n",chu);
			x=temp/chu;
			temp=temp-x*chu;
			sum=sum*10+x;
			i--;
		}
		//printf("%lld\n",sum);
	long long ten=1;
	long long  count=0;
	while(sum%ten==0)
	{
		ten*=10;
		count++;
	}
	count--;
	ten=ten/10;
	sum=sum/ten;
	long long a;
	a=fan(sum);
	printf("%lld %lld\n",a,count);
		
	}
	
	
	return 0;
}
long long er(long long i)
{
	long long k=1;
	long long t;
	for(t=1;t<=i;t++)
	k*=2;
	
	return k;
}
long long fan(long long sum)
{
	long long k=0;
	long long x;
	long long er=1;
	long long temp=sum;
	while(temp!=0)
	{
		x=temp%10;
		temp/=10;
		k+=er*x;
		er*=2;
	}
	
	return k;
}
