//
//  main.cpp
//  模线性方程
//
//  Created by 高松 on 16/1/2.
//  Copyright © 2016年 yisa. All rights reserved.
//

//
//  main.cpp
//  模线性方程
//
//  Created by 高松 on 15/12/10.
//  Copyright © 2015年 伊萨. All rights reserved.
//
// 扩展欧几里德算法,解gcd(a, b) = ax + by
//扩展欧几里得算法
// 求解模线性方程 得出ax同余b mod n的整数解x
//将ans解存入ans数组中
//
#include <iostream>
using namespace std;
#include <cstdio>
int ans [99999];
int len;

int Extended_Euclid(int a,int b,int& x,int &y)
{
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int d=Extended_Euclid(b,a%b,x,y);
    int temp=x;x=y;y=temp-a/b*y;
    return d;
}

//用扩展欧几里得解模线性方程ax=b (mod n)
bool modularLinearEquation(int a,int b,int n)
{
    int x,y,x0,i;
    int d=Extended_Euclid(a,n,x,y);
    if(b%d)
        return false;
    x0=x*(b/d)%n;
    for(i=1;i<=d;i++){
        len++;
        ans[i-1]=(x0+i*(n/d))%n;
        // printf("%d\n",(x0+i*(n/d))%n);
    }
    return true;
}

int main (){
    int a,b, n; // a*x 同余 b mod n
    while(cin>>a>>b>>n){
        len=0;
        if(modularLinearEquation(a,b,n)){
            for(int i=0;i<len;i++){
                if(i)cout<<" ";
                cout<<ans[i];
            }
            cout<<endl;
        }
    }
}