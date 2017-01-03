int wu(int );
int main ()
{
	int m;
	scanf("%d",&m);
	int top;
	for(top=1;top<=m;top++)
	{
		
		int n;
	scanf("%d",&n);
	
		int sum=0;
		int x;
		int i;
		for(i=1;i<=n;i++)
		{
			x=wu(i);
			sum+=x;
			
		}
		printf("%d\n",sum);
		
		
	}
	return 0;
}
int wu(int n)
{
	int count=0;
	int k=0;
	do{
	if(n%5==0)
	{
	k=1;
	count++;
	n/=5;
	}else break;	
	}while(k);

	return count;
}
