using namespace std;
#define ll long long
#include <cmath>
#include <algorithm>
int const MaxTime = 100010;

int F[1005];
ll B,N;

ll cnt(ll time){
    ll res = 0;
    for(int i=0;i<B;i++){
        res+=(time+F[i]-1)/F[i];
    }
    return res;
}


int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>B>>N;
        for(int i=0;i<B;i++){
            cin>>F[i];
        }
        ll l = 0;
        ll r = (N)*MaxTime;
        ll mid;
        ll need;
        while(l<=r){
            mid = (l+r)/2;
            if(cnt(mid)<N&&cnt(mid+1)>=N)
            {
                need= mid;
                break;
            }
            else if(cnt(mid)<N){
                l=mid+1;
            }
            else
                r= mid-1;
        }
        
        ll now = need;
        ll per = cnt(need);
        for(int i=0;i<B;i++){
            if(now%F[i]==0){
                per++;
                if(per==N){
                    cout<<i+1<<endl;
                    break;
                }
            }
        }
    }
}

