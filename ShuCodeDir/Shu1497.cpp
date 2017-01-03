int main()   
{   
	char str[10000];
	int i;
	while(gets(str)!=NULL)
	{
		int sp=0;
		int num=0;
		int ch=0;
		int oth=0;
		for (i=0;str[i]!='\0';i++)
		{
			if(str[i]>='a'&&str[i]<='z')
			ch++;
			else if(str[i]>='A'&&str[i]<='Z')
			ch++;
			else if(str[i]>='0'&&str[i]<='9')
			num++;
			else if(str[i]==' ')
				sp++;
			else oth++;
			
		}
		
		printf("%d %d %d %d\n",ch,num,sp,oth);
	}

    return 0;   
    }   
