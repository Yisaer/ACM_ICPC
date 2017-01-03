int you (char*,int);
int main ()
{
	char str[2010];
	int count =0;
	int x;
	while (gets(str)!=NULL)
	{

		int i;
		count++;
		printf("Case %d:\n",count);
		int k;
		k=0;
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]=='0'&&(str[i+1]<'0'||str[i+1]>'9')&&(str[i-1]<'0'||str[i-1]>'9'))
				printf("%c",str[i]);
			if(str[i]>='1'&&str[i]<='9')
			{
				k=1;
				printf("%c",str[i]);
			}			
			if(str[i]=='0'&&k)
			printf("%c",str[i]);
			if((str[i]<'0'||str[i]>'9')&&(str[i-1]>='0'&&str[i-1]<='9')&&k)
			{
			k=0;
			x=you(str,i);
				if(x)
			printf(" ");
	
			}
			if((str[i]<'0'||str[i]>'9')&&str[i-1]=='0'&&(str[i-2]<'0'||str[i-2]>'9'))
			{
				x=you(str,i);
				if(x)
				printf(" ");
			}
			if((str[i]<'0'||str[i]>'9')&&str[i]=='0'&&str[i+1]=='\0')
				printf("%c",str[i]);
		}
		printf("\n");
	}
		
	return 0;
}
int you(char*str,int n)
{
	int i;
	int k=0;
	for(i=n;str[i]!='\0';i++)
	{
		if(str[i]>='1'&&str[i]<='9')
		{
			k=1;
			return k;
		}
		if(str[i]=='0'&&str[i+1]>'9'&&str[i+1]<'0')
				{
			k=1;
			return k;
		}

	}
	return k;
}
