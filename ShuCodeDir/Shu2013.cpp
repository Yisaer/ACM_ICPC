#include <iostream>
using namespace std;
#include <string>
#include <cmath>
int const Maxn = 1000005;

int p[Maxn];
int F[Maxn];
int Index[Maxn];
int Fun[Maxn];

int main (){
    F[1]=1;
    F[2]=2;
    p[1]=1;
    p[2]=2;
    for(int i=2;i<Maxn;i++){
        Fun[i]=i;
        if(!Index[i]){
            for(int j=i;j<Maxn;j+=i)
                if(!Index[j])
                Index[j] = i ;
        }
    }
    Fun[2]=4;
    int head =2;
    
    for(int i=3;i<Maxn;i++){
        int x = head;
        head = Maxn;
        while(x>1){
            
            int prim = Index[x];
            while(p[Fun[prim]]&&Fun[prim]+prim<Maxn){
                Fun[prim]+=prim;

            }
            head = min (head , Fun[prim]);
            while(x%prim==0){
                x/=prim;
            }
        }
        p[head]= i;
    }
    int x;
    while(cin>>x,x){
        cout<<"The number "<<x<<" appears in location "<<p[x]<<"."<<endl;
    }
}
