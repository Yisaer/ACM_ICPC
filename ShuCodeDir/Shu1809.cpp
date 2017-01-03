#include <cstring>
#include <cstdio>
#include <math.h>
using namespace std;
#define ll long long

int n;
int k;
const int MAXN=10+2;

ll Arr[MAXN][MAXN];
ll Ans[MAXN][MAXN];
ll T_Ans[MAXN][MAXN];

int main ()
{

	while(cin>>n>>k)
	{
		int cas=0;
		cas++;
		memset(Arr,0,sizeof(Arr));
		memset(Ans,0,sizeof(Ans));
		memset(T_Ans,0,sizeof(T_Ans));
		for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{ 
		cin>>Arr[i][j];
		Ans[i][j]=Arr[i][j]; 
		} 
		
	
		for(int q=0;q<k-1;++q){
 
    for(int i=0;i<n;++i){
        long long s=0;
        for(int j=0;j<n;++j){
            s=0;
            for(int k=0;k<n;++k){
                s+=Ans[i][k]*Arr[k][j];
                 
                 
                 
            }
            T_Ans[i][j]=s;
             
             
        }
    }
for(int i=0;i<n;++i){
            for(int j=0;j<n;++j)Ans[i][j]=T_Ans[i][j];
        }
 
}
		for(int i=0;i<n;++i){
    for(int j=0;j<n;++j){
        if(j<n-1)cout<<Ans[i][j]<<' ';
        else cout<<Ans[i][j];
    }
    cout<<endl;
}
     
cout<<endl;
	
	
	}

	
	return 0;
}
