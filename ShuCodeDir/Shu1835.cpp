#include<stdio.h>
#include <string.h>
using namespace std;
int main()
{
	
		int n,m;
		while(cin>>n){
		int ans[125];
		memset(ans,0,sizeof(ans));
		ans[0]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i<=j)
				ans[j]=ans[j]+ans[j-i];
		cout<<ans[n]<<endl;
	}
}  
