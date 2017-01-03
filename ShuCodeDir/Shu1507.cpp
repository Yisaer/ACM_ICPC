void West(int *,int *,int *);
void South(int *sh,int *nan ,int *don);
void North(int *sh,int *nan,int*don);
void East(int *sh,int *nan ,int *don);
int main ()
{
	int n;
	int sh;
	int nan;
	int don;
	char str[1000];
	int count=0;
	while((scanf("%d",&n))==1)
	{
		count++;
		sh=1;
		nan=2;
		don=3;
		int i;
		scanf("%s",str);
		for(i=0;i<n;i++)
		{
			
			switch (str[i])
			{
				case 'W': West(&sh,&nan,&don);  break;
				case 'S':	South(&sh,&nan,&don); break;
				case 'N':	North(&sh,&nan,&don); break;
				case 'E':	East(&sh,&nan,&don);   break;
			}
			
			
		}
		printf("Case %d:%d\n",count,sh);
		
		
	}
	
	return 0;
}
void West(int *sh,int *nan,int*don)
{
	int temp;
	temp=*sh;
	*sh=*don;
	*don=7-temp;
}
void South(int *sh,int *nan ,int *don)
{
	int t1;
	int t2;
	t1=*nan;
	t2=*sh;
	*sh=7-t1;
	*nan=t2;
}
void North(int *sh,int *nan,int*don)
{
	int t1;
	int t2;
	t1=*nan;
	t2=*sh;
	*sh=t1;
	*nan=7-t2;
	
}
void East(int *sh,int *nan ,int *don)
{
	int t1,t2;
	t1=*don;
	t2=*sh;
	*sh=7-t1;
	*don=t2;
	
}
