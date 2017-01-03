#include <cstdio>
#include <cstring>
using namespace std;

int n,m;
const int MAXN=110;

int Arr[MAXN][MAXN];
int T_Arr[MAXN][MAXN];


int main ()
{
	while(cin>>n>>m)
	{
		memset(Arr,0,sizeof(Arr));
		memset(T_Arr,0,sizeof(T_Arr));
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		cin>>Arr[i][j];
		
		for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
		{
			T_Arr[i][j]=Arr[j][i];	
		}
		for(int i=0;i<m;i++)
		{
		for(int j=0;j<n;j++)
		{
			if(j)
			cout<<" ";
			cout<<T_Arr[i][j];
		}
		cout<<endl;
		}
		cout<<endl;
	}
	
	return 0;
}
