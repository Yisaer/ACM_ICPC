int main()
{
	int n;
	int num;
	while((scanf("%d",&n))==1)
	{
		num=1;
		int i;
	
		for(i=1;i<=n-1;i++)
		{
			num=(num+1)*2;
			
		}
		printf("%d\n",num);
		
	}
	
	return 0;
}
