using namespace std;
#include <cstring>
#include <cstdio>
char s[10005];
bool vis[10005];
int L[30];

int main (){
    int T;
    cin>>T;
    while(T--){
        cin>>s;
        memset(L,0,sizeof(L));
        memset(vis,0,sizeof(vis));
        int pos;
        for(int i=0;i<26;i++){
            if(vis[i])continue;
            vis[i] = 1;
            pos = i;
            int len = 1;
            while(s[pos]-'A'!=i){
                len++;
                pos = s[pos]-'A';
                vis[pos] = 1;
            }
            L[len]++;
        }
        for(int i=2;i<=26;i+=2){
            if(L[i]&1) {
                cout<<"No"<<endl;
                goto A;
            }
        }
        cout<<"Yes"<<endl;
    A:
        continue;
    }
}
