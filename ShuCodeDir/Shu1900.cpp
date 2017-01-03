#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
#define ll long long
#define max(a,b) (a>b?a:b)
int n,m,s,e;
int u,v,a,b;
vector<ll> Par[120][120];
int Gu[150][150];
int Shi[150][150];

int Cost(int x,int y){
    int Ans=0;
    if(Par[x][y].empty())
        return Shi[x][y];
    for(int i = 0;i<Par[x][y].size();i++){
        ll ans = Par[x][y][i];
        Ans= max(Shi[x][y],Cost(ans,y)+Cost(x,ans));
    }
    return Ans;
}
void spfa()
{
    for (int k =0 ; k< n; k++)
    {
        for (int i = 0; i< n; i++){
            for (int j = 0; j< n; j++)
                if (Gu[i][j] > Gu[i][k] + Gu[k][j])
                {
                    Gu[i][j] = Gu[i][k]+Gu[k][j];
                    Par[i][j].clear();
                    Par[i][j].push_back(k);
                }
            
            
                else if (Gu[i][j] == Gu[i][k] + Gu[k][j] && k!= i &&k !=j)
                {
                    Par[i][j].push_back(k);
                }
            
        }
        
    }
    
}
int main(){
    int T;
    cin>>T;
    while(T--){
        
    
        cin>>n>>m>>s>>e;
        for(int i = 0;i<120;i++)
            for(int j = 0;j<120;j++)
                Par[i][j].clear();
     
        
        for(int i = 0;i<n;i++)
            for(int j = 0;j<n;j++)
            {
                Gu[i][j] = 2000;
                if(i==j)
                    Gu[i][j]=0;
            }
        for(int i = 0;i<m;i++){
            cin>>u>>v>>a>>b;
            u--;v--;
            Gu[u][v] = a;
            Gu[v][u] = a;
            Shi[u][v] = b;
            Shi[v][u] = b;
        }
        spfa();
        printf("%d %d\n",Gu[s-1][e-1],Cost(s-1,e-1));
        
        
        
        
    }
}
