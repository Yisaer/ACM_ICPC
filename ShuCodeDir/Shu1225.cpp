int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	int i;
	int year,month,day;
	
	while(scanf("%d/%d/%d",&year,&month,&day)==3)
	{
		int res=0;
		for(i=1;i<=month-1;i++)
		res+=a[i];
		res+=day;
		
		if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		if(month>2)
		{
		res=0;
		for(i=1;i<=month-1;i++)
		res+=a[i];
		res++;
		res+=day;
		}
		printf("%d\n",res);
	}
	
	
	return 0;
}
