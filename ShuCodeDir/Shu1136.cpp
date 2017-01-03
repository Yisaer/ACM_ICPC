int fun(int ,int);
int main()
{
	int n;
	scanf("%d",&n);
	int top;
	for(top=1;top<=n;top++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		int k1;
		int k2;
		k1=fun(a,b);
		k2=fun(b,a);
		if(k1&&k2)
		printf("YES\n");
		else printf("NO\n");
		
		
	}
	
	
	
	return 0;
}
int fun(int a,int b)
{
	int k=0;
	int i;
	int sum=0;
	for(i=1;i<=a/2;i++)
	{
		if(a%i==0)
		sum+=i;
	}
	if(sum==b)
	k=1;
	return k;
	
}
