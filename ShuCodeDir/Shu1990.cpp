//  main.cpp
//  计算思维测试2
//
//  Created by 高松 on 16/2/22.
//  Copyright © 2016年 yisa. All rights reserved.
//
#include <cstring>
#include <iostream>
using namespace std;
#define ll long long
int const Maxn = 15;
char s[Maxn];
int main ()
{
    int T;
    cin>>T;
    char ans [Maxn];
    while(T--){
        memset(s,0,sizeof(s));
        memset(ans,0,sizeof(ans));
        cin>>s;
        int j = 0;
        for(int i=0;i<8;i++){
            if(i==4){
                ans[j]='-';
                j++;
            }
            if((s[i]>='a'&&s[i]<='c')||(s[i]>='A'&&s[i]<='C')||s[i]=='2')
                ans[j]='2';
            if((s[i]>='d'&&s[i]<='f')||(s[i]>='D'&&s[i]<='F')||s[i]=='3')
                ans[j]='3';
            if((s[i]>='G'&&s[i]<='I')||(s[i]>='g'&&s[i]<='i')||s[i]=='4')
                ans[j]='4';
            if((s[i]>='J'&&s[i]<='L')||(s[i]>='j'&&s[i]<='l')||s[i]=='5')
                ans[j]='5';
            if((s[i]>='M'&&s[i]<='O')||(s[i]>='m'&&s[i]<='o')||(s[i]=='6'))
                ans[j]='6';
            if((s[i]>='p'&&s[i]<='s')||(s[i]>='P'&&s[i]<='S')||s[i]=='7')
                ans[j]='7';
            if((s[i]>='t'&&s[i]<='v')||(s[i]>='T'&&s[i]<='V')||s[i]=='8')
                ans[j]='8';
            if((s[i]>='w'&&s[i]<='z')||(s[i]>='W'&&s[i]<='Z')||s[i]=='9')
                ans[j]='9';
            if(s[i]=='0')
                ans[j]='0';
            if(s[i]=='1')
                ans[j]='1';
            j++;
        }
        cout<<ans<<endl;
        
    }
    
    
    
}
