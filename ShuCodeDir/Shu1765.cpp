void print(int);
int main ()
{
	int Z;
	scanf("%d",&Z);
	int top;
	for(top=1;top<=Z;top++)
	{
	
		int m,n;
		scanf("%d%d",&n,&m);
		printf("Case %d:\n",top);
		int i;
		for(i=1;i<=n;i++)
		{
			print(m);
			if(m==1)
			m=2;
			else
			m=1;
			
		}
		
	}
	
	return 0;
}

void print(int i)
{
	if(i==1)
	printf("1-2-1 1-2-1 1 1 1-2-1\n");
	else
	printf("1 2 3 4 1-2-3 4\n");
	
}

