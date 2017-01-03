int reverse(int);
int main ()
{
	int top;
	int L;
	scanf("%d",&L);
	for(top=1;top<=L;top++)
	{
		int n;
		scanf("%d",&n);
		int x;
		int i;
		for(i=1;i<=8;i++)
		{
		x=reverse(n);
		int sum;
		sum=x+n;
		int m;
		m=reverse(sum);
		if(m==sum)	break;
		else{
				n=sum;
				}
		}
		if(i==9)
		i=0;
		printf("%d\n",i);
	}
	return 0;
}
int reverse(int n)
{
	int k=0;
	int temp;
	temp=n;
	int x;
	while(temp!=0)
	{
		x=temp%10;
		temp/=10;
		k=k*10+x;
		
	}
	
	
	
	return k;
}
