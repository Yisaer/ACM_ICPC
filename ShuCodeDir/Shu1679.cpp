//  main.cpp
//  SHU I
//
//  Created by 高松 on 15/11/25.
//  Copyright © 2015年 伊萨. All rights reserved.
//
#include<cstring>
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 510;
const int MOD = 1000007;

int C[MAXN][MAXN];
int n, m, k;
/*
 题意：在一个m*n的矩形网格里放k个相同的石子，问有多少种方法？每个格子最多放一个石子，所有石子都要放完，并且第一行、最后一行、第一列、最后一列都得有石子。
 
 思路：假设满足第一行没有石子的方案集为A，最后一行没有石子的方案集为B，第一列没有石子的方案集为C，最后一列没有石子的方案集为D，全集为S，则所求答案就是“在S中但不在A，B，C，D任何一个集合中”的元素个数，这里就是运用容斥原理。程序中可以用二进制来表示集合。
 */
void init() {
    memset(C, 0, sizeof(C));
    C[0][0] = 1;
    for (int i = 0; i < MAXN; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
}

int main() {
    init();
    int cas, t = 1;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d%d", &n, &m, &k);
        int sum = 0;
        for (int S = 0; S < 16; S++) {
            int b = 0, r = n, c = m;
            for (int i = 0; i < 4; i++) {
                if (S & (1 << i)) {
                    if (i % 2)
                        r--;
                    else
                        c--;
                    b++;
                }
            }
            if (b & 1)
                sum = (sum + MOD - C[r * c][k]) % MOD;
            else
                sum = (sum + C[r * c][k]) % MOD;
        }
        printf("%d\n", sum);
    }
    return 0;
}
