//  main.cpp
//  SHU1546
//
//  Created by 高松 on 16/1/7.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    int n;
    while(cin>>n){
        if(n<10)
        {
            cout<<0<<endl;
            continue;
        }
        int ans = 0;
        for(int i=0;i<=n/100;i++){
            int tmp = 0;
            int now = n-i*100;
            for(int j=0;j<=now/50;j++){
                int cur=now-j*50;
                tmp+=(cur/20+1);
            }
            ans+=tmp;
        }
        cout<<ans<<endl;
        
    }

    return 0;
}

