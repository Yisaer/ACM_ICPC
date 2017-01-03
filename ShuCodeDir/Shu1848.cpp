int cmp(int ,int );
int a[1010];
int b[1010];
int main ()
{

	int q;
	int m,n;
	scanf("%d%d",&n,&m);

	int i;
	for(i=1;i<=n;i++)
	scanf("%d",&a[i]);
	for(q=1;q<=m;q++)
	scanf("%d",&b[q]);
	
	
	int j=1;
	i=1;
	int k;
	for(;;)
	{
	//	printf("a[i]=%d,b[j]=%d",a[i],b[j]);
		k=cmp(a[i],b[j]);
	//	printf("k=%d\n",k);
		if(k==1)
		{
			j++;
		}
		if(k==2)
		i++;
		if(k==3)
		{
			i++;
			j++;
		}
		if(k==4)
		break;
		if(j>m)
		break;
		if(i>n)
		break;
	//	printf("i=%d,j=%d\n",i,j);
	}
	if(k!=4)
	{
	if(i>n&&j<=m)
	printf("Second\n");
	if(i>n&&j>m)
	printf("Draw\n");
	if(j>m&&i<=n)
	printf("First\n");
	}
	else printf("Draw\n");
	return 0;
}
int  cmp(int i,int j)
{
	
	int k;
	if(i>=32&&i<=40&&j>=32&&j<=40)
	{
		if(i>j)
		k=1;
		else if(i==j)
		{
			k=3;
		}
		else if(i<j)
		k=2;
	}
	if(i==30||j==30)
	k=3;
	
	if(i==31&&j>32&&j<=40)
	k=1;
	if(j==31&&i>32&&i<=40)
	k=2;
	if(i==31&&j==32)
	k=2;
	if(j==31&&i==32)
	k=1;
	if(i==31&&j==31)
	k=4;
//	printf("Enter k =%d\n",k);
	return k;
}
