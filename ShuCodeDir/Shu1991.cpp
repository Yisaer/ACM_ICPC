//  main.cpp
//  计算思维测试2
//
//  Created by 高松 on 16/2/22.
//  Copyright © 2016年 yisa. All rights reserved.
//
#include <cstring>
#include <iostream>
using namespace std;
#define ll long long
int const Maxn = 15;
int s[Maxn];

int hadnext(int x){
    for(int i=x-1;i>=0;i--){
        if(s[i]>0)
            return 1;
        if(s[i]<0)
            return -1;
            
    }
    
    return 0;
}
int main ()
{
    while(cin>>s[8]){
        for(int i=7;i>=0;i--)
            cin>>s[i];
        bool allzero =true;
        for(int i=8;i>=1;i--){
            if(s[i]!=0){
                allzero =false;
                break;
            }
        }
        if(allzero ==true){
            cout<<s[0]<<endl;
            continue;
        }
        bool flag = true;
        for(int i=8;i>=2;i--){
            if(s[i]==0){
                continue;
            }
            if(flag){
                if(s[i]==1){
                    cout<<"x^"<<i;
                }
                else if(s[i]==-1){
                    cout<<"-x^"<<i;
                }
                else{
                    cout<<s[i]<<"x^"<<i;
                }
                flag  =false;
            }
            else{
                s[i]=s[i]>0?s[i]:-s[i];
                if(s[i]==1){
                    cout<<"x^"<<i;
                }
                else{
                    cout<<s[i]<<"x^"<<i;
                }
                
            }
            if(hadnext(i)==1){
                cout<<" + ";
            }
            else if(hadnext(i)==-1)
                cout<<" - ";
            else
            {
                cout<<endl;
                break;
            }
            
        }
        if(s[1]!=0){
            if(flag){
                if(s[1]==1){
                    cout<<"x";
                }
                else if(s[1]==-1){
                    cout<<"-x";
                }
                else{
                    cout<<s[1]<<"x";
                }
                flag  =false;
            }
            else{
                s[1]=s[1]>0?s[1]:-s[1];
                if(s[1]==1){
                    cout<<"x";
                }
                else{
                    cout<<s[1]<<"x";
                }
                
            }
            if(s[0]>0){
                cout<<" + ";
            }
            else if(s[0]<0){
                cout<<" - ";
            }
            else
            {
                cout<<endl;
                continue;
            }
        }
        if(s[0]!=0){
            if(flag)
            cout<<s[0]<<endl;
            else{
                s[0]=s[0]>0?s[0]:-s[0];
                cout<<s[0]<<endl;
            }
        }
        
        
        
        
    }
    
    
}

