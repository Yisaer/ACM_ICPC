int main ()
{
	char str1[100000];
	char str2[100000];
	while (scanf("%s%s",str1,str2)!=EOF)
	{
		int i=0,j=0;
		int k=1;
		for(;str1[i]!='\0';i++)
		{
		if(k)
		for(;str2[j]!='\0';j++)
		{
			if(str1[i]==str2[j])
			break;
			if(str2[j+1]=='\0')
			{
				k=0;
				break;
				
			}
		}
		else break;
		}
		if(k)
		printf("Yes\n");
		else	printf("No\n");
	}
	return 0;
}
