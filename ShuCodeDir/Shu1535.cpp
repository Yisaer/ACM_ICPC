
int main()
{
	int top;
	int count;
	scanf("%d",&count);
	for(top=1;top<=count;top++)
	{
		int n;
		scanf("%d",&n);
		if(n==1)
		printf("Mission Complete!\n");
		else
		{
		
			long long x=0;
			int i;
			for(i=1;i<=n-1;i++)
			x+=i;
			if(x==1)
			printf("Needs at least %lld ATP!\n",x);
			else
			printf("Needs at least %lld ATPs!\n",x);
			
		}
		

	}
	return 0;
}
