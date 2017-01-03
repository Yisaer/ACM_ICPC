//
//  main.cpp
//  容斥原理
//
//  Created by 高松 on 16/1/3.
//  Copyright © 2016年 yisa. All rights reserved.
//
//
//  main.cpp
//  SHU1785
//
//  Created by 高松 on 16/1/3.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

long long a,b,n;
vector<long long> vt;

long long solve(long long x,long long n){
    vt.clear();
    long long i,j;
    for(i=2;i*i<=n;i++)     //对n进行素数分解
        if(n%i==0){
            vt.push_back(i);
            while(n%i==0)
                n/=i;
        }
    if(n>1)
        vt.push_back(n);
    
    long long sum=0,val,cnt;
    for(i=1;i<(1<<vt.size());i++){  //用二进制来1,0来表示第几个素因子是否被用到,如m=3，三个因子是2,3,5，则i=3时二进制是011，表示第2、3个因子被用到
        val=1;
        cnt=0;
        for(j=0;j<vt.size();j++)
            if(i&(1<<j)){       //判断第几个因子目前被用到
                val*=vt[j];
                cnt++;
            }
        if(cnt&1)       //容斥原理，奇加偶减
            sum+=x/val;
        else
            sum-=x/val;
    }
    return x-sum;
}

int main(){
    
    //freopen("input.txt","r",stdin);
    
    int t,cases=0;
    scanf("%d",&t);
    while(t--){
        cin>>a>>b>>n;
        cout<<"Case #"<<++cases<<": "<<solve(b,n)-solve(a-1,n)<<endl;
    }
    return 0;
}