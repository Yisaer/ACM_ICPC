#include <iostream>
using namespace std;

int const Manx = 1000;
char X[Manx];
char Y[Manx];
int dp[Manx][Manx];

int main (){

    int n;
    int count = 0;
    int T;
    cin>>T;
    while(T--){
        count++;
        memset(X,0,sizeof(X));
        memset(Y,0,sizeof(Y));
        memset(dp,0,sizeof(dp));
        int n,m;
        cin>>n>>m;
        for(int i= 1  ;i<=n;i++)
            cin>>X[i];
        for(int i = 1;i<=m;i++)
            cin>>Y[i];

        for(int i = 1;i<=n;i++){
            for(int j= 1;j<=m;j++){

                if(X[i]==Y[j]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        cout<<"Case "<<count<<endl;
        cout<<dp[n][m]<<endl;
    }
}
