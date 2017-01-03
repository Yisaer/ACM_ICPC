int a[31];
int b[31];
int main ()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		int i;
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		for(i=0;i<n;i++)
		scanf("%d",&b[i]);
		int j;
		int temp;
		for(i=0;i<n;i++)
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
				
			}
			
		}
		for(i=0;i<n;i++)
		for(j=0;j<n-1-i;j++)
		{
			if(b[j]>b[j+1])
			{
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
				
			}
			
		}
		
		int sum=0;
		for(i=0;i<n;i++)
		sum+=a[i]*b[i];
		printf("%d\n",sum);
		
	}
	
	
	return 0;
}
