#include <cmath>
#include <cstring>
#include <string>
#include <climits>
using namespace std;

int main (){
    int n;
    int cas = 0;
    while(cin>>n){
        cas++;
        printf("Case %d: ",cas);
        cout<<n<<", ";
        int tmp = n;
        for(int i=0;i<4;i++){
            if(INT_MAX/n>tmp){
                tmp = tmp *n;
                
                if(i)
                    cout<<", ";
                cout<<tmp;
            }
            else
                break;
        }
        cout<<endl;
    }
}

