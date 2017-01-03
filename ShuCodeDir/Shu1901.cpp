#include <iostream>
using namespace std;
#include <queue>
char G[4][4];
int vis[4][4];
int n,m;
int SX,SY;

int Min;
struct S{
    int time;
    int x1,y1;
    int x2,y2;
    int vis1[4][4];
    int vis2[4][4];
    int par1[4][4];
    int par2[4][4];
    S(){}
    
};
int dir[4][2] = {1,0,-1,0,0,1,0,-1};

bool flag (S now){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(now.vis1[i][j]==0&&now.vis2[i][j]==0)
                return false;
        }
    }
    return true;
}



void bfs2(){
    S cur ;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            cur.vis1[i][j]=vis[i][j];
            cur.vis2[i][j]=vis[i][j];
            cur.par1[i][j]=-1;
            cur.par2[i][j]=-1;
        }
    }
    cur.x1=cur.x2=SX;
    cur.y1=cur.y2=SY;
    cur.time = 0;
    queue<S> q;
    q.push(cur);
    while(!q.empty()){
        S now = q.front();
        q.pop();
        if(flag(now)){
            Min = now.time;
            return;
        }
        int x1 = now.x1;
        int y1 = now.y1;
        int x2 = now.x2;
        int y2 = now.y2;
        int time = now.time;
        
        int cnt1 = 0;
        for(int i=0;i<4;i++){
            int tx1 = x1+dir[i][0];
            int ty1 = y1+dir[i][1];
            
            if(G[tx1][ty1]=='X'||tx1<0||tx1>=n||ty1<0||ty1>=m||now.vis1[tx1][ty1]==1)
            {
                cnt1++;
                if(cnt1==4){
                    int par1x = now.par1[x1][y1]/10;
                    int par1y = now.par1[x1][y1]%10;
                    now.vis1[par1x][par1y]=0;
                    i=-1;
                }
                continue;
            }
            int cnt2 = 0;
            for(int j=0;j<4;j++){
                int tx2 = x2+dir[j][0];
                int ty2 = y2+dir[j][1];
                if(G[tx2][ty2]=='X'||tx2<0||tx2>=n||ty2<0||ty2>=m||now.vis2[tx2][ty2]==1){
                    cnt2++;
                    if(cnt2==4){
                        int par2x = now.par2[x2][y2]/10;
                        int par2y = now.par2[x2][y2]%10;
                        now.vis2[par2x][par2y]=0;
                        j=-1;
                    }
                    continue;
                }
                
                S next;
                next.x1 = tx1;
                next.x2 = tx2;
                next.y1 = ty1;
                next.y2 = ty2;
                next.time = time+1;
                for(int i=0;i<n;i++)
                    for(int j=0;j<m;j++){
                        next.vis1[i][j]=now.vis1[i][j];
                        next.vis2[i][j]=now.vis2[i][j];
                        next.par1[i][j]=now.par1[i][j];
                        next.par2[i][j]=now.par2[i][j];
                        
                    }
                
                if(next.par1[tx1][ty1]==-1){
                    next.par1[tx1][ty1]=x1*10+y1;
                }
                if(next.par1[tx2][ty2]==-1){
                    next.par2[tx2][ty2]=x2*10+y2;
                }
                next.vis1[tx1][ty1]=1;
                next.vis2[tx2][ty2]=1;
                q.push(next);
            }
        }
    }
}


int main (){

    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        memset(vis,0,sizeof(vis));
        memset(G,0,sizeof(G));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                cin>>G[i][j];
                if(G[i][j]=='X')
                {
                    vis[i][j]=1;
                }
                if(G[i][j]=='S')
                {
                    vis[i][j]=1;
                    SX=i;
                    SY=j;
                }
             
            }
        }
        bfs2();
        cout<<Min<<endl;
    }
}
