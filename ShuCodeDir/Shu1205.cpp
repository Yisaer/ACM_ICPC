//  main.cpp
//  SHU1205 方砖问题
//
//  Created by 高松 on 15/12/17.
//  Copyright © 2015年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n&1){
            if(n==3){
                cout<<6<<endl;
            }else{
                
            int ans =1;
            int t= n-2;
            int num = t/2;
            int num2=num*2+1;
                int num1=n*n-(n-2)*(n-2)-num2*4;
                ans+=num2+num1;
                cout<<ans<<endl;
            }
        }
        else
            cout<<4<<endl;
        
    }
    
    
    return 0;
}

