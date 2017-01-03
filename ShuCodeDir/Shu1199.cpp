//  main.cpp
//  SHU1199 数列有序
//
//  Created by 高松 on 15/12/17.
//  Copyright © 2015年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
int a [105];
#include <algorithm>

int main (){
    int n;
    int m;
    while(cin>>n>>m,n&&m){
        for(int i =0;i<n;i++){
            cin>>a[i];
        }
        a[n]=m;
        sort(a,a+n+1);
        for(int i=0;i<n+1;i++){
            if(i)
                cout<<" ";
            cout<<a[i];
        }cout<<endl;
        
        
    }
    
    
}

