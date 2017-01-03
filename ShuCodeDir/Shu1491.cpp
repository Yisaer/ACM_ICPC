int a[1010];
int main ()
{
	int n;
	while(scanf("%d",&n)==1)
	{
	a[0]=25;
	a[1]=-25;
	int i;
	for(i=2;i<n;i++)
	{	
	a[i]=((a[i-1]*4627+a[i-2]*3581)/100)%100-50;	
	}
	

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
	for(i=0;i<n-1;i++)
	printf("%d ",a[i]);
	printf("%d\n",a[i]);
	
	
	}
	
	
	return 0;
}

