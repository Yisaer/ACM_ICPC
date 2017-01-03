int main ()
{
	int n;
	scanf("%d",&n);
	int wu,er,yi;
	int count=0;
	for(wu=1;wu<=n/5;wu++)
	for(er=1;er<=n/2;er++)
	for(yi=1;yi<=n/1;yi++)
	if(wu*5+er*2+yi*1==n)
	count++;
	printf("%d\n",count);
	
	
	
	return 0;
}
