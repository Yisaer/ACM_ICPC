int main()
{
	
	char str[100];
	int i;
	while(gets(str)!=NULL)
	{
		i=0;
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]>='a'&&str[i]<='z')
				str[i]=str[i]-'a'+'A';
			
		}
			puts(str);
	}
	return 0;
}
