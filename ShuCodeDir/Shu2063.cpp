using namespace std;
#include <cstring>
int sum[1005];
int c[1005];
int const mod = 1000000007;
#define ll long long
ll fac[1000005];

#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)

void qfac(int n,int k){
    fac[1] = 1;
    REP2(i,2,n)
    fac[i] = fac[i-1]*i%k;
}
ll fast_mod(ll n,int m,int k){
    ll ans = 1;
    while(m){
        if(m&1) ans = ans*n%k;
        m>>=1;
        n = n*n%k;
    }
    return ans;
}
ll inv(ll n,int k){
    ll ans = fast_mod(n,k-2,k);
    return ans;
}


int main (){
    int k;
    while(cin>>k){
        
        memset(c,0,sizeof(c));
        memset(sum,0,sizeof(sum));
        
        for(int i=0;i<k;i++){
            cin>>c[i];
        }
        long long ans =1;
        sum[0] = 0;
        for(int i=1;i<k;i++){
            sum[i] = (sum[i-1]+ c[i-1]);
        }
        
        for(int i=1;i<k;i++){
            ll Max = sum[i]+c[i]-1;
            ll Min = c[i]-1;
            if(Min==0){
                continue;
            }
            
            memset(fac,0,sizeof(fac));
            qfac(Max,mod);
            ans = (ans* (fac[Max]*inv(fac[Min],mod)%mod*inv(fac[Max-Min],mod)%mod) )% mod;
        }
        
        cout<<(ans%mod)<<endl;
        
    }
}

