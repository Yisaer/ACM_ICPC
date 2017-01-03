using namespace std; 
#define NMAX 500 
int main(){ 
 int a[NMAX],i,j,k,c; 
 while(cin>>a[0]){ 
 char ch;
 if(ch=getchar()=='\n')
 {
 	cout<<a[0]<<endl;
 	continue;
 }
 for(i=1;i<NMAX;i++) 
 { 
 cin>>a[i]; 
 if ( cin.get()=='\n' ) break; 
 } 
 c=i+1; 
  
 for(i=0;i<c;i++) 
 for(j=i+1;j<c;j++) 
 if(a[i]==a[j]) 
 { 
 for(k=j;k<c-1;k++)a[k]=a[k+1]; 
 c--;  
 j--;
 } 
 for(i=0;i<c-1;i++)cout<<a[i]<<" "; 
 cout<<a[c-1]<<endl; 
 } 
 return 0; 
}  
