#include <iostream>
using namespace std;
#include <algorithm>

struct X{
    int w,t,c;
    int id;
}F[105];

bool cmp(X a,X b){
    return a.t>b.t;
    
}
int dp[105][51];

int main (){
    int T;
    cin>>T;
    while(T--){
        int n,m,s;
        cin>>n>>m>>s;
        memset(F,0,sizeof(F));
        for(int i=0;i<m;i++){
            cin>>F[i].w>>F[i].t>>F[i].c;
            F[i].id = i;
        }
        
        sort(F,F+m,cmp);
        memset(dp,0x3f,sizeof(dp));
        dp[0][n]=0;
        for(int i=0;i<m;i++){
            for(int j=1;j<=min(F[i].t,n);j++){
                for(int k=0;k<=s-F[i].w;k++){
                    dp[k+F[i].w][j-1]=min(dp[k+F[i].w][j-1],dp[k][j]+F[i].c);
                }
            }
            
        }
        int ans = 0x3f3f3f3f;
        for(int i=0;i<=s;i++){
            ans = min(ans,dp[i][0]);
        }
        if(ans == 0x3f3f3f3f){
            cout<<-1<<endl;
        }
        else
            cout<<ans<<endl;
        
    }
}
