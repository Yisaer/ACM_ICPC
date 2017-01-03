int main ()
{
	int n;
	scanf("%d",&n);
	int top;
	char str[100];
	char res[100];
	for(top=1;top<=n;top++)
	{
		scanf("%s",str);
		int i;
		int x=0;
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]!='_')
			{
				res[x++]=str[i];
				if(str[i-1]=='_')
				{
				x--;
				res[x]=res[x]-'a'+'A';
					x++;
				}
				
			}
		}
		res[x]='\0';
		printf("Case %d:\n",top);
		puts(res);
	
	}
	
	
	
	return 0;
}
