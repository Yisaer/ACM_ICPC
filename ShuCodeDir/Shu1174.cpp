//  main.cpp
//  SHU1174 去掉双斜杠
//
//  Created by 高松 on 15/12/17.
//  Copyright © 2015年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstdio>
#include <cstring>
char str[100];
#define ll long long

int main(int argc, const char * argv[]) {
    while(gets(str)){
        ll len =strlen(str);
        for(int i=0;i<len;i++){
            if(str[i]=='/'&&str[i+1]=='/'){
                if(i==0){
                    goto B;
                }else{
                    goto A;
                }
            }else{
                cout<<str[i];
            }
        }
    A:cout<<endl;
    B: continue;
        
    }
  
    
    return 0;
}

