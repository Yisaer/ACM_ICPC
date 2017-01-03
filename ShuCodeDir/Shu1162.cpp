int main()
{
	int n;
	int top;
	scanf("%d",&n);
	int AH,AM,AS,BH,BM,BS;
	for(top=1;top<=n;top++)
	{
		scanf("%d%d%d%d%d%d",&AH,&AM,&AS,&BH,&BM,&BS);
		int X=0;
		int Y=0;
		int Z=0;
		Z+=AS+BS;
		if(Z>=60)
		{
			Z=Z-60;
			Y++;
		}
		Y+=AM+BM;
		if(Y>=60)
		{
			X++;
			Y=Y-60;
		}
		X+=AH+BH;
		printf("%d %d %d\n",X,Y,Z);
		
		
		
	}
	
	return 0;
}
