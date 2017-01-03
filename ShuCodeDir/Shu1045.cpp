int main()
{
	int n,i,j,count,k,t;
	int a[100];
	scanf("%d",&n);
	count=n;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<count-1;i++){
		for(j=i+1;j<count;j++){
			if(a[i]==a[j]){
				for(k=j;k<count-1;k++)
					a[k]=a[k+1];
					count--;
					j--;
			}
		}
	}
	/*printf("%d\n",count);
	for(i=0;i<count;i++)
	printf("%d ",a[i]);*/
	for(i=1;i<count;i++)
		for(j=0;j<count-i;j++)
			if(a[j]>a[j+1]){
				t=a[j];a[j]=a[j+1];a[j+1]=t;
			}
	printf("%d\n",count);
	for(i=0;i<count-1;i++)
	printf("%d ",a[i]);
	printf("%d",a[count-1]);
	return 0;
}
