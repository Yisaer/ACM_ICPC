using namespace std;
#include <string>
#include <cstdio>
#include <queue>

int x1,x2,y1,y2;
struct X{
    int x;
    int y;
    int step;
};
int Ans ;

int dir[8][2] = { {1,2},{-1,2},{1,-2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};

bool IsLegal(int x,int y){
    if(x <1 || x>8 || y<1 ||y > 8){
        return false;
    }
    return true;
}

void bfs(){

    X ini;
    ini.x = x1;
    ini.y = y1;
    ini.step = 0;
    queue<X> q;
    q.push(ini);
    while(!q.empty()){
        X cur = q.front();
        q.pop();
        if(cur.x == x2 && cur.y == y2){
            Ans = cur.step;
            return;
        }
        for(int i =0;i<8;i++){
            int tx = cur.x+dir[i][0];
            int ty = cur.y+dir[i][1];
            if(IsLegal(tx,ty)){
                X next ;
                next.x = tx;
                next.y = ty;
                next.step = cur.step+1;
                q.push(next);
            }
        }
    }
}

#define debug(a)    cout<<#a<<"= "<<a<<endl
int main (){

    char str[10];
    while(gets(str)){

        x1 = str[0] - 'a'+1;
        y1 = str[1] - '0';
        x2 = str[3] - 'a'+1;
        y2 = str[4] - '0';
//        debug(x1);
//        debug(y1);
//        debug(x2);
//        debug(y2);
        bfs();
        cout<<str[0]<<str[1]<<"==>"<<str[3]<<str[4]<<": "<<Ans<<" moves"<<endl;


    }
}
