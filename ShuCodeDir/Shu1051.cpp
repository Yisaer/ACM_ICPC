int m,s,t,i,f[300001]; 
using namespace std;
int main()
{
    cin>>m>>s>>t; 
    for(i=1;i<=t;i++)
    {
        if(m>=10)
        {
          f[i]=f[i-1]+60; 
          m-=10; 
        }
        else
        {
          f[i]=f[i-1]; 
          m+=4; 
        } 
    } 
  for(i=1;i<=t;i++)
    {
      if(f[i]<f[i-1]+17)f[i]=f[i-1]+17; 
      if(f[i]>=s)
        {
          cout<<"Yes"<<endl; 
          cout<<i<<endl; 
          return 0; 
        } 
    } 
  cout<<"No"<<endl; 
  cout<<f[t]<<endl; 
  return 0;
}
