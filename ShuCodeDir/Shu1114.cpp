int main()
{
	int n,a;
	scanf("%d%d",&a,&n);
	int sum=0;
	int sum1=0;
	int i;
	for(i=1;i<=n;i++)
	{
		sum=sum*10+a;
		sum1+=sum;
	}
	printf("%d\n",sum1);
	
	return 0;
	
	
}
