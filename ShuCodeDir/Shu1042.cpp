//  main.cpp
//  SHU1042 校门外的树
//
//  Created by 高松 on 15/11/30.
//  Copyright © 2015年 伊萨. All rights reserved.
//

#include <iostream>
using namespace std;
#include <cstring>

int const MAX=1E5+10;
int vis[MAX];

int main(int argc, const char * argv[]) {
    int n;
    int m;
    while(cin>>n>>m)
    {
        memset(vis,1,sizeof(vis));
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            for(int j=a;j<=b;j++)
                vis[j]=0;
            
        }
        int ans=0;
        for(int i=0;i<=n;i++)
        {
            if(vis[i])
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}

