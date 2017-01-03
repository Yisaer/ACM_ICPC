int main()
{
	int n;
	int top;
	scanf("%d",&n);
	for(top=1;top<=n;top++)
	{
		int m;
		scanf("%d",&m);
		int i=0;
		int sum=1;
		while(sum<m)
		{
			sum*=2;
			i++;
			
		}
		printf("%d\n",i);
		
	}
	return 0;
}
