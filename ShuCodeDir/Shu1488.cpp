int a[1010];
int main()
{
	int n;
	int top;
	scanf("%d",&n);
	for(top=1;top<=n;top++)
	{
		
		int i=0;
		char q;
		while(scanf("%d",&a[i])!=EOF&&scanf("%c",&q)&&q!='\r'&&q!='\n')
		{
			i++;
		}
		printf("Case %d:\n",top);
		int n=++i;
		printf("Before sorting:\n");
		int x=0;
		for(i=n-1;i>0;i--)
		{
		x++;
			if(x%10==0)
				printf("%d\n",a[i]);
			else printf("%d ",a[i]);
		}
		printf("%d",a[i]);
		printf("\n");
		int j;
		int temp;
		for(i=0;i<n;i++)
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]<a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				
			}
		}
		printf("After sorting:\n");
		x=0;
		for(i=0;i<n-1;i++)
		{
			x++;
			if(x%10==0)
				printf("%d\n",a[i]);
			else printf("%d ",a[i]);
			
		}
		printf("%d",a[i]);
		printf("\n");
		
	}
	
	
	return 0;
}
