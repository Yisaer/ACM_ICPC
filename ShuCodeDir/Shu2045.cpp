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
char str[65540];


int main (){
    int cas = 0;
    while(gets(str)){
        cas++;
        printf("Case %d: ",cas);
        int ans = 0;
        bool flag = true;
        for(int i=0;i<strlen(str);i++){
            if(str[i]!=' '&&flag == true){
                ans++;
                flag = false;
            }
            if(str[i]==' '&&flag == false){
                flag = true;
            }
        }
        cout<<ans<<endl;
    }
}

