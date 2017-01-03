//
//  main.cpp
//  kmp算法
//
//  Created by 高松 on 16/1/1.
//  Copyright © 2016年 yisa. All rights reserved.
//



// KMP算法 返回模式串在目标串中第一个匹配的位置
// Demo:
//   如 str为 aaab ,而模式串opt则为aab
//   则模式串在目标串的第二个位置发现匹配
//   返回2
//   复杂度O(len1+len2）

#include <cstring>
#include <iostream>
using namespace std;
#include <cstdio>
char str[1000000+10];//目标串
char opt[10000+10];// 模式串
int Next[10000+10];
long long  len1,len2;

void getnext()
{
    len1=strlen(str);
    len2=strlen(opt);
    Next[0]=-1;
    int i=0,j=-1;
    while(i<len2)
    {
        if(j==-1 || opt[i]==opt[j])
        {
            i++;j++;
            Next[i]=j;
        }
        else
            j=Next[j];
    }
}

int kmp()
{
    int i=0,j=0;
    while(i<len1 && j<len2)
    {
        if(j==-1 || str[i]==opt[j])
        {
            i++;j++;
        }
        else
            j=Next[j];
    }
    return j==len2?i-j+1:-1;
}




int main (){


}