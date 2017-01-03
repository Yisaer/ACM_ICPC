//  main.cpp
//  SHU1038 花生采摘
//
//  Created by 高松 on 15/11/30.
//  Copyright © 2015年 伊萨. All rights reserved.
//
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int peanuts[25][25];

int main(){
    int row, col;
    int time;
   
    while(cin>>row>>col>>time){
    int i,j;
    int curPi = 0, curPj;
    int timeUsed = 0;
    int peaGot = 0;
    for(i = 1; i <= row; i++){
        for(j = 1; j <= col; j++){
            cin>>peanuts[i][j];
        }
    }
    int maxPi = 0, maxPj = 0;
    while(timeUsed <= time){
        int max = 0;
        for(i = 1; i <= row; i++){
            for(j = 1; j <= col; j++){
                if(peanuts[i][j] > max){
                    max = peanuts[i][j];
                    maxPi = i;
                    maxPj = j;
                }
            }
            
        }
        if(max == 0)
            break;
        if(curPi == 0)
            curPj = maxPj;
        if(timeUsed + (abs(maxPj - curPj) + abs(maxPi - curPi) + 1 + maxPi) <= time){
            timeUsed += abs(maxPj - curPj) + abs(maxPi - curPi) + 1;
            curPi = maxPi;
            curPj = maxPj;
            peaGot += peanuts[curPi][curPj];
            peanuts[curPi][curPj] = 0;
        }
        else
            break;
    }
    cout<<peaGot<<endl;
}
    return 0;
    
}
