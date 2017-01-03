//  main.cpp
//  SHU1036 蛇形矩阵
//
//  Created by 高松 on 15/11/27.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#define ll long long

int M[105][105];
int Help[105][105];


int main(int argc, const char * argv[]) {
   
    for(int i=1;i<=100;i++)
        for(int j=1;j<=100;j++)
        {
            Help[i][j]=i+j-2;
        }
    
    for(int i=1;i<=100;i++)
        Help[1][i]=i;
    
  /*
     for(int i=1;i<=5;i++)
     {
        int index=1;
        for(int j=1;j<=5-i+1;j++)
        {
            if(index-1)
                cout<<" ";
            cout<<Help[i][index++];
     
        }
        cout<<endl;
     }
     
     
    */
    
    
    for(int i=1;i<=100;i++)
        for(int j=1;j<=100;j++)
        {
            if(i==1&&j==1)
            {
                M[1][1]=1;
                continue;
            }
            if(i==1||j==1)
            {
                if(i==1)
                {
                    M[i][j]=M[i][j-1]+Help[i][j];
                    
                }
                else
                {
                    M[i][j]=M[i-1][j]+Help[i][j];
                }
                
            }
            else
            {
                M[i][j]=M[i-1][j]+Help[i][j];
                
            }
            
        }
    //M Array
    int n;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            int index=1;
            for(int j=1;j<=n-i+1;j++)
            {
                if(index-1)
                    cout<<" ";
                cout<<M[i][index++];
                
            }
            cout<<endl;
            
        }
        
    }
}
/*
1 2 3 4 5
1 2 3 4
2 3 4
3 4
4


*/
