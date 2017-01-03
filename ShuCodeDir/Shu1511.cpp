using namespace std;
#include <cstdio>
int F[20] =
{
    128,
    224,
    768,
    1504,
    2304,
    4752,
    13088,
    18824,
    26832,
    39096,
    51712,
    87152,
    166832,
    200224,
    256096,
    414072,
    581776,
    1031424,
    1634528,
    1952048,
};


int main (){
    int N;
    int cas = 0;
    while(cin>>N){
        if(cas)cout<<endl;
        printf("Case %d:\n",++cas);
        cout<<F[N-10]<<endl;
        
    }
}
