//
//  main.cpp
//  Manacher算法 最长回文子串
//
//  Created by 高松 on 16/1/1.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
const int MAXN=1100100;
using namespace std;
char s[MAXN]; //原字符串
char Ma[MAXN*2];// 变形字符串

int Mp[MAXN*2]; // 记录变形字符串的回文长度

int ans ;
void Manacher(char s[],long long len)
{
    int l=0;
    Ma[l++]='$';
    Ma[l++]='#';
    for(int i=0;i<len;i++)
    {
        Ma[l++]=s[i];
        Ma[l++]='#';
    }
    Ma[l]=0;
    int mx=0,id=0;
    for(int i=0;i<l;i++)
    {
        Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1;
        while(Ma[i+Mp[i]]==Ma[i-Mp[i]])
            Mp[i]++;
        if(i+Mp[i]>mx)
        {
            mx=i+Mp[i];
            id=i;
        }
    }
    //MP数组处理完
    for(int i=0;i<2*len+2;i++)
        ans=max(ans,Mp[i]-1);
    
}
int main(void)
{
    int T;
    cin>>T;
    
    while(T--)
    {
        cin>>s;
        ans=0;
        long long  len=strlen(s);
        Manacher(s,len);
        cout<<ans<<endl;
    }
    return 0;
}