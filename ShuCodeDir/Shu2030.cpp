#include <iostream>
using namespace std;
#include <cstring>
char ch[3] = {'B','I','F'};
char s[1005];

int F(int l,int r);


int main (){
    int n;
    while(cin>>n){
        cin>>s;
        int len = strlen(s);
        F(0,len-1);
        cout<<endl;
    }
    
}

int F(int l, int r){
    if(l==r){
        cout<<ch[s[l]-'0'];
        return s[l]-'0';
    }
    int mid=(l+r)/2;
    int x=F(l,mid);
    int y=F(mid+1,r);
    if(x==y){
        cout<<ch[x];
        return x;
    }else{
        cout<<"F";
        return 2;
    }
}

