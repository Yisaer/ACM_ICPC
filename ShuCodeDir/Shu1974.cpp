#include<algorithm>
#include<cstring>
using namespace std;
#define see(a) cout<<#a<<a<<endl;
 
bool cmp(int a,int b)
{
    return a>b;
}
 
int main()
{
    int n,k;
    while(cin>>n>>k)
    {
        int p[1010],pr[1010];
        for(int i=0;i<n;i++)
            cin>>p[i];
        sort(p,p+n,cmp);
        memcpy(pr,p,sizeof(p));
        int y=unique(p,p+n)-p;
        //see(y);for(int i=0;i<y;i++)see(p[i]);
        int num=min(k,n);
        int price=pr[num-1];
        int w=lower_bound(p,p+y,price,cmp)-p;
        int maxn=price*num;
        int maxp=price;
        while(w>0)
        {
            w--;
            price=p[w];
            num=upper_bound(pr,pr+n,price,cmp)-pr;
            if (maxn<price*num)
            {
                maxn=price*num;
                maxp=price;
            }
        }
        cout<<maxp<<' '<<maxn<<endl;
    }
    return 0;
}
