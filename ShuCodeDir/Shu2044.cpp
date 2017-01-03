#include <cmath>
#include <cstring>
#include <string>
#include <climits>
#include <cstdlib>
#include <cstdio>
int G[60][60];
using namespace std;

struct X{
    int x;
    int y;
}F[3600];


int main (){
    int n;
    int cas = 0;
    while(cin>>n){
        memset(G,0,sizeof(G));
        memset(F,0,sizeof(F));
        cas++;
        printf("Case %d:",cas);
        cout<<endl;
        G[1][n/2+1]=1;
        F[1].x = 1;
        F[1].y = n/2+1;
        for(int i=2;i<=n*n;i++){
            if((i-1)%n==0){
                int prex = F[i-1].x;
                int prey = F[i-1].y;
                F[i].x = prex+1;
                F[i].y = prey;
                if(prex==n){
                    F[i].x = 1;
                }
                G[F[i].x][F[i].y] = i;
            }
            else{
                int prex = F[i-1].x;
                int prey = F[i-1].y;
                F[i].x = prex-1;
                F[i].y = prey+1;
                if(prex ==1){
                    F[i].x = n;
                }
                if(prey==n){
                    F[i].y = 1;
                }
                G[F[i].x][F[i].y] = i;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                printf("%5d",G[i][j]);
            }
            cout<<endl;
        }
    }
}

