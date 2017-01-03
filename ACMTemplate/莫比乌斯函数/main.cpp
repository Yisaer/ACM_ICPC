//
//  main.cpp
//  莫比乌斯函数
//
//  Created by 高松 on 16/1/7.
//  Copyright © 2016年 yisa. All rights reserved.
//

//输入N以后，Mu数组存放的是Mu[d]=u(d)
//cnt代表1-N之间的素数个数
//prime依次存放素数


#include <cstring>
#include <iostream>
using namespace std;
#include <cstdio>
int const Maxn = 1000+5;
int vis[Maxn];
int prime[Maxn];
int mu[Maxn];
int cnt ;
int N;


void Mobius() {          //计算d的不同素因子个数，计算μ(d)的值
    memset(vis,0,sizeof(vis));            //vis[i]记录记录i是否标记过
    mu[1] = 1; cnt = 0;
    for(int i=2; i<N; i++) {
        if(!vis[i]) {                      //如果vis[i]是第1个未标记的，那么i是素数
            prime[cnt++] = i;   mu[i] = -1;
        }
        for(int j=0; j<cnt&&i*prime[j]<N; j++) { //用筛法求素数
            vis[i*prime[j]] = 1;    //将prime[j]的倍数都标记，即筛掉
            if(i%prime[j]) mu[i*prime[j]] = -mu[i]; //若i未被筛掉，则用积性求μ
            else {
                mu[i*prime[j]] = 0; break;   //被筛掉的数都有素数的平方， μ=0
            }
        }
    }
}






int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
