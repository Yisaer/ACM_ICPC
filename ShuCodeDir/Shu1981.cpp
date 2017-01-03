//  main.cpp
//  SHU1981
//
//  Created by 高松 on 15/12/16.
//  Copyright © 2015年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#define ll long long
#include <cstdio>


int main(int argc, const char * argv[]) {
    int T;
    scanf("%d",&T);
    while(T--){
        ll n ,m;
        scanf("%lld%lld",&n,&m);
        ll N=n/m;
        ll L=n%m;
        ll ans = 0;
        if((m-1)%2==0){  // 1 2 3 4 5 6
            if(L>=(m-1)/2){
                ans+=N*(N-1)/2;//+ Yu 0
                ll t = (m-1)-L;
                ans+=t*N*(N+1);//
                ans+=(m-1-2*t)/2*(N+1)*(N+1);
            }else if(L==0){
                ans=(N-1)*N/2+(m-1)/2*N*N;
            }else {
                        //1 2 3 4 5 6
                ans+=N*(N-1)/2;//+ Yu 0
                ans+=L*(N+1)*N;
                ll t=(m-1)/2-L;
                ans+=t*N*N;
            }
        }else{  // 1 2 3 4 5 6 7 L=5
            if(L>(m-1)/2){
                ll t= m-1-L;  // t = 7-5=2
                ans+=N*(N-1)/2;
                ans+=t*N*(N+1);
                ll t2=(L-t)/2; // 5-2= 3 /2 =1
                ans+=t2*(N+1)*(N+1)+(N+1)*N/2;
            }
            else if(L==0){
                ans+=N*(N-1)+(m-2)/2*N*N;
            }else{ // 1 2 3 4 5 6 7  L = 3
                ans+=N*(N-1)/2;
                ans+=L*N*(N+1);
                ll t= (m-1)/2-L;
                ans+=t*N*N;
                ans+=N*(N-1)/2;
            }
            
        }
        
        printf("%lld\n",ans);
    }
    
}

