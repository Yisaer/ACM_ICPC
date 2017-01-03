using namespace std;
int main()
{
	int m,n;
	int cnt=0;
	while (cin>>m>>n && m!=0)
	{
		int cnt1=0,cnt2=0;
		int b,s;
		if(cnt) cout << endl;
		printf("Case %d:\n",++cnt);
		while(cin>>b>>s && b!=-1)
		{
			if(b==0)
			{
				if (cnt2 <m-n) printf("No Smoking: %d\n",++cnt2);
					else printf("Next flight leaves 6 hours\n");
			}
			else {
				if(cnt1<n)	printf("Smoking: %d\n",++cnt1);
				else if(cnt2<m-n&&s==0) printf("No Smoking: %d\n",++cnt2);
				else printf("Next flight leaves 6 hours\n");
				
				
			}
			
			
		}
		
		
		
		
	}
	
	
	
	
	return 0;
}
