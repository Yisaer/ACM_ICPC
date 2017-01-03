#include <cstring>
#include <algorithm>
using namespace std;

int N[10005],n;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    while(cin>>n){
        int ans = 0;
        for(int i=0;i<n;i++)
            scanf("%d",&N[i]);
        sort(N,N+n);
        while(1)
        {
            if(n==1)
                break;
            N[1]+= N[0];
            int x= N[1];
            ans += N[1];
            int i=2;
            while(N[1]>N[i]&&i<n)
                i++;
            for(int j=2;j<i;j++)
            {
                N[j-2]=N[j];
            }
            N[i-2]=x;
            for (int j=i-1;j<n;j++)
                N[j]=N[j+1];
            n--;
        }
        
        cout<<ans<<endl;
    }
}
