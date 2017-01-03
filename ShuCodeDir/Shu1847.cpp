int a[110][110];
int b[110][110];
int main ()
{
	int H;
	while(scanf("%d",&H)==1)
	{
		int i;
		int j;
		for(i=0;i<110;i++)
		for(j=0;j<110;j++)
		{
			a[i][j]=0;
			b[i][j]=0;
		}
		
		
		
		for(i=1;i<=H;i++)
		for(j=1;j<=2*i-1;j++)
		{
			scanf("%d",&a[i][j]);
		}
		for(i=1;i<=H;i++)
		for(j=1;j<=2*i-1;j++)
		{
			b[i][j]=a[i][j];
		}
		
		for(i=2;i<=H;i++)
		for(j=1;j<=2*i-1;j++)
		{
			b[i][j]=a[i][j]+b[i-1][j-1];
			if(b[i][j]<a[i][j]+b[i-1][j-2])
			b[i][j]=a[i][j]+b[i-1][j-2];
			if(b[i][j]<a[i][j]+b[i-1][j])
			b[i][j]=a[i][j]+b[i-1][j];
		}
		int max=0;
		for(j=1;j<=2*H-1;j++)
		if(b[H][j]>max)
			max=b[H][j];
		printf("%d\n",max);
	}
	return 0;
}
