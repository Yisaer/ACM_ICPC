int main()
{
	int m,n;
	int f[1010],g[1010];
	int i;
	scanf("%d%d",&m,&n);
	for(i=0;i<m;i++)
	{
		scanf("%d",&f[i]);
	}
	for(i=0;i<n;i++)
	scanf("%d",&g[i]);
	int x;
	int j;
	int min;
	min=20000;
	for(i=0;i<m;i++)
	for(j=0;j<n;j++)
	{
		x=f[i]-g[j];
		if(x<0)
		x=-1*x;
		if(x<min)
		min=x;
	}
	printf("%d\n",min);
	return 0;
}
