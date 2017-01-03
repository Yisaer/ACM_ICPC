//  main.cpp
//  SHU1668 How many Ways
//
//  Created by 高松 on 15/12/7.
//  Copyright © 2015年 伊萨. All rights reserved.
//
#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>

int main ()
{
    int n;
    while(cin>>n,n){
       if(n==1||n==2)
           cout<<"1"<<endl;
        else
            cout<<(n-1)/2<<endl;
    }


}
