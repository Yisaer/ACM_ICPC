#include <iostream>
using namespace std;

void test(int&a,int &b,int num,int N){
    a=0;
    b=0;
    int n1[10];
    int n2[10];
    memset(n1,0,sizeof(n1));
    memset(n2,0,sizeof(n2));
    int x=0,y=0;
    for(int i=0;i<5;i++){
        int a = num%10;
        int b = N%10;
        if(a==b)
            x++;
        n1[a]++;
        n2[b]++;
        num/=10;
        N/=10;
    }
    for(int i=0;i<10;i++){
        y+=min(n1[i],n2[i]);
    }
    a=x;
    b=y;
    
}

int main (){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int N[15];
        int x[15];
        int y[15];
        for(int i=0;i<n;i++){
            cin>>N[i]>>x[i]>>y[i];
        }
        int ans = 0;
        for(int i =0;i<=99999;i++){
            bool flag  =false;
            for(int j=0;j<n;j++){
                int a=0,b=0;
                test(a,b,i,N[j]);
                if(a!=x[j]||b!=y[j])
                {
                    flag = true;
                    break;
                }
            }
            if(!flag){
                ans++;
            }
            
        }
        cout<<ans<<endl;
    }
}

