//  main.cpp
//  shu1929 Yaoge的英语成绩
//
//  Created by 高松 on 15/11/27.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>
int const Maxn=105;
int S[Maxn];
int P[Maxn];
int M[Maxn][Maxn];

int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    while(T--){
        int n,p,q;
        cin>>n>>p>>q;
        memset(M,0,sizeof(M));
        memset(P,0,sizeof(P));
        memset(S,0,sizeof(S));
        for(int i=0;i<p;i++){
            int a,x;
            cin>>a>>x;
            a--;
            if(x>S[a])
            S[a]=x;
        }
        for(int i=0;i<q;i++){
            int a,b,x;
            cin>>a>>b>>x;
            a--;b--;
            if(x>M[a][b])
            M[a][b]=x;
        }
        for(int l=0;l<q;l++){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                
                int X=M[i][j];
                if(X!=0&&S[i]-S[j]<X){
                    if(P[i]<S[j]+X)
                        P[i]=S[j]+X;
                    for(int i=0;i<n;i++){
                        if(P[i]!=0)
                            S[i]=P[i];
                    }
                    
                }
                
            }
        }
        cout<<S[0]<<endl;
        
        
    }
    
    
    return 0;
}
