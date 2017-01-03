#include <iostream>
using namespace std;
#include <cstdio>
#include <algorithm>
#define ll long long

ll gcd(ll a,ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}

int main (){
    
    int T;
    cin>>T;
    while(T--){
        ll n,m;
        cin>>n>>m;
        cout<<lcm(n,m)/m<<endl;
        
        
    }
    
}

