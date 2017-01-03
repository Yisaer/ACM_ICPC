










#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
#define ll long long


ll ans;
int main ()
{

    char str[1005];
    while(cin>>str)
    {
        ll len=strlen(str);
        ll index=1;
        ans=0;
      //  cout<<"len="<<len<<endl;
        for(ll i=len-1;i>=0;i--)
        {
       //     cout<<"index="<<index<<endl;
            char x=str[i];
            if(x=='u')
                ans-=index;
            else
                if(x=='1')
                    ans+=index;
            
            index*=2;
        

        }
        cout<<ans<<endl;
        
    }


}
