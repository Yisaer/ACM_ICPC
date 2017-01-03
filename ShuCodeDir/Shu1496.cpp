int main()
{
	int n;

	int sum;
	int x;
	int temp;
	while ((scanf("%d",&n))==1)
	{
		sum=0;
		temp=n;
		while(temp!=0)
		{
			x=temp%10;
			sum+=x*x*x;
			temp/=10;
		}
		if(sum==n)
		printf("%d:YES\n",n);
		else
			printf("%d:NO\n",n);
		
}
	
	return 0;
}
