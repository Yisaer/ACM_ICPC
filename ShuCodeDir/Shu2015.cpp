#include <iostream>
using namespace std;


int main (){
    int t,n;
    
    while(cin>>t>>n){
        int v[105];
        int w[105];

        int dp[t+1];
        for(int i=0;i<n;i++){
            cin>>w[i]>>v[i];
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=t;j>=w[i];j--){
                dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
            }
        }
        cout<<dp[t]<<endl;
        
    }
    
}

