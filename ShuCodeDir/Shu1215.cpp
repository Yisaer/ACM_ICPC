int fact(int);
int main ()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",fact(n));
	
	return 0;
}
int fact(int n)
{
	int x;
	if(n>=1&&n<=3)
	x=1;
	else 
	x=fact(n-1)+fact(n-3);
	
	return x;
}
