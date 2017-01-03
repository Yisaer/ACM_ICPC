//  main.cpp
//  SHU1039
//
//  Created by 高松 on 16/1/2.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>
char ch[3] = {'B','I','F'};
char s[1005];

int merge(int l, int r){
    if(l==r){
        printf("%c",ch[s[l]-'0']);
        return s[l]-'0';
    }
    int mid=(l+r)/2;
    int x=merge(l,mid);
    int y=merge(mid+1,r);
    if(x==y){
        printf("%c",ch[x]);
        return x;
    }else{
        printf("F");
        return 2;
    }
    
    
}


int main (){
    int n;
    while(cin>>n){
        scanf("%s",s);
        merge(0,strlen(s)-1);
        cout<<endl;
    }

}
