//  main.cpp
//  中国剩余定理
//
//  Created by 高松 on 15/12/10.
//  Copyright © 2015年 伊萨. All rights reserved.
//
#include <iostream>
using namespace std;
#define ll long long
//参数可为负数的扩展欧几里德定理
void exOJLD(int a, int b, int &x, int &y){
    //根据欧几里德定理
    if(b == 0){//任意数与0的最大公约数为其本身。
        x = 1;
        y = 0;
    }else{
        int x1, y1;
        exOJLD(b, a%b, x1, y1);
        if(a*b < 0){//异号取反
            x = - y1;
            y = a/b*y1 - x1;
    }else{//同号
            x = y1;
        y = x1 - a/b* y1;
        }
    }
}
//剩余定理
int calSYDL(int a[], int m[], int k){
    int N[k];//这个可以删除
    int mm = 1;//最小公倍数
    int result = 0;
    for(int i = 0; i < k; i++){
        mm *= m[i];
    }
    for(int j = 0; j < k; j++){
        int L, J;
        exOJLD(mm/m[j], -m[j], L, J);
        N[j] = m[j] * J + 1;//1
    N[j] = mm/m[j] * L;//2 【注】1和2这两个值应该是相等的。
       result += N[j]*a[j];
    }
    return (result % mm + mm) % mm;//落在(0, mm)之间，这么写是为了防止result初始为负数，本例中不可能为负可以直接 写成：return result%mm;即可。
}


int main(){
 //   int a[3] = {2, 3, 2}; // 余数
 //   int m[3] = {3, 5, 7}; // 除数
    int X,Y;
    while(cin>>X>>Y){
    int a[100],m[100];
    int num=2;
    a[0]=1,a[1]=3;
    m[0]=3,m[1]=5;
    int tmp=calSYDL(a, m, num);
        int muti =1;
        for(int i=0;i<num;i++){
            muti*=m[i];
        }
        int L=muti-((X-tmp)%muti);
       // cout<<"L="<<L<<endl;
        if(L==muti){
            int Tmp=(Y-X)/muti;
          //   cout<<"Tmp="<<Tmp<<endl;
            int S=X;
           //  cout<<"S="<<S<<endl;
            int E=S+muti*Tmp;
           // cout<<"E="<<E<<endl;
            int ans = (S+E)*(Tmp+1)/2;
            cout<<ans<<endl;
        }else{
            int S=X+L;
            int M=(Y-tmp)%muti;
            int E=Y-M;
            int Tmp=(E-S)/muti+1;
            int ans = (S+E)*Tmp/2;
            cout<<ans<<endl;
            
        }
        
        
    }
    
}
