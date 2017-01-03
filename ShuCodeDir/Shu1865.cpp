int main()
{
	char str[10000];
	int i=0;
	
		scanf("%[^\1]",str);
		int count=0;
		for(i=0;str[i]!='\0';i++)
		if(str[i]>='a'&&str[i]<='z')
		str[i]=str[i]-'a'+'A';

		for(i=0;str[i]!='\0';i++)
		if(str[i]=='Y'&&str[i+1]=='A'&&str[i+2]=='O'&&str[i+3]=='G'&&str[i+4]=='E')
		count++;
		printf("%d\n",count);
		
	
	
	
	return 0;
}
