//
//  main.cpp
//  MergeSort 归并排序
//
//  Created by 高松 on 16/1/4.
//  Copyright © 2016年 yisa. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
const int Maxn = 1005;

int a[Maxn],tmp[Maxn];

void Merge(int l,int m,int r)
{
    int i = l;
    int j = m + 1;
    int k = l;
    while(i <= m && j <= r)
    {
        if(a[i] > a[j])        //进行比较
        {
            tmp[k++] = a[j++]; //大于则说明需要交换
        }
        else
        {
            tmp[k++] = a[i++]; //小于直接放入输出数组
        }
    }
    while(i <= m) tmp[k++] = a[i++]; //此时有一表已经输完，将剩余元素放入表中
    while(j <= r) tmp[k++] = a[j++];
    for(int i=l;i<=r;i++)
        a[i] = tmp[i];     //将排序好的数组放入
}

void Merge_sort(int l,int r)
{
    if(l < r)
    {
        int m = (l + r) >> 1;
        Merge_sort(l,m);
        Merge_sort(m+1,r);
        Merge(l,m,r);
    }
}

int main()
{
    int n;
    int cas=0;
    while(cin>>n)
    {
        cas++;
        for(int i=0;i<n;i++)
            cin>>a[i];
        Merge_sort(0,n-1);
        for(int i=0;i<n;i++){
           if(i) cout<<" ";
            cout<<a[i];
        }
        cout<<endl;
        
    }
    return 0;
}

