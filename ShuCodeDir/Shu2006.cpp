//  main.cpp
//  QY
//
//  Created by 高松 on 16/3/28.
//  Copyright © 2016年 yisa. All rights reserved.
//
#include <iostream>
using namespace std;
#include <cstring>
#include <algorithm>
#include <string>
char key[15];
char str[105];
char S[15][105];
int Index[15];
#include <vector>

bool cmp(int a,int b){
    if(key[a]==key[b]){
        return a<b;
    }
    return (int)key[a]<(int)key[b];
}

int main (){
    
    while(true){
        memset(S,0,sizeof(S));
        memset(str,0,sizeof(str));
        memset(key,0,sizeof(key));
        cin>>key;
        if(strlen(key)==6&&
           key[0]=='T'&&key[1]=='H'&&key[2]=='E'
           &&key[3]=='E'&&key[4]=='N'&&key[5]=='D'){
            break;
        }
        cin>>str;
        int len = strlen(key);
        for(int i=0;i<len;i++)
            Index[i]=i;
        sort(Index,Index+len,cmp);
//        for(int i=0;i<len;i++){
//            if(i)cout<<" ";
//            cout<<Index[i];
//        }
        int L = strlen(str);
        int now = 0;
        int row = L/len;
        if(L%len) row++;
        int end = row;
        
        vector<string> v;
        while(end<=L){
//            cout<<string(&str[now],&str[end])<<endl;
            v.push_back(string(&str[now],&str[end]));
            now=end;
            end = now+row;
            if(now==L){
                v.push_back(string(&str[L],&str[L]));
                break;
            }
            if(end>L&&now<end){
                end=L;
                 v.push_back(string(&str[now],&str[end]));
                break;
            }
        }
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].length();j++){
                S[i][j]=v[i][j];
            }
        }
//       for(int i=0;i<v.size();i++){
//            cout<<S[i]<<endl;
//        }
        for(int j=0;j<row;j++){
            for(int i=0;i<len;i++){
                for(int k=0;k<len;k++){
                    if(Index[k]==i){
                        cout<<S[k][j];
                        break;
                    }
                }
            }
        }
        cout<<endl;
        
    }
}
