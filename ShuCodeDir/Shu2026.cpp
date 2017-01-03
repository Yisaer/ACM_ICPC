using namespace std;
#define ll long long
ll n, m, k;


ll cut (ll x,ll y){
    ll a= n/(x+1);
    a = min(a,n-a*x);
    ll b= m/(y+1);
    b= min(b,m-b*y);
    return a*b;
}


ll solve(ll n,ll m){
    ll ans = 0;
    if(k<n){
        ans = max ( ans,cut(k,0));
    }
    if(k<m){
        ans = max(ans,cut(0,k));
    }
    if(k>=n&&k>=m){
        ans = max(ans,cut(n-1,k-n+1));
        ans = max(ans,cut(k-m+1,m-1));
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        if(n+m-2<k){
            cout<<-1<<endl;
            continue;
        }
        cout<<solve(n,m)<<endl;
        
    }
    return 0;
}
