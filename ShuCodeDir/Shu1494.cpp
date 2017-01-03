int main()
{
	
	int i,j,r,l,b,d,pl,N;
	while((scanf("%d",&N))==1)
	{
	for (i=1;i<=N;i++) 
{ for (j=1;j<=N;j++)  
{ r=i;d=0;pl=j-r; 
if (r>N-j+1) {r=N-j+1;d=1;pl=i-r;} 
if (r>N-i+1) {r=N-i+1;d=2;pl=N-j+1-r;} 
if (r>j) {r=j;d=3;pl=N-i+1-r;} 

l=N-2*(r-1)-1;
b=(4*N-4)*(r-1)-4*(r-1)*(r-2)+1; 
if(b+l*d+pl>=N&&b+l*d+pl<=2*N-1)
printf("%d",b+l*d+pl); 
else
printf("%d ",b+l*d+pl); 
} 
printf("\n"); 
}
printf("\n");
}
	return 0;
}
