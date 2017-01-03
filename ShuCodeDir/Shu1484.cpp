int main ()
{
	int a,b;
	int GCD,LCM;
	int ta,tb;
	int count=0;
	
	while (scanf("%d%d",&a,&b)==2){
		
		ta=a;
		tb=b;
		count++;
		if(ta==0&&tb==0)
		{
			//printf("Here1\n");
			printf("Case %d:\n",count);
			printf("no GCD\n");
			printf("no LCM\n");
		}
		else {
			//printf("Here2\n");
			if(a<0)
			{
				ta=-1*a;
			}
			if(b<0)
			{
				tb=-1*b;
			}
			int max,min;
			if(ta>tb)
			{
				max=ta;
				min=tb;
			}
			else{
				max=tb;
				min=ta;
			}
			int k=1;
			if(ta==0||tb==0)
			{
				GCD=max;
				k=0;
			}
			int i;
			if(k)
			{
			for(i=min;i>=1;i--)
			{
				//printf("H2L1");
				if(max%i==0&&min%i==0)
				{
				
				GCD=i;
				break;
				}
			}
			for(i=max;;i++)
			{
			//	printf("H2L2");
				if(i%max==0&&i%min==0)
				{
				LCM=i;
				break;
				}
			}
		}
			printf("Case %d:\n",count);
			printf("GCD(%d,%d) = %d\n",a,b,GCD);
			if(k)
			printf("LCM(%d,%d) = %d\n",a,b,LCM);
			else{
				printf("no LCM\n");
			}
			
		}
		
		printf("\n");
	}
	
	
	return 0;
}
