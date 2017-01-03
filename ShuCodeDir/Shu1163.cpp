//  main.cpp
//  SHU1163 众数
//
//  Created by 高松 on 15/12/19.
//  Copyright © 2015年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <map>


int main(int argc, const char * argv[]) {
    int n;
    while(cin>>n){
        map<int,int>cnt;
        while(n--){
            int val;
            cin>>val;
            cnt[val]++;
        }
        map<int,int>::iterator it;
        int ans=0,Max= 0;
        for(it=cnt.begin();it!=cnt.end();it++){
            if(it->second>Max){
                Max=it->second;
                ans=it->first;
            }
            
        }
        cout<<ans<<endl;
        cout<<Max<<endl;
    }
    return 0;
}
