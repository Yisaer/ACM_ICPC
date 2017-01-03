using namespace std;
struct day
{
    int x;
    int y;
    int z;
}a[100];
int main()
{
    int A,B,C,n=0;
    day m;
    while(scanf("%d/%d/%d",&A,&B,&C)!=EOF)
    {
        a[n].x=A;
        a[n].y=B;
        a[n].z=C;
        n++;
    }
    for(int i=0;i<n-1;i++)
	{
        for(int j=0;j<n-1-i;j++)
		{
            if(a[j].y>a[j+1].y)
            {
				m=a[j];
				a[j]=a[j+1];
				a[j+1]=m;
			}
		}
	}
    for(int i=0;i<n-1;i++)
	{
        for(int j=0;j<n-1-i;j++)
		{
            if(a[j].x>a[j+1].x)
            {
				m=a[j];
				a[j]=a[j+1];
				a[j+1]=m;
			}
		}
	}
    for(int i=0;i<n-1;i++)
	{
        for(int j=0;j<n-1-i;j++)
		{
            if(a[j].z>a[j+1].z)
            {
				m=a[j];
				a[j]=a[j+1];
				a[j+1]=m;
			}
		}
	}
    for(int i=0;i<n;i++)
	{
		if(a[i].x>9)
			cout<<a[i].x<<'/';
		else
			cout<<'0'<<a[i].x<<'/';
		if(a[i].y>9)
			cout<<a[i].y<<'/';
		else
			cout<<'0'<<a[i].y<<'/';
		cout<<a[i].z<<endl;
	}
}

