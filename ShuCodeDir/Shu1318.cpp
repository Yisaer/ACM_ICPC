//  main.cpp
//  SHU1318
//
//  Created by 高松 on 15/12/9.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstdio>
int const Max = 30;
int Mem[Max][Max][Max];

int main(int argc, const char * argv[]) {
    
    for(int i=0;i<=20;i++){
        for(int j=0;j<=20;j++){
            for(int k=0;k<=20;k++){
                if(i==0||k==0||j==0)
                    Mem[i][j][k]=1;
                else
                    if(i<j&&j<k){
                        Mem[i][j][k]=Mem[i][j][k-1]+Mem[i][j-1][k-1]-Mem[i][j-1][k];
                    }
                    else {
                        Mem[i][j][k]=Mem[i-1][j][k]+Mem[i-1][j-1][k]+Mem[i-1][j][k-1]-Mem[i-1][j-1][k-1];
                    }
                
            }
            
            
        }
        
    }
    
    int a,b,c;
    while(cin>>a>>b>>c){
        if(a==-1&&b==-1&&c==-1)
            break;
        int ta=a,tb=b,tc=c;
        if(ta<=0||tb<=0||tc<=0){
            ta=0;
            tb=0;
            tc=0;
        }
        if(ta>20||tb>20||tc>20)
        {
            ta=20;tb=20;tc=20;
        }
      
        printf("w(%d, %d, %d) = %d\n",a,b,c,Mem[ta][tb][tc]);
        
    }
    
    return 0;
}
