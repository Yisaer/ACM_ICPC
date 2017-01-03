char str[1010];
int main ()
{
 int n;
 scanf("%d",&n);
 int top=1;
 while(top<=n)
 {
 
 scanf("%s",str);
 int i;
 for(i=0;str[i]!='\0';i++);
 i--;
 for(;i>=0;i--)
 {
  printf("%c",str[i]);	
 	
 }
 printf("\n");
 
 top++;
}
 

return 0;	
}

