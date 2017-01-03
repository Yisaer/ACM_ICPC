int main()
{
	int n;
	int top;
	scanf("%d",&n);
	for(top=1;top<=n;top++)
	{
		int m;
		scanf("%d",&m);
		int x,y;
		int count=0;
		for(x=0;x<=m-1;x++)
		for(y=0;y<=(m-1)/2;y++)
		{
			if(x+2*y==m-1)
				count++;
			
		}
		printf("%d\n",count);
		
		
		
	}
	
	
	return 0;
}
