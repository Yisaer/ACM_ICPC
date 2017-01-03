int main ()
{
	int a,b,c;
	int x;
	int y;
	int z;
	int count=0;
	while(scanf("%d%d%d",&a,&b,&c)==3)
	{
		int k=0;
		count++;
		printf("Case %d:\n",count);
		for(x=1;x<=(100-b-c)/a;x++)
		{
	
		if(k)break;
		for(y=(100-a-c)/b;y>=1;y--)
		{
			if(k)break;
		for(z=1;z<=(100-a-b)/c;z++)
		if(x*a+y*b+z*c==100&&x+y+3*z==100)
		{
			k=1;
			printf("%d %d %d\n",x,y,3*z);
			break;
		}
		}
		}
		if(k==0)
		printf("Impossible\n");
		
	}
	
	return 0;
}
