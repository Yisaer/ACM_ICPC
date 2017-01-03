
int  main ()
{
	int L,m;
	int i;
	int top;
	while(scanf("%d%d",&L,&m)==2)
	{
	int a[10001]={0};
	for(top=1;top<=m;top++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		int j;
		for(j=x;j<=y;j++)
		a[j]=1;
		
	}
	int count=0;
	for(i=0;i<=L;i++)
	if(a[i]==0)
	count++;
	printf("%d\n",count);
}
	return 0;
}
