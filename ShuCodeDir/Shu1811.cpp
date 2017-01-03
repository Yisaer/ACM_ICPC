#include <string.h>
#include <stdio.h>
#ifndef _SHUOJ_J_
#define _SHUOJ_J_

using namespace std;
const int N = 1005;

int a[N],tmp[N];
int ans;

void Merge(int l,int m,int r)
{
    int i = l;
    int j = m + 1;
    int k = l;
    while(i <= m && j <= r)
    {
        if(a[i] > a[j])
        {
            tmp[k++] = a[j++];
            ans += m - i + 1;
        }
        else
        {
            tmp[k++] = a[i++];
        }
    }
    while(i <= m) tmp[k++] = a[i++];
    while(j <= r) tmp[k++] = a[j++];
    for(int i=l;i<=r;i++)
        a[i] = tmp[i];
}

void Merge_sort(int l,int r)
{
    if(l < r)
    {
        int m = (l + r) >> 1;
        Merge_sort(l,m);
        Merge_sort(m+1,r);
        Merge(l,m,r);
    }
}

int main()
{
    int n,tt=1;
 	int cas=0;
    while(cin>>n)
    {
    	cas++;
        for(int i=0;i<n;i++)
         cin>>a[i];
        ans = 0;
        Merge_sort(0,n-1);
        printf("Case %d:\n",cas);
        cout<<ans<<endl;
    }
    return 0;
}




#endif  //SHUOJ_J_
