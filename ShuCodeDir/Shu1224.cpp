int main()
{
	int a[100];
	int n;
	int top;
	scanf("%d",&n);
	int m;
	for(top=1;top<=n;top++)
	{
		scanf("%d",&m);
		int i;
		for(i=0;i<m;i++)
		scanf("%d",&a[i]);
		int j;
		int temp;
		for(i=0;i<m;i++)
		for(j=0;j<m-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
		int x=a[1]-a[0];
		for(i=1;i<m;i++)
		{
			if((a[i]-a[i-1])!=x)
			break;
		}
		if(i==m)
			printf("yes\n");
		else	printf("no\n");
	}
	
	return 0;
}
