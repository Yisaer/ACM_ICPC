int a[1001];
int main()
{
	int top;
	int n;
	scanf("%d",&n);
	char q;
	int i;
	int k;
	int maxindex;
		int minindex;
		int max;
		int min;
		int sum;
		
	for(top=1;top<=n;top++)
	{
		k=1;
		i=1;
		while(scanf("%d",&a[i])!=EOF&&scanf("%c",&q)&&q!='\r'&&q!='\n')
		{
			i++;
		}
		int m=i;
		if(m<=2)
		k=0;
		if(m==3)
		{
			sum=a[1]+a[2]+a[3];
			max=sum;
			min=sum;
			maxindex=1;
			minindex=1;
			
		}
		if(m>3)
		{ 
			max=a[1]+a[2]+a[3];
		 maxindex=1;
 	   min=a[1]+a[2]+a[3];
		 minindex=1;
 	   for(i=2;i<=m-2;i++)
  	   {
  	   	sum=a[i]+a[i+1]+a[i+2];
  	   	if(sum>max)	
		{
			 
	 		 max=sum;
	 		 maxindex=i;
		}
  	   	if(sum<min) 
			 {
		 	minindex=i;
			 min =sum;
			 }
	   	}
	   	int sum1,sum2;
	   	sum1=a[1]+a[m-1]+a[m];
	   	if(sum1>max)	
		   {
		   max=sum1;
		   maxindex=m-1;
		   }
	   	if(sum1<min)	
		   {
		   min=sum1;
		   minindex=m-1;
		   }
	   	sum2=a[m]+a[2]+a[1];
		if(sum2>max)	
		{
		max=sum2;
		maxindex=m;
		}
		if(sum2<min)	
		{
		 min=sum2;
		 minindex=m;
		 }
			
			
		}
		printf("Case %d:\n",top); 
		if(k)
	 	printf("maximum = %d, minimum = %d, MaxIndex = %d, MinIndex = %d\n",max,min,maxindex,minindex);
		else printf("No maximal and minimal!\n");
	}
	
	return 0;
}
