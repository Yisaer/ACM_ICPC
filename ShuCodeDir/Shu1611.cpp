#include <cstring>
using namespace std;


int const Maxn = 1001;
int dp[Maxn][Maxn];
int S[Maxn][Maxn];
int cntP[Maxn];
int cntN[Maxn];
int p[Maxn];

void Trace(int i,int j){
    if(i==j) return;
    Trace(i,S[i][j]);
    Trace(S[i][j]+1,j);
    cntP[i]++;
    cntN[j]++;
}


int main (){
    int n;
    int count = 0;
    while(cin>>n) {
        count++;
        memset(cntP, 0, sizeof(cntP));
        memset(cntN, 0, sizeof(cntN));
        memset(dp, 0, sizeof(dp));
        memset(S, 0, sizeof(S));
        for (int i = 0; i <= n; i++) {
            cin >> p[i];
        }
        if(n==1){
            cout<<"Case "<<count<<endl;
            cout<<0<<" "<<"A1"<<endl;
            continue;
        }
        for (int r = 2; r <= n; r++) {
            for (int i = 1; i <= n - r + 1; i++) {
                int j = i + r - 1;
                dp[i][j] = dp[i + 1][j] + p[i - 1] * p[i] * p[j];
                S[i][j] = i;
                for (int k = i + 1; k < j; k++) {
                    int t = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if (t < dp[i][j]) {
                        dp[i][j] = t;
                        S[i][j] = k;
                    }
                }
            }
        }
        cout<<"Case "<<count<<endl;
        cout << dp[1][n] <<" ";
        Trace(1, n);
        cntP[1]--;
        cntN[n]--;
        for (int i = 1; i <= n; i++) {
            while (cntP[i]) {
                cntP[i]--;
                cout << "(";
            }
            cout << "A" << i;
            while (cntN[i]) {
                cntN[i]--;
                cout << ")";
            }
        }
        cout<<endl;
    }
}
