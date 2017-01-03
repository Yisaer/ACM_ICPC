int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		if(n<0||n>100)
			printf("Score is error!\n");
		if(n<=59)
		printf("E\n");
		if(n<=69&&n>=60)
		printf("D\n");
		if(n<=79&&n>=70)
		printf("C\n");
		if(n<=89&&n>=80)
		printf("B\n");
		if(n<=100&&n>=90)
		printf("A\n");
		
		
	}

	return 0;
}
