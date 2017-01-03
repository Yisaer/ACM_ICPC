//  main.cpp
//  QY
//
//  Created by 高松 on 16/3/28.
//  Copyright © 2016年 yisa. All rights reserved.
//
#include<iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int const Maxn  = 52;
int dp[Maxn][Maxn][5];

//dp[l][r][k]表示第l个到第r个点用K个矩形覆盖的最小面积
//递归公式 dp[l][r][k] = 

struct Point{
    int x,y;
    
}p[Maxn];

int n,k;

bool cmp(Point a,Point b){
    if(a.y==b.y)
        return a.x<b.x;
    return a.y<b.y;
}

int DP(int l,int r,int k){
//    cout<<"l="<<l<<" r="<<r<<" k="<<k<<endl;
    if(l>r)
        return 0;
    if(!k)
        return 1000000 ;
//    当l<=r且k=0的时候 无法使用矩形覆盖 返回极大值
    if(k==1 && dp[l][r][k]==-1 ){
        if(l==r)
        return 0;
//        当L==r且K=1时候，即为1个矩形覆盖一个点 面积为0
        int minX ,minY;
        int maxX, maxY;
        minX=minY= 10000000;
        maxX=maxY= 0;
        for(int i=l;i<=r;i++){
            minX = min(minX,p[i].x);
            maxX = max(maxX,p[i].x);
            minY = min(minY,p[i].y);
            maxY = max(maxY,p[i].y);
        }
        dp[l][r][k]= (maxX-minX)*(maxY-minY);
        return dp[l][r][k];
    }
    if( dp[l][r][k] != -1 )
        return dp[l][r][k];
    dp[l][r][k] = 100000000;
    int i , j;
    for( i = l - 1 ; i <= r ; i++ )
        for( j = 0 ; j <= k ; j++ )
            dp[l][r][k] = min( DP( l , i , j ) + DP( i + 1 , r , k - j ) , dp[l][r][k] );
    return dp[l][r][k];
    
}


int main (){
    while(cin>>n>>k){
        memset(p,0,sizeof(p));
        for(int i=1;i<=n;i++){
            cin>>p[i].x>>p[i].y;
        }
        sort(p+1,p+n+1,cmp);
        memset(dp,-1,sizeof(dp));
        
        
        
        cout<<DP(1,n,k)<<endl;
    }
}
