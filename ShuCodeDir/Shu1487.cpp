#include 	<string.h>
char str[1010];
int palindrome(char*,int  );
int main 	()
{
 	int n;
 	scanf("%d",&n);
	int top;
	for(top=1;top<=n;top++)
	{
 	 scanf("%s",str);
	int i;
	int k;
	for(i=0;str[i]!='\0';i++);
	i--;
	k=palindrome(str,i);
	if(k==1)
	printf("YES!\n");
	else	
	printf("NO!\n");
	
	}
	
	
	
	return 0;
}
int palindrome(char*s,int m)
{
	int j=m;
	//printf("%d\n",j);
	int i;
	int k;
	for(i=0;i<j;i++,j--)
	{
	
		if(*(s+i)!=*(s+j))
		break;
		
	}
	//printf("i=%d j=%d\n",i,j); 
	if(i>=j)
	k=1;
	else
	k=0;
	return k;
	
}
