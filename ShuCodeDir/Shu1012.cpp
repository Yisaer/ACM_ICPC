//  main.cpp
//  产生数
//
//  Created by 高松 on 15/12/31.
//  Copyright © 2015年 yisa. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>
#include <cstdio>
#define ll long long
int const Maxn =40;
char s[Maxn];
int  num[10];
int  G[10][10];
int ans[99999];


int main(int argc, const char * argv[]) {
    int k;
    while(cin>>s>>k){
        memset(ans,0,sizeof(ans));
        memset(G,0,sizeof(G));
        memset(num,0,sizeof(num));
        
        while(k--){
            int a,b;
            cin>>a>>b;
            G[a][b]=1;
        }
        
        for(int i=0;i<10;i++)
            G[i][i]=1;
        for(int k=0;k<10;k++)
            for(int i=0;i<10;i++){
                for(int j=0;j<10;j++){
                    G[i][j]=G[i][j]|(G[i][k]&G[k][j]);
                }
            }
        for(int i=0;i<10;i++)
            for(int j=0;j<10;j++)
                if(G[i][j]) num[i]++;
        // 高精度乘法
        int len;
        ans[1]=len=1;
        for (int i=0;i<strlen(s);++i)
        {
            int x=num[s[i]-'0'];
            for (int j=1;j<=len;++j) ans[j]*=x;
            for (int j=1;j<=len;++j)
            {
                ans[j+1]+=ans[j]/10;
                ans[j]%=10;
            }
            while (ans[len])
            {
                ans[len+1]+=ans[len]/10;
                ans[len]%=10;
                ++len;
            }
        }
        for (int i=len-1;i>0;--i) printf("%d",ans[i]);
    }
    
    
    return 0;
}
