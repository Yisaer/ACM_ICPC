//  main.cpp
//  SHU1178 哥德巴赫曾猜测
//
//  Created by 高松 on 15/12/7.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cmath>
#include <cstdio>

int su [32767];
int len;
bool Isprime(int n){
    if(n==1)
        return false;
    if(n==2)
        return true;
    for(int i=2;i<=sqrt(n);i++){
       if(n%i==0)
           return false;
    }
    return true;
}


int Maxindex(int n){
    int r=len;
    int l=1;
    int ans;
    while(l<=r){
        
        int mid=(l+r)/2;
        if(n>su[mid]&&n<=su[mid+1]){
            ans=mid;
            break;
        }
        else{
            if(n>su[mid]){
                l=mid;
            }else
                r=mid;
            
        }
    }
    return ans;
    
}


int main(int argc, const char * argv[]) {
    
    int index=1;
    for(int i=2;i<=32767;i++){
        if(Isprime(i)){
            su[index++]=i;
        }
    }
    len=index-1;
    /*
    for(int i=1;i<=100;i++){
        if(i-1)
            cout<<" ";
        cout<<su[i];
        if(i%10==0)
            cout<<endl;
    }
    cout<<endl;
    */
    int n;
    while(cin>>n){
        
        int e=Maxindex(n);
        int cnt=0;
        for(int s=1;s<=e;){
            if(su[s]+su[e]==n){
                cnt++;
                s++;
                e--;
            }else{
                if(su[s]+su[e]>n){
                    e--;
                    
                }else{
                    s++;
                }

            }
            
        }
        cout<<cnt<<endl;
    }
    
    
    return 0;
}
