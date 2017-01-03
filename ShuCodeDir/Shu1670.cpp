//  main.cpp
//  SHU1670 Escape
//
//  Created by 高松 on 15/12/7.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;

double const P=3.1415926;

int main(int argc, const char * argv[]) {
    double R,v1,v2;
    while(cin>>R>>v1>>v2){
        double time1=R/v1;
        double time2=R*P/v2;
        if(time1<time2)
            cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        
        
    }
    
    
    return 0;
}
