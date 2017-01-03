#include<cstdio>
#include<cstring>
#define N 1010
using namespace std;

int d[N][N];
char a[N];

int min(int x,int y)
{
    return x<y?x:y;
}

int main()
{
    int i,j,p,n,T;
    cin>>T;
    while(T--)
    {
        scanf("%s",a+1);
        n=strlen(a+1);
        for(i=1;i<=n;i++) d[i][i]=d[i][i-1]=0;
        for(p=1;p<n;p++)
        {
            for(i=1;i<=n-p;i++)
            {
                j=i+p;
                d[i][j]=10000;
                if(a[i]==a[j]) d[i][j]=d[i+1][j-1];
                d[i][j]=min(d[i][j],d[i+1][j]+1);
                d[i][j]=min(d[i][j],d[i][j-1]+1);
            }
        }
      cout<<d[1][n]<<endl;
    }
    return 0;
}
