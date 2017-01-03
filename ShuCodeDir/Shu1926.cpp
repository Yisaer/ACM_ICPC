#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

#define Rep(i,n) for(int i=0;i<n;i++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define INF 0x3F3F3F3F
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define Test 	cout<<"here"<<endl;

int main ()
{
	int t;
	cin>>t;
	while(t--)
	{
		
	string s;
	cin>>s;
	int len=s.length();
	int cnt=0;
	
	for (int i=0,j=len-1;i<j&&i<len&&j>=0;)
	{
		if(s[i]!=s[j])
		{
			  if(s[i+1]==s[j])  i++;
		 else if(s[i]==s[j-1])	j--;
		 cnt++;
		}
		 else
		 {
		 i++;
		 j--;
	
		 }
		 

		
		if(cnt>=2)
		break;

	
	}
	if(cnt<2)
	cout<<"YES"<<endl;
	else 
	cout<<"NO"<<endl;	
		
		
	}
	
	
	
}
