#include <cstdio>
#include <iostream>
using namespace std;
 
int const Maxn = 105;
 
int F[Maxn];
int t[Maxn];
int dp[1005];
 
int main (){
         
    int N;
    while(cin>>N){
         
        int time;
        cin>>time;
        for(int i=0;i<N;i++){
            cin>>F[i]>>t[i];
        }
        memset(dp,0,sizeof(dp));
        for(int i=0;i<N;i++){
            for(int j=time;j>=t[i];j--){
               dp[j]=max(dp[j],dp[j-t[i]]+F[i]);
            }
        }
        cout<<dp[time]<<endl;
         
    }
     
}
