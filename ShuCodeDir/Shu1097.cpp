//  main.cpp
//  SHU1097 TOm数
//
//  Created by 高松 on 15/12/29.
//  Copyright © 2015年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>
char num [20];


int main(int argc, const char * argv[]) {
    while(cin>>num){
        int ans = 0;
        for(int i=0;i<strlen(num);i++){
            ans+=num[i]-'0';
        }
        cout<<ans<<endl;
    }
    return 0;
}
