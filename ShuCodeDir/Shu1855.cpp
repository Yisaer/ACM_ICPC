//  main.cpp
//  kmp
//
//  Created by 高松 on 15/11/25.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
char str1[500000];
char str2[500000];
int Next[500000];

void getNext(string a)
{
    int i = 0;int j = -1;
    Next[0] = -1;
    while(i<a.length()){
        if(j == -1||a[i] == a[j])
        {
            i++;j++;
            Next[i] = j;
        }
        else
            j = Next[j];
    }
}//next数组
int kmp(char* T,char* S)
{
    int ans = 0;
    int j=0;
    int len1=strlen(S);
    int len2=strlen(T);
    if(len1 == 1 && len2 == 1)
    {
        if(S[0] == T[0])
            return 1;
        else
            return 0;
    }//数组都长度为1时
    getNext(T);
    for(int i = 0; i < len1; i++)
    {
        while(j > 0 && S[i] != T[j])
            j = Next[j];
        
        if(S[i] == T[j])
            j++;
        //搜索相同字符项
        ans = max(ans,j);
        if(j == len2)
            break;
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    while(scanf("%s",str1)!=EOF){
        scanf("%s",str2);
        int ans=kmp(str2,str1);
        cout<<ans<<endl;
        char q=getchar();
        
        
    }
    return 0;
}
